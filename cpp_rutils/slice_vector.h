#pragma once

#include <vector>

#include "assign_m.h"

template <class T>
struct SliceVectorIterator
{
  using iterator_category = std::random_access_iterator_tag;
  using valueTpe          = std::remove_cv_t<T>;
  using differenceTpe     = ptrdiff_t;
  using pointer           = T*;
  using reference         = T&;

  constexpr reference operator*() const noexcept { return *_data; }

  constexpr pointer operator->() const noexcept { return _data; }

  constexpr SliceVectorIterator& operator++() noexcept
  {
    _data += _stride;
    return *this;
  }

  constexpr SliceVectorIterator operator++(int) noexcept
  {
    SliceVectorIterator _Tmp{*this};
    ++*this;
    return _Tmp;
  }

  constexpr SliceVectorIterator& operator--() noexcept
  {
    _data -= _stride;
    return *this;
  }

  constexpr SliceVectorIterator operator--(int) noexcept
  {
    SliceVectorIterator _Tmp{*this};
    --*this;
    return _Tmp;
  }

  constexpr SliceVectorIterator& operator+=(const differenceTpe offset) noexcept
  {
    _data += offset * _stride;
    return *this;
  }

  constexpr SliceVectorIterator operator+(const differenceTpe offset) const noexcept
  {
    SliceVectorIterator _Tmp{*this};
    _Tmp += offset * _stride;
    return _Tmp;
  }

  constexpr SliceVectorIterator& operator-=(const differenceTpe offset) noexcept
  {
    _data -= offset * _stride;
    return *this;
  }

  constexpr SliceVectorIterator operator-(const differenceTpe offset) const noexcept
  {
    SliceVectorIterator _Tmp{*this};
    _Tmp -= offset * _stride;
    return _Tmp;
  }

  constexpr differenceTpe operator-(const SliceVectorIterator& _Right) const noexcept
  {
    return _data - _Right._data;
  }

  constexpr reference operator[](const differenceTpe offset) const noexcept
  {
    return *(*this + offset);
  }

  constexpr bool operator==(const SliceVectorIterator& _Right) const noexcept
  {
    return _data == _Right._data && _stride = _Right._stride;
  }

  constexpr std::strong_ordering operator<=>(const SliceVectorIterator& _Right) const noexcept
  {
    return std::pair{_data, _stride} <=> std::pair{_Right._data, _Right._stride};
  }

  pointer _data   = nullptr;
  size_t  _stride = 1;
};

// stride non-owing vector
template <class T>
struct SliceVector
{
  SliceVector() = default;
  SliceVector(T* data, size_t size, size_t stride);
  SliceVector(const std::vector<std::decay_t<T>>& v)
    requires std::is_const_v<T>
      : _data(v.data()), _size(v.size()), _stride(1)
  {
  }

  SliceVector(std::vector<std::decay_t<T>>& v)
    requires(! std::is_const_v<T>)
      : _data(v.data()), _size(v.size()), _stride(1)
  {
  }

  size_t size() const { return _size; }

  using iterator = SliceVectorIterator<T>;

  iterator begin() { return iterator{_data, _stride}; }
  iterator end() { return iterator{_data + _size * _stride, _stride}; }

  T*     _data;
  size_t _size;
  size_t _stride;
};


template <class T>
SliceVector<T>::SliceVector(T* data, size_t size, size_t stride) : A_(data), A_(size), A_(stride)
{
}
