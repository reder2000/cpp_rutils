#pragma once 

#include <memory>

// Shared Pointer
template <class _Ty>
using sp = std::shared_ptr<_Ty>;

// Shared Pointer to Const
template <class _Ty>
using spc = std::shared_ptr<const _Ty>;


template <class _Ty>  inline
sp<_Ty> new_sp() {
    return sp<_Ty>(new _Ty);
}

template <class _Ty>  inline
sp<_Ty> new_sp(_Ty && t) {
    return sp<_Ty>(new _Ty(std::forward<_Ty>(t)));
}


template <class _Ty, class _OTy>
inline
sp<_Ty> make_sp_copy(const _OTy& t) {
    return sp<_Ty>(new _Ty((_OTy(t))));
}

template <class _Ty, class _OTy>
inline
sp<_Ty> make_sp_move(_OTy&& t) {
    return sp<_Ty>(new _Ty(std::move(t)));
}

// Unique Pointer
template <class _Ty>
using up = std::unique_ptr<_Ty>;

// Unique Pointer to Const
template <class _Ty>
using upc = std::unique_ptr<const _Ty>;
