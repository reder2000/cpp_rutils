# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Roost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_DETAIL_IS_BINARY_HPP
# define ROOST_PREPROCESSOR_DETAIL_IS_BINARY_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/detail/check.hpp>
#
# /* ROOST_PP_IS_BINARY */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_IS_BINARY(x) ROOST_PP_CHECK(x, ROOST_PP_IS_BINARY_CHECK)
# else
#    define ROOST_PP_IS_BINARY(x) ROOST_PP_IS_BINARY_I(x)
#    define ROOST_PP_IS_BINARY_I(x) ROOST_PP_CHECK(x, ROOST_PP_IS_BINARY_CHECK)
# endif
#
# define ROOST_PP_IS_BINARY_CHECK(a, b) 1
# define ROOST_PP_CHECK_RESULT_ROOST_PP_IS_BINARY_CHECK 0, ROOST_PP_NIL
#
# endif
