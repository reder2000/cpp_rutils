#pragma once

// replace static_assert(sizeof<T>==0)
// with  static_assert(always_false_v<T>)
// for unimplemented template failure

template <class... T>
struct always_false
{
  static constexpr bool value = false;
};

template <class... T>
constexpr bool always_false_v = always_false<T...>::value;