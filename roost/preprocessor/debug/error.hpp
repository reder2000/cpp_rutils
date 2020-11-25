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
# ifndef ROOST_PREPROCESSOR_DEBUG_ERROR_HPP
# define ROOST_PREPROCESSOR_DEBUG_ERROR_HPP
#
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_ERROR */
#
# if ROOST_PP_CONFIG_ERRORS
#    define ROOST_PP_ERROR(code) ROOST_PP_CAT(ROOST_PP_ERROR_, code)
# endif
#
# define ROOST_PP_ERROR_0x0000 ROOST_PP_ERROR(0x0000, ROOST_PP_INDEX_OUT_OF_BOUNDS)
# define ROOST_PP_ERROR_0x0001 ROOST_PP_ERROR(0x0001, ROOST_PP_WHILE_OVERFLOW)
# define ROOST_PP_ERROR_0x0002 ROOST_PP_ERROR(0x0002, ROOST_PP_FOR_OVERFLOW)
# define ROOST_PP_ERROR_0x0003 ROOST_PP_ERROR(0x0003, ROOST_PP_REPEAT_OVERFLOW)
# define ROOST_PP_ERROR_0x0004 ROOST_PP_ERROR(0x0004, ROOST_PP_LIST_FOLD_OVERFLOW)
# define ROOST_PP_ERROR_0x0005 ROOST_PP_ERROR(0x0005, ROOST_PP_SEQ_FOLD_OVERFLOW)
# define ROOST_PP_ERROR_0x0006 ROOST_PP_ERROR(0x0006, ROOST_PP_ARITHMETIC_OVERFLOW)
# define ROOST_PP_ERROR_0x0007 ROOST_PP_ERROR(0x0007, ROOST_PP_DIVISION_BY_ZERO)
#
# endif
