#pragma once

// Helper function to compute/deduce the used_size of an object.
// An object of type T may provide a computation by either
// implementing a member function size_impl(memory::record &) const
// or a free function size_impl(const T&, memory::record &)

#include <memory>
#include <variant>
#include <unordered_set>

// --------------------

template <typename T>
size_t memory_size(const T& t);

// details

namespace memory
{


  // records if an object is already counted (shared pointers...)
  struct record
  {
    bool not_counted(const void* address)
    {
      if (! _already_counted.contains(address))
      {
        _already_counted.insert(address);
        return true;
      }
      return false;
    }
   private:
    std::unordered_set<const void*> _already_counted;
  };

  // reference for concept check
  inline record& fake_count()
  {
    static record res;
    return res;
  }

  // unordered_maps are huge
  template <typename T>
  concept has_bucket_count = requires(T a) { a.bucket_count(); };

  template <typename T>
  concept is_unordered_map = has_bucket_count<T> && requires(T a) { typename T::value_type; };

  // smart pointers will need inspection
  template <typename T>
  concept is_smart_ptr = requires(T a) { a.reset(); };

  // variant will need visitation
  template <typename T>
  concept is_variant = requires(T a) { a.valueless_by_exception(); };

  // iterables will need iteration
  template <typename T>
  concept is_iterable = requires(T a) { a.begin(); };

  template <typename T>
  concept is_not_iterable = !
  is_iterable<T>;

  // type has internal helper for used_size
  template <typename T>
  concept has_internal_impl = requires(T a) { a.size_impl(fake_count()); };

  // type has external helper for used_size
  template <typename T>
  concept has_external_impl = requires(const T& a) { size_impl(a, fake_count()); };

  // type has a used size (std::vector...)
  template <typename T>
  concept has_size = requires(T a) { a.size(); };

  template <typename T>
  concept has_size_and_internal_impl = has_size<T> && has_internal_impl<T>;

  template <typename T>
  concept has_size_and_external_impl = has_size<T> && has_external_impl<T>;

  template <typename T>
  concept need_inspection = has_size<T> || has_internal_impl<T> || is_smart_ptr<T> || is_variant<T>;

  template <typename T>
  concept needs_recursion = is_iterable<T> && need_inspection<typename T::value_type> && !is_unordered_map<T> && !has_internal_impl<T>;

  template <typename T>
  concept no_needs_recursion = is_iterable<T> && !
  need_inspection<typename T::value_type> && ! has_internal_impl<T> && !is_unordered_map<T>;

  template <typename T>
  concept is_unordered_map_needs_recursion =
      is_unordered_map<T> && need_inspection<typename T::mapped_type>;

  template <typename T>
  concept is_unordered_map_no_needs_recursion = is_unordered_map<T> && !
  need_inspection<typename T::mapped_type>;

  template <typename T>
  concept has_capacity = requires(T a) { a.capacity(); };

  // allocated size if only size
  template <typename T>
  size_t allocated_size(const T& t)
  {
    return t.size();
  }

  // allocated size if capacity
  template <has_capacity T>
  size_t allocated_size(const T& t)
  {
    return t.capacity();
  }

  template <typename T>
  size_t used_size(const T&, record&)
  {
    return sizeof(T);
  }

  template <has_internal_impl T>
  size_t used_size(const T& t, record& mc)
  {
    return t.size_impl(mc);
  }

  template <has_external_impl T>
  size_t used_size(const T& t, record& mc)
  {
    return size_impl(t, mc);
  }

  template <no_needs_recursion T>
  size_t used_size(const T& t, record&)
  {
    size_t res = sizeof(T) + sizeof(typename T::value_type) * allocated_size(t);
    return res;
  }

  template <needs_recursion T>
  size_t used_size(const T& t, record& mc)
  {
    size_t res = sizeof(T);
    for (auto i : t)
      res += used_size(i, mc);
    return res;
  }

  template <has_size_and_internal_impl T>
  size_t used_size(const T& t, record& mc)
  {
    return t.size_impl(mc);
  }

  template <has_size_and_external_impl T>
  size_t used_size(const T& t, record& mc)
  {
    return size_impl(t, mc);
  }

  template <is_smart_ptr T>
  size_t used_size(const T& t, record& mc)
  {
    size_t res = sizeof(std::shared_ptr<void>);
    if (t && mc.not_counted(t.get())) res += used_size(*t, mc);
    return res;
  }

  template <is_variant T>
  size_t used_size(const T& t, record& mc)
  {
    size_t res = sizeof(t);
    res += std::visit([&](auto&& a) -> size_t { return used_size(a, mc); }, t);
    return res;
  }

  template <is_unordered_map_no_needs_recursion M>
  size_t used_size(const M& m, record& )
  {
    size_t res = (m.size() * (sizeof(typename M::value_type) + sizeof(void*)) +  // data list
                  m.bucket_count() * (sizeof(void*) + sizeof(size_t)))  // bucket index
                 * 3  // estimated allocation overheads
        ;
    res /= 2;
    return res;
  }

  template <is_unordered_map_needs_recursion M>
  size_t used_size(const M& m, record& mc)
  {
    size_t res = (m.size() * (sizeof(typename M::value_type) + sizeof(void*)) +  // data list
                  m.bucket_count() * (sizeof(void*) + sizeof(size_t)))  // bucket index
                 * 3  // estimated allocation overheads
        ;
    res /= 2; 
    for (auto const& v : m)
      res += used_size(v.second,mc);
    return res;
  }

}  // namespace memory

// --------------------

template <typename T>
size_t memory_sizes(memory::record& mc, const T& t)
{
  return memory::used_size(t, mc);
}

template <typename T, typename... Ts>
size_t memory_sizes(memory::record& mc, const T& t, const Ts&... args)
{
  return memory::used_size(t, mc) + memory_sizes(mc, args...);
}

template <typename T>
size_t memory_size(const T& t)
{
  memory::record mc;
  return memory::used_size(t, mc);
}
