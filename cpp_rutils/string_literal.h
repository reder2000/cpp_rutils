#pragma once 

#include <algorithm>
#include <require.h>
#include <string_view>
#include <array>
#include "index.h"

// string used as literal for non type template parameter
// literal class type that wraps a constant expression string
template <size_t N>
struct StringLiteral
{
	//  Uses implicit conversion to allow templates to *seemingly* accept constant strings
	constexpr StringLiteral(const char(&str)[N]) { std::copy_n(str, N, value); }

	// compares strings (for lookup in template varargs)
	template <size_t M>
	constexpr bool operator==(const char(&str)[M]) const
	{
		if constexpr (M != N) return false;
		size_t i = 0;
		for (; (i < M) && (value[i] == str[i]); i++)
			;
		return i == M;
	}

	//template <size_t M>
	constexpr bool operator==(const StringLiteral& sl) const { return *this == sl.value; }

	char                 value[N];
	//inline static size_t NN = N;
};


// tuple_like holder of string literals
template <StringLiteral... Us>
struct tuple_sl;

template <>
struct tuple_sl<>
{
};

template <StringLiteral U, StringLiteral... Us>
struct tuple_sl<U, Us...> : private tuple_sl<Us...>
{
};

#include "detail/string_literal.h"

// is T  in tuple_sl ? returns std::string::npos if not found
template <StringLiteral T, class U>
constexpr bool tuple_sl_contains = detail::tuple_sl_contains<T, U>::value;

// find index of T in tuple_sl
template <StringLiteral T, class U>
constexpr size_t tuple_sl_index = detail::tuple_sl_index   <T, U>::value;

// find value if Ith string literal in T
template <std::size_t I, class T>
constexpr auto tuple_sl_get = detail::tuple_sl_get<I, T>::value;

// array of values
template <typename T>
constexpr auto tuple_sl_array = detail::get_tuple_sl_array(T{});

// runtime i-th value
template <typename T>
std::string_view tuple_sl_get_i(size_t i)
{
	return detail::tuple_sl_get_i(i, T{});
}

// runtime index of value. npos if not found
template <typename T>
size_t tuple_sl_index_s(std::string_view s)
{
	return index(tuple_sl_array<T>, s );
}
