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
# ifndef ROOST_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
# define ROOST_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_EXPR_IIF */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_EXPR_IIF(bit, expr) ROOST_PP_EXPR_IIF_I(bit, expr)
# else
#    define ROOST_PP_EXPR_IIF(bit, expr) ROOST_PP_EXPR_IIF_OO((bit, expr))
#    define ROOST_PP_EXPR_IIF_OO(par) ROOST_PP_EXPR_IIF_I ## par
# endif
#
# define ROOST_PP_EXPR_IIF_I(bit, expr) ROOST_PP_EXPR_IIF_ ## bit(expr)
#
# define ROOST_PP_EXPR_IIF_0(expr)
# define ROOST_PP_EXPR_IIF_1(expr) expr
#
# endif
