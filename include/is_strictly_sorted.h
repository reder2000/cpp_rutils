#pragma once 

#include <algorithm>

template <class _FwdIt>
bool is_strictly_sorted(_FwdIt _First, _FwdIt _Last) { // test if range is strictly ordered by operator<
    return std::is_sorted(_First, _Last) &&
        (std::unique(_First, _Last) == _Last);
}

template <class _FwdIt>
_FwdIt is_strictly_sorted_until(_FwdIt _First, _FwdIt _Last) {
    _FwdIt res = std::is_sorted_until(_First, _Last);
    if (res == _Last)
        res = std::unique(_First, _Last);
    return res;
}
