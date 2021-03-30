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
# ifndef ROOST_PREPROCESSOR_IS_BEGIN_PARENS_HPP
# define ROOST_PREPROCESSOR_IS_BEGIN_PARENS_HPP

#include <roost/preprocessor/config/config.hpp>
#include <roost/preprocessor/punctuation/detail/is_begin_parens.hpp>

#if ROOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define ROOST_PP_IS_BEGIN_PARENS(param) \
    ROOST_PP_DETAIL_IBP_SPLIT \
      ( \
      0, \
      ROOST_PP_DETAIL_IBP_CAT \
        ( \
        ROOST_PP_DETAIL_IBP_IS_VARIADIC_R_, \
        ROOST_PP_DETAIL_IBP_IS_VARIADIC_C param \
        ) \
      ) \
/**/

#else

#define ROOST_PP_IS_BEGIN_PARENS(...) \
    ROOST_PP_DETAIL_IBP_SPLIT \
      ( \
      0, \
      ROOST_PP_DETAIL_IBP_CAT \
        ( \
        ROOST_PP_DETAIL_IBP_IS_VARIADIC_R_, \
        ROOST_PP_DETAIL_IBP_IS_VARIADIC_C __VA_ARGS__ \
        ) \
      ) \
/**/

#endif /* ROOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
#endif /* ROOST_PREPROCESSOR_IS_BEGIN_PARENS_HPP */
