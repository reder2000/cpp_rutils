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
# ifndef ROOST_PREPROCESSOR_LOGICAL_BITOR_HPP
# define ROOST_PREPROCESSOR_LOGICAL_BITOR_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_BITOR */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_BITOR(x, y) ROOST_PP_BITOR_I(x, y)
# else
#    define ROOST_PP_BITOR(x, y) ROOST_PP_BITOR_OO((x, y))
#    define ROOST_PP_BITOR_OO(par) ROOST_PP_BITOR_I ## par
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()
#    define ROOST_PP_BITOR_I(x, y) ROOST_PP_BITOR_ ## x ## y
# else
#    define ROOST_PP_BITOR_I(x, y) ROOST_PP_BITOR_ID(ROOST_PP_BITOR_ ## x ## y)
#    define ROOST_PP_BITOR_ID(id) id
# endif
#
# define ROOST_PP_BITOR_00 0
# define ROOST_PP_BITOR_01 1
# define ROOST_PP_BITOR_10 1
# define ROOST_PP_BITOR_11 1
#
# endif
