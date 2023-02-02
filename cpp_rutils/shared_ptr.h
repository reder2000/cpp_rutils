#pragma once

// shorten std::shared_ptr to sp
// shorten std::shared_ptr<const ...> to spc
// shorten std::unique_ptr to up
// shorten std::unique_ptr<const ...> to upc

#include <memory>

// Shared Pointer
template <class _Ty>
using sp = std::shared_ptr<_Ty>;

// Shared Pointer to Const
template <class _Ty>
using spc = std::shared_ptr<const _Ty>;

template <typename T, typename... Args>
std::shared_ptr<T> make_share_aggregate(Args&&... args)
{
  return std::make_shared<T>(T{std::forward<Args>(args)...});
}

// abbreviation for std::make_shared
// problems with aggregates & llvm so this does not work #define m_sp std::make_shared
#ifdef __clang__
template <typename T, typename... Args>
#define m_sp make_share_aggregate
#else
#define m_sp std::make_shared
#endif



template <class _Ty>
sp<_Ty> new_sp()
{
  return sp<_Ty>(new _Ty);
}

template <class _Ty>
sp<_Ty> new_sp(_Ty&& t)
{
  return sp<_Ty>(new _Ty(std::forward<_Ty>(t)));
}

template <class _Ty>
spc<_Ty> new_spc(_Ty&& t)
{
  return spc<_Ty>(new _Ty(std::forward<_Ty>(t)));
}

template <class _Ty, class _OTy>
sp<_Ty> make_sp_copy(const _OTy& t)
{
  return sp<_Ty>(new _Ty((_OTy(t))));
}

template <class _Ty, class _OTy>
sp<_Ty> make_sp_move(_OTy&& t)
{
  return sp<_Ty>(new _Ty(std::move(t)));
}

// Unique Pointer
template <class _Ty>
using up = std::unique_ptr<_Ty>;

// Unique Pointer to Const
template <class _Ty>
using upc = std::unique_ptr<const _Ty>;

template <class _Ty>
upc<_Ty> new_upc(_Ty&& t)
{
  return upc<_Ty>(new _Ty(std::forward<_Ty>(t)));
}

template <class _Ty>
up<_Ty> new_up(_Ty&& t)
{
  return up<_Ty>(new _Ty(std::forward<_Ty>(t)));
}


template <class T>
std::decay_t<T>& auto_const_cast(const T& t)
{
  return const_cast<std::decay_t<T>&>(t);
}
