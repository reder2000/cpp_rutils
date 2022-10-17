#pragma once

#include <concepts>

template <class T>
concept VectorConcept = requires(T a)
{
  {
    a.begin()
    } -> std::same_as<typename T::iterator>;
  {
    a.end()
    } -> std::same_as<typename T::iterator>;
  {
    a.size()
    } -> std::same_as<size_t>;
  {
    a.size()
    } -> std::same_as<size_t>;
  {
    a.empty()
    } -> std::same_as<bool>;
};
