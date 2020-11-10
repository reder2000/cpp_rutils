# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Roost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.roost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_CAT_HPP
# define ROOST_PREPROCESSOR_CAT_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_CAT */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_CAT(a, b) ROOST_PP_CAT_I(a, b)
# else
#    define ROOST_PP_CAT(a, b) ROOST_PP_CAT_OO((a, b))
#    define ROOST_PP_CAT_OO(par) ROOST_PP_CAT_I ## par
# endif
#
# if (~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()) || (defined(__INTEL_COMPILER) && __INTEL_COMPILER >= 1700)
#    define ROOST_PP_CAT_I(a, b) a ## b
# else
#    define ROOST_PP_CAT_I(a, b) ROOST_PP_CAT_II(~, a ## b)
#    define ROOST_PP_CAT_II(p, res) res
# endif
#
# endif
