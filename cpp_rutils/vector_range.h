#pragma once 

#include <vector>
#include "require.h"

// vector result as ranges

template <class I>
std::vector<I> vector_range(I stop);

template <class I>
std::vector<I> vector_range(I start, I stop);

template <class I, class J>
std::vector<I> vector_range(I start, I stop, J step);

// ---------------------------

template<class I>
inline std::vector<I> vector_range(I stop)
{
    std::vector<I> res(stop);
    for (I i = 0; i < stop; ++i)
        res[i] = i;
    return res;
}

template<class I>
inline std::vector<I> vector_range(I start, I stop)
{
    std::vector<I> res(stop-start);
    size_t j = 0; 
    for (I i = start; i < stop; ++i,++j)
        res[j] = i;
    return res;
}

template<class I, class J>
inline std::vector<I> vector_range(I start, I stop, J step)
{
    std::vector<I> res;
    if (start > stop) {
        MREQUIRE(step < 0);
        res.reserve((start - stop) / (-step));
        for (I i = start; i > stop; i += step)
            res.push_back(i);
    }
    else {
        MREQUIRE(step > 0);
        res.reserve((stop - start) / (step));
        for (I i = start; i < stop; i += step)
            res.push_back(i);
    }
    return res;
}
