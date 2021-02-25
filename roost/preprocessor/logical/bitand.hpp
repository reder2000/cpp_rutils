# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_LOGICAL_BITAND_HPP
# define ROOST_PREPROCESSOR_LOGICAL_BITAND_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_BITAND */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_BITAND(x, y) ROOST_PP_BITAND_I(x, y)
# else
#    define ROOST_PP_BITAND(x, y) ROOST_PP_BITAND_OO((x, y))
#    define ROOST_PP_BITAND_OO(par) ROOST_PP_BITAND_I ## par
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()
#    define ROOST_PP_BITAND_I(x, y) ROOST_PP_BITAND_ ## x ## y
# else
#    define ROOST_PP_BITAND_I(x, y) ROOST_PP_BITAND_ID(ROOST_PP_BITAND_ ## x ## y)
#    define ROOST_PP_BITAND_ID(res) res
# endif
#
# define ROOST_PP_BITAND_00 0
# define ROOST_PP_BITAND_01 0
# define ROOST_PP_BITAND_10 0
# define ROOST_PP_BITAND_11 1
#
# endif
