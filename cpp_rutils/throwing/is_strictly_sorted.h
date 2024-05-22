#pragma once 

#include <iterator>
#include "../to_string.h"

namespace throwing {

    template <class FwdIt, class Pr>
	requires (is_printable< typename std::iterator_traits<FwdIt>::value_type > )
    bool is_strictly_sorted(FwdIt first, FwdIt last, Pr pred) { // test if range is strictly ordered by operator<
        if (first != last) {
          auto First = first;
            for (auto next = first; ++next != last; ++first) {
                if (!(pred(*first, *next))) {
					auto first_str = to_string(*first);
					auto next_str = to_string(*next);
                    auto where = std::distance(First, next);
                                        throw std::runtime_error(
                                            std__format("range not strictly sorted at index {}: !({} < {})", where,
                                                        first_str, next_str));
                }
            }
        }
        return true;
    }

    template <class FwdIt, class Pr>
        requires (! is_printable< typename std::iterator_traits<FwdIt>::value_type >)
    bool is_strictly_sorted(FwdIt first, FwdIt last, Pr pred) { // test if range is strictly ordered by operator<
        if (first != last) {
          auto First = first;
            for (auto next = first; ++next != last; ++first) {
                if (!(pred(*first, *next))) {
                    auto where = std::distance(First, next);
                  throw std::runtime_error(std__format("range not strictly sorted at index {}", where));
                }
            }
        }
        return true;
    }

    template <class FwdIt>
    bool is_strictly_sorted(FwdIt first, FwdIt last) { // test if range is strictly ordered by operator<
        return is_strictly_sorted(first, last, std::less{});
    }


}
