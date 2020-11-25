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
# ifndef ROOST_PREPROCESSOR_LOGICAL_COMPL_HPP
# define ROOST_PREPROCESSOR_LOGICAL_COMPL_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_COMPL */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_COMPL(x) ROOST_PP_COMPL_I(x)
# else
#    define ROOST_PP_COMPL(x) ROOST_PP_COMPL_OO((x))
#    define ROOST_PP_COMPL_OO(par) ROOST_PP_COMPL_I ## par
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()
#    define ROOST_PP_COMPL_I(x) ROOST_PP_COMPL_ ## x
# else
#    define ROOST_PP_COMPL_I(x) ROOST_PP_COMPL_ID(ROOST_PP_COMPL_ ## x)
#    define ROOST_PP_COMPL_ID(id) id
# endif
#
# define ROOST_PP_COMPL_0 1
# define ROOST_PP_COMPL_1 0
#
# endif
