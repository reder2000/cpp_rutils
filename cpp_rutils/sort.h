#pragma once 

#include <concepts>
#include <algorithm>

template <class T>
concept VectorConcept = requires(T a)
{
    { a.begin() } -> std::same_as<typename T::iterator>;
    { a.end() } -> std::same_as<typename T::iterator>;
};

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


//template <class _FwdIt, class _Pr>
//bool is_strictly_sorted(_FwdIt _First, _FwdIt _Last, _Pr _Pred) { // test if range is strictly ordered by operator<
//        if (_First != _Last) {
//            for (auto _Next = _First; ++_Next != _Last; ++_First) {
//                if (!(_Pred( *_First, *_Next))) {
//                    return false;
//                }
//            }
//        }
//        return true;
//}
//
//template <class _FwdIt>
//bool is_strictly_sorted(_FwdIt _First, _FwdIt _Last) { // test if range is strictly ordered by operator<
//    return is_strictly_sorted(_First, _Last, std::less{});
//}
//
//template <class _FwdIt, class _Pr>
//_FwdIt is_strictly_sorted_until(_FwdIt _First, _FwdIt _Last, _Pr _Pred) {
//    if (_First != _Last) {
//        for (auto _Next = _First; ++_Next != _Last; ++_First) {
//            if (!(_Pred(*_First, *_Next))) {
//                return _First;
//            }
//        }
//    }
//    return _Last;
//}
//
//template <class _FwdIt>
//_FwdIt is_strictly_sorted_until(_FwdIt _First, _FwdIt _Last) { // test if range is strictly ordered by operator<
//    return is_strictly_sorted_until(_First, _Last, std::less{});
//}
