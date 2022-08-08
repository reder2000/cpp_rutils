#pragma once 

#include <concepts>

template <class T>
concept VectorConcept = requires(T a)
{
    { a.begin() } -> std::same_as<typename T::iterator>;
    { a.end() } -> std::same_as<typename T::iterator>;
};

