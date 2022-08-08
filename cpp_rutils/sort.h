#pragma once 

// sort vectors in one-line and no boilerplate iterators

#include "vector_concept.h"
#include <algorithm>

template <VectorConcept T>
T&& sort(T&& v) {
    std::sort(v.begin(), v.end());
    return std::forward<T>(v);
}

template <VectorConcept T, class Pred>
T&& sort(T&& v, Pred pred) {
    std::sort(v.begin(), v.end(), pred);
    return std::forward<T>(v);
}

