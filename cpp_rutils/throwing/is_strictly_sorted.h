#pragma once 

#include <iterator>
#include "../to_string.h"

namespace throwing {

    template <class _FwdIt, class _Pr>
	requires (is_printable< typename std::iterator_traits<_FwdIt>::value_type > )
    bool is_strictly_sorted(_FwdIt _First, _FwdIt _Last, _Pr _Pred) { // test if range is strictly ordered by operator<
        if (_First != _Last) {
            for (auto _Next = _First; ++_Next != _Last; ++_First) {
                if (!(_Pred(*_First, *_Next))) {
					auto _First_str = to_string(*_First);
					auto _Next_str = to_string(*_Next);
                    auto where = std::distance(_First, _Next);
                    throw std::runtime_error(fmt::format("range not strictly sorted at index {}: !({} < {})", where, _First_str, _Next_str));
                }
            }
        }
        return true;
    }

    template <class _FwdIt, class _Pr>
        requires (! is_printable< typename std::iterator_traits<_FwdIt>::value_type >)
    bool is_strictly_sorted(_FwdIt _First, _FwdIt _Last, _Pr _Pred) { // test if range is strictly ordered by operator<
        if (_First != _Last) {
            for (auto _Next = _First; ++_Next != _Last; ++_First) {
                if (!(_Pred(*_First, *_Next))) {
                    auto where = std::distance(_First, _Next);
                    throw std::runtime_error(fmt::format("range not strictly sorted at index {}", where));
                }
            }
        }
        return true;
    }

    template <class _FwdIt>
    bool is_strictly_sorted(_FwdIt _First, _FwdIt _Last) { // test if range is strictly ordered by operator<
        return is_strictly_sorted(_First, _Last, std::less{});
    }


}