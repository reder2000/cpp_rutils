#pragma once 

// check thath an input range is strictly sorted

#include <functional>

template <class _FwdIt, class _Pr>
bool is_strictly_sorted(_FwdIt _First, _FwdIt _Last, _Pr _Pred) { // test if range is strictly ordered by operator<
        if (_First != _Last) {
            for (auto _Next = _First; ++_Next != _Last; ++_First) {
                if (!(_Pred( *_First, *_Next))) {
                    return false;
                }
            }
        }
        return true;
}

template <class _FwdIt>
bool is_strictly_sorted(_FwdIt _First, _FwdIt _Last) { // test if range is strictly ordered by operator<
    return is_strictly_sorted(_First, _Last, std::less{});
}

template <class _FwdIt, class _Pr>
_FwdIt is_strictly_sorted_until(_FwdIt _First, _FwdIt _Last, _Pr _Pred) {
    if (_First != _Last) {
        for (auto _Next = _First; ++_Next != _Last; ++_First) {
            if (!(_Pred(*_First, *_Next))) {
                return _First;
            }
        }
    }
    return _Last;
}

template <class _FwdIt>
_FwdIt is_strictly_sorted_until(_FwdIt _First, _FwdIt _Last) { // test if range is strictly ordered by operator<
    return is_strictly_sorted_until(_First, _Last, std::less{});
}
