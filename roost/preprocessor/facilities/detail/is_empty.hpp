# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Roost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
#ifndef ROOST_PREPROCESSOR_DETAIL_IS_EMPTY_HPP
#define ROOST_PREPROCESSOR_DETAIL_IS_EMPTY_HPP

#include <roost/preprocessor/punctuation/is_begin_parens.hpp>

#if ROOST_PP_VARIADICS_MSVC

# pragma warning(once:4002)

#define ROOST_PP_DETAIL_IS_EMPTY_IIF_0(t, b) b
#define ROOST_PP_DETAIL_IS_EMPTY_IIF_1(t, b) t

#else

#define ROOST_PP_DETAIL_IS_EMPTY_IIF_0(t, ...) __VA_ARGS__
#define ROOST_PP_DETAIL_IS_EMPTY_IIF_1(t, ...) t

#endif

#if ROOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define ROOST_PP_DETAIL_IS_EMPTY_PROCESS(param) \
    ROOST_PP_IS_BEGIN_PARENS \
        ( \
        ROOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C param () \
        ) \
/**/

#else

#define ROOST_PP_DETAIL_IS_EMPTY_PROCESS(...) \
    ROOST_PP_IS_BEGIN_PARENS \
        ( \
        ROOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C __VA_ARGS__ () \
        ) \
/**/

#endif

#define ROOST_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(a, b) a ## b
#define ROOST_PP_DETAIL_IS_EMPTY_IIF(bit) ROOST_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(ROOST_PP_DETAIL_IS_EMPTY_IIF_,bit)
#define ROOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C(...) ()

#endif /* ROOST_PREPROCESSOR_DETAIL_IS_EMPTY_HPP */
