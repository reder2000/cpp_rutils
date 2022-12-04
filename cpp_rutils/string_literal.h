#pragma once 

#include <algorithm>

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

//template <StringLiteral SL>
//auto consteval operator""_sl()
//{
//  return SL;
//}

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


namespace detail
{

    template <StringLiteral T, class Tuple>
    struct tuple_sl_element_struct
    {
        static_assert(!std::is_same_v<Tuple, tuple_sl<>>, "Could not find `T` in given `Tuple`");
    };

    template <StringLiteral T, StringLiteral... Types>
    struct tuple_sl_element_struct<T, tuple_sl<T, Types...>>
    {
        static constexpr std::size_t value = 0;
    };

    template <StringLiteral T, StringLiteral U, StringLiteral... Types>
    struct tuple_sl_element_struct<T, tuple_sl<U, Types...>>
    {
        static const std::size_t value = 1 + tuple_sl_element_struct<T, tuple_sl<Types...>>::value;
    };
}

// find index of T in tuple_sl
template <StringLiteral T, class U>
constexpr size_t tuple_sl_element = detail::tuple_sl_element_struct<T, U>::value;

namespace detail {
    template <StringLiteral T, class Tuple>
    struct is_tuple_sl_element_struct
    {
        static constexpr bool value = false;
    };

    template <StringLiteral T, StringLiteral... Types>
    struct is_tuple_sl_element_struct<T, tuple_sl<T, Types...>>
    {
        static constexpr bool value = true;
    };

    template <StringLiteral T, StringLiteral U, StringLiteral... Types>
    struct is_tuple_sl_element_struct<T, tuple_sl<U, Types...>>
    {
        static const bool value = is_tuple_sl_element_struct<T, tuple_sl<Types...>>::value;
    };
}

// is T  in tuple_sl ?
template <StringLiteral T, class U>
constexpr bool is_tuple_sl_element = detail::is_tuple_sl_element_struct<T, U>::value;

namespace detail {


    template< std::size_t I, class T >
    struct tuple_sl_element;

    // recursive case
    template< std::size_t I, StringLiteral Head, StringLiteral ... Tail >
    struct tuple_sl_element<I, tuple_sl<Head, Tail...>>
        : tuple_sl_element<I - 1, tuple_sl<Tail...>> { };

    // base case
    template< StringLiteral Head, StringLiteral ... Tail >
    struct tuple_sl_element<0, tuple_sl<Head, Tail...>> {
        static constexpr auto value  = Head;
    };
}

template <std::size_t I, class T>
constexpr auto tuple_sl_element_t = detail::tuple_sl_element<I,T>::value;
