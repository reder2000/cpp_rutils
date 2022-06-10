#pragma once 

// helper function to compute/deduce the used_size of an object
// an object of type T may provide a computation by either
// implementing a member function size_impl(memory::record &) const
// of a free function size_impl(const T&, memory::record &)

#include <concepts>
#include <memory>
#include <variant>
#include <unordered_set>

namespace memory {


    // records if an object is already counted (shared pointers...)
    struct record {
        bool not_counted(const void* address) {
            if (!_already_counted.contains(address)) {
                _already_counted.insert(address);
                return true;
            }
            return false;
        }
    private:
        std::unordered_set<const void*> _already_counted;
    };

    // reference for concept check
    inline
        record& fake_count() {
        static record res;
        return res;
    }

    // smart pointers will need inspection
    template <typename T>
    concept is_smart_ptr =
        requires(T a) { a.reset(); };

    // variant will need visitation
    template <typename T>
    concept is_variant =
        requires(T a) { a.valueless_by_exception(); };

    // iterables will need iteration
    template<typename T>
    concept is_iterable =
        requires (T a) { a.begin(); };

    template<typename T>
    concept is_not_iterable = !is_iterable<T>;

    // type has internal helper for used_size
    template<typename T>
    concept has_internal_impl =
        requires (T a) { a.size_impl(fake_count()); };

    // type has external helper for used_size
    template<typename T>
    concept has_external_impl =
        requires (const T &a) { size_impl(a,fake_count()); };

    // type has a used_size (std::vector...)
    template<typename T>
    concept has_size =
        requires (T a) { a.used_size(); };

    template<typename T>
    concept has_size_and_internal_impl =
        has_size<T> && has_internal_impl<T>;

    template<typename T>
    concept has_size_and_external_impl =
        has_size<T> && has_external_impl<T>;

    template<typename T>
    concept need_inspection =
        has_size<T> || has_internal_impl<T> || is_smart_ptr<T> || is_variant<T>;

    template<typename T>
    concept needs_recursion =
        is_iterable<T> && need_inspection <typename T::value_type>;

    template<typename T>
    concept no_needs_recursion =
        is_iterable<T> && !need_inspection <typename T::value_type>;

    template<typename T>
    concept has_capacity =
		requires (T a) { a.capacity(); };

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
    size_t used_size(const T& t, record&) {
        return sizeof(T);
    }

    template <has_internal_impl T>
    size_t used_size(const T& t, record& mc) {
        return t.size_impl(mc);
    }

    template <has_external_impl T>
    size_t used_size(const T& t, record& mc) {
        return size_impl(t,mc);
    }

    template <no_needs_recursion T>
    size_t used_size(const T& t, record&) {
        return sizeof(T) + sizeof(typename T::value_type) * allocated_size(t);
    }

    template <needs_recursion T>
    size_t used_size(const T& t, record& mc) {
        size_t res = sizeof(T);
        for (auto i : t)
            res += used_size(i, mc);
        return res;
    }

    template <has_size_and_internal_impl T>
    size_t used_size(const T& t, record& mc) {
        return t.size_impl(mc);
    }

    template <has_size_and_external_impl T>
    size_t used_size(const T& t, record& mc) {
        return size_impl(t,mc);
    }

    template <is_smart_ptr T>
    size_t used_size(const T& t, record& mc) {
        size_t res = sizeof(std::shared_ptr<void>);
        if (t && mc.not_counted(t.get()))
            res += used_size(*t, mc);
        return res;
    }

    template <is_variant T>
    size_t used_size(const T& t, record& mc) {
        size_t res = sizeof(t);
        res += std::visit([&](auto&& a) -> size_t {return used_size(a, mc); }, t);
        return res;
    }

} // memory namespace 

// --------------------

template <typename T>
size_t memory_sizes(memory::record& mc, const T& t) {
    return memory::used_size(t,mc);
}

template <typename T, typename... Ts>
size_t memory_sizes(memory::record& mc, const T& t, const Ts&... args) {
    return memory::used_size(t,mc) + memory_sizes(mc,args...);
}

template <typename T>
size_t memory_size(const T& t) {
    memory::record mc;
    return memory::used_size(t,mc);
}
