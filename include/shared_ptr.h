#pragma once 

#include <memory>

template <class _Ty>
using sp = std::shared_ptr<_Ty>;

template <class _Ty>  inline
sp<_Ty> new_sp() {
    return sp<_Ty>(new _Ty);
}

template <class _Ty>  inline
sp<_Ty> new_sp(_Ty && t) {
    return sp<_Ty>(new _Ty(std::move(t)));
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
