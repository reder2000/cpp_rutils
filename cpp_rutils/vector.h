#pragma once

// make vector from tuples

#include <vector>
#include "shared_ptr.h"
#include <algorithm>

template<class _Ty>
using vc = std::vector<_Ty>;

template<class _Ty>
using sp_vc = sp<vc<_Ty>>;

template<class _Ty>
inline
sp_vc<_Ty> new_sp_vc(std::initializer_list<_Ty> l) {
    return sp_vc<_Ty>(new vc<_Ty>(l));
}

template<class _Ty, class... Args>
inline
sp_vc<_Ty> new_sp_vc(Args... args) {
    return sp_vc<_Ty>(new vc<_Ty>(args...));
}

template<class _Ty>
using vc_sp = vc<sp<_Ty>>;

template<class _Ty>
inline
vc_sp<_Ty> new_vc_sp(_Ty &&t) {
    return vc_sp<_Ty>({new_sp<_Ty>(std::forward<_Ty>(t))});
}

template<class _Ty>
inline
vc_sp<_Ty> new_vc_sp(std::initializer_list<_Ty> l) {
    vc_sp<_Ty> res(l.size());
    std::transform(l.begin(), l.end(), res.begin(),
                   [](const _Ty &v) { return sp<_Ty>(new _Ty(v)); });
    return res;
}


template<class T, class TU>
vc<T> vc_move_tuple(TU &&t) {
    vc<T> res;
    res.reserve(std::tuple_size<typename std::decay_t<TU>>::value);
    std::apply([&res](auto &&...x) { ((res.push_back(std::move(x))), ...); }, std::forward(t));
    return res;
}

template<class T, class TU>
vc_sp<T> vc_sp_move_tuple(TU &&t) {
    vc_sp<T> res;
    res.reserve(std::tuple_size<typename std::decay_t<TU>>::value);
    std::apply([&res](auto &&...x) {
        ((res.push_back(
                sp<T>(new std::decay_t<decltype(x)>(std::move(x)))
        )), ...);
    }, std::forward<TU>(t));
    return res;
}

template<class T, class TU>
vc<T> vc_from_tuple(const TU &t) {
    vc<T> res;
    res.reserve(std::tuple_size<typename std::decay_t<TU>>::value);
    std::apply([&res](auto const &...x) { ((res.push_back(x)), ...); }, t);
    return res;
}

template<class T, class TU>
vc_sp<T> vc_sp_from_tuple(const TU &t) {
    vc_sp<T> res;
    res.reserve(std::tuple_size<typename std::decay_t<TU>>::value);
    std::apply([&res](auto &...x) {
        ((res.push_back(
                sp<T>(new std::decay_t<decltype(x)>(x))
        )), ...);
    }, t);
    return res;
}
