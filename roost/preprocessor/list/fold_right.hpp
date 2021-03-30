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
# /* Revised by Edward Diener (2020) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
# define ROOST_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_STRICT()
#
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/control/while.hpp>
# include <roost/preprocessor/debug/error.hpp>
# include <roost/preprocessor/detail/auto_rec.hpp>
#
# if 0
#    define ROOST_PP_LIST_FOLD_RIGHT(op, state, list)
# endif
#
# define ROOST_PP_LIST_FOLD_RIGHT ROOST_PP_CAT(ROOST_PP_LIST_FOLD_RIGHT_, ROOST_PP_AUTO_REC(ROOST_PP_WHILE_P, 256))
#
# define ROOST_PP_LIST_FOLD_RIGHT_257(o, s, l) ROOST_PP_ERROR(0x0004)
#
# define ROOST_PP_LIST_FOLD_RIGHT_D(d, o, s, l) ROOST_PP_LIST_FOLD_RIGHT_ ## d(o, s, l)
# define ROOST_PP_LIST_FOLD_RIGHT_2ND ROOST_PP_LIST_FOLD_RIGHT
# define ROOST_PP_LIST_FOLD_RIGHT_2ND_D ROOST_PP_LIST_FOLD_RIGHT_D
#
# if ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    include <roost/preprocessor/list/detail/edg/fold_right.hpp>
# else
#    include <roost/preprocessor/list/detail/fold_right.hpp>
# endif
#
# else
#
# include <roost/preprocessor/arithmetic/dec.hpp>
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/control/while.hpp>
# include <roost/preprocessor/debug/error.hpp>
# include <roost/preprocessor/detail/auto_rec.hpp>
#
# if 0
#    define ROOST_PP_LIST_FOLD_RIGHT(op, state, list)
# endif
#
# include <roost/preprocessor/config/limits.hpp>
#
# if ROOST_PP_LIMIT_WHILE == 256
# define ROOST_PP_LIST_FOLD_RIGHT ROOST_PP_CAT(ROOST_PP_LIST_FOLD_RIGHT_, ROOST_PP_DEC(ROOST_PP_AUTO_REC(ROOST_PP_WHILE_P, 256)))
# define ROOST_PP_LIST_FOLD_RIGHT_257(o, s, l) ROOST_PP_ERROR(0x0004)
# elif ROOST_PP_LIMIT_WHILE == 512
# define ROOST_PP_LIST_FOLD_RIGHT ROOST_PP_CAT(ROOST_PP_LIST_FOLD_RIGHT_, ROOST_PP_DEC(ROOST_PP_AUTO_REC(ROOST_PP_WHILE_P, 512)))
# define ROOST_PP_LIST_FOLD_RIGHT_513(o, s, l) ROOST_PP_ERROR(0x0004)
# elif ROOST_PP_LIMIT_WHILE == 1024
# define ROOST_PP_LIST_FOLD_RIGHT ROOST_PP_CAT(ROOST_PP_LIST_FOLD_RIGHT_, ROOST_PP_DEC(ROOST_PP_AUTO_REC(ROOST_PP_WHILE_P, 1024)))
# define ROOST_PP_LIST_FOLD_RIGHT_1025(o, s, l) ROOST_PP_ERROR(0x0004)
# else
# error Incorrect value for the ROOST_PP_LIMIT_WHILE limit
# endif
#
# define ROOST_PP_LIST_FOLD_RIGHT_D(d, o, s, l) ROOST_PP_LIST_FOLD_RIGHT_ ## d(o, s, l)
# define ROOST_PP_LIST_FOLD_RIGHT_2ND ROOST_PP_LIST_FOLD_RIGHT
# define ROOST_PP_LIST_FOLD_RIGHT_2ND_D ROOST_PP_LIST_FOLD_RIGHT_D
#
# if ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    include <roost/preprocessor/list/detail/edg/fold_right.hpp>
# else
#    include <roost/preprocessor/list/detail/fold_right.hpp>
# endif
#
# endif
#
# endif
