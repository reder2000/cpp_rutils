#pragma once 

#include "../string_literal.h"

// clang does not like details
namespace detaill
{

  // index
  template <StringLiteral T, class Tuple>
  struct tuple_sl_index
  {
    static_assert(! std::is_same_v<Tuple, tuple_sl<>>, "Could not find `T` in given `Tuple`");
  };

  template <StringLiteral T, StringLiteral... Types>
  struct tuple_sl_index<T, tuple_sl<T, Types...>>
  {
    static constexpr std::size_t value = 0;
  };

  template <StringLiteral T, StringLiteral U, StringLiteral... Types>
  struct tuple_sl_index<T, tuple_sl<U, Types...>>
  {
    static const std::size_t value = 1 + tuple_sl_index<T, tuple_sl<Types...>>::value;
  };

  // contains

  template <StringLiteral T, class Tuple>
  struct tuple_sl_contains
  {
    static constexpr bool value = false;
  };

  template <StringLiteral T, StringLiteral... Types>
  struct tuple_sl_contains<T, tuple_sl<T, Types...>>
  {
    static constexpr bool value = true;
  };

  template <StringLiteral T, StringLiteral U, StringLiteral... Types>
  struct tuple_sl_contains<T, tuple_sl<U, Types...>>
  {
    static const bool value = tuple_sl_contains<T, tuple_sl<Types...>>::value;
  };

  // get

  template <std::size_t I, class T>
  struct tuple_sl_get
  {
    static_assert(! std::is_same_v<T, tuple_sl<>>, "Could not find `T` in given `Tuple`");
  };

  template <std::size_t I, StringLiteral Head, StringLiteral... Tail>
  struct tuple_sl_get<I, tuple_sl<Head, Tail...>> : tuple_sl_get<I - 1, tuple_sl<Tail...>>
  {
  };

  template <StringLiteral Head, StringLiteral... Tail>
  struct tuple_sl_get<0, tuple_sl<Head, Tail...>>
  {
    static constexpr auto value = Head;
  };

  // array of values

  // old version
  //template <typename T, std::size_t... Is>
  //constexpr	auto get_tuple_sl_array_i(T t, std::integer_sequence<size_t, Is...> i)
  //{
  //	return std::array{ static_cast<const char*>(tuple_sl_get<Is, T>.value)... };
  //}

  //template <StringLiteral ...Ts>
  //constexpr std::array<const char*, sizeof...(Ts)>
  //	//auto
  //	get_tuple_sl_array(tuple_sl<Ts...>) {
  //	using Is = std::make_integer_sequence<size_t, sizeof...(Ts)>;
  //	//return std::array<const char*, sizeof...(Ts)> { (tuple_sl_element_get<Is, tuple_sl<Ts>>) , ... };
  //	return get_tuple_sl_array_i(tuple_sl<Ts...>{}, Is{});
  //}

  template <StringLiteral... Ts>
  constexpr std::array<const char*, sizeof...(Ts)> get_tuple_sl_array(tuple_sl<Ts...>)
  {
    return {(Ts.value)...};
  }

  //
  template <StringLiteral... Ts>
  std::string_view d_tuple_sl_get_i(size_t i, tuple_sl<Ts...>)
  {
    MREQUIRE(i < sizeof...(Ts));
    return get_tuple_sl_array(tuple_sl<Ts...>{})[i];
  }

}  // namespace detaill
