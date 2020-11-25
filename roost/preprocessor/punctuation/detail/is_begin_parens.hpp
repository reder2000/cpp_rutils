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
#ifndef ROOST_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP
#define ROOST_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP

#if ROOST_PP_VARIADICS_MSVC

#include <roost/preprocessor/facilities/empty.hpp>

#define ROOST_PP_DETAIL_VD_IBP_CAT(a, b) ROOST_PP_DETAIL_VD_IBP_CAT_I(a, b)
#define ROOST_PP_DETAIL_VD_IBP_CAT_I(a, b) ROOST_PP_DETAIL_VD_IBP_CAT_II(a ## b)
#define ROOST_PP_DETAIL_VD_IBP_CAT_II(res) res

#define ROOST_PP_DETAIL_IBP_SPLIT(i, ...) \
    ROOST_PP_DETAIL_VD_IBP_CAT(ROOST_PP_DETAIL_IBP_PRIMITIVE_CAT(ROOST_PP_DETAIL_IBP_SPLIT_,i)(__VA_ARGS__),ROOST_PP_EMPTY()) \
/**/

#define ROOST_PP_DETAIL_IBP_IS_VARIADIC_C(...) 1 1

#else

#define ROOST_PP_DETAIL_IBP_SPLIT(i, ...) \
    ROOST_PP_DETAIL_IBP_PRIMITIVE_CAT(ROOST_PP_DETAIL_IBP_SPLIT_,i)(__VA_ARGS__) \
/**/

#define ROOST_PP_DETAIL_IBP_IS_VARIADIC_C(...) 1

#endif /* ROOST_PP_VARIADICS_MSVC */

#define ROOST_PP_DETAIL_IBP_SPLIT_0(a, ...) a
#define ROOST_PP_DETAIL_IBP_SPLIT_1(a, ...) __VA_ARGS__

#define ROOST_PP_DETAIL_IBP_CAT(a, ...) ROOST_PP_DETAIL_IBP_PRIMITIVE_CAT(a,__VA_ARGS__)
#define ROOST_PP_DETAIL_IBP_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define ROOST_PP_DETAIL_IBP_IS_VARIADIC_R_1 1,
#define ROOST_PP_DETAIL_IBP_IS_VARIADIC_R_ROOST_PP_DETAIL_IBP_IS_VARIADIC_C 0,

#endif /* ROOST_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP */
