#pragma once 

// check thath an input range is strictly sorted

#include <functional>

template <class FwdIt, class Pr>
bool is_strictly_sorted(FwdIt first, FwdIt last, Pr pred) { // test if range is strictly ordered by operator<
        if (first != last) {
            for (auto next = first; ++next != last; ++first) {
                if (!(pred( *first, *next))) {
                    return false;
                }
            }
        }
        return true;
}

template <class FwdIt>
bool is_strictly_sorted(FwdIt first, FwdIt last) { // test if range is strictly ordered by operator<
    return is_strictly_sorted(first, last, std::less{});
}

template <class FwdIt, class Pr>
FwdIt is_strictly_sorted_until(FwdIt first, FwdIt last, Pr pred) {
    if (first != last) {
        for (auto next = first; ++next != last; ++first) {
            if (!(pred(*first, *next))) {
                return first;
            }
        }
    }
    return last;
}

template <class FwdIt>
FwdIt is_strictly_sorted_until(FwdIt first, FwdIt last) { // test if range is strictly ordered by operator<
    return is_strictly_sorted_until(first, last, std::less{});
}
