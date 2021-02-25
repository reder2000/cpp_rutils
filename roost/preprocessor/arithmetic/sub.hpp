# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.roost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
# /* Revised by Edward Diener (2020) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_ARITHMETIC_SUB_HPP
# define ROOST_PREPROCESSOR_ARITHMETIC_SUB_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_STRICT()
#
# include <roost/preprocessor/arithmetic/dec.hpp>
# include <roost/preprocessor/control/while.hpp>
# include <roost/preprocessor/tuple/elem.hpp>
#
# /* ROOST_PP_SUB */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_SUB(x, y) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE(ROOST_PP_SUB_P, ROOST_PP_SUB_O, (x, y)))
# else
#    define ROOST_PP_SUB(x, y) ROOST_PP_SUB_I(x, y)
#    define ROOST_PP_SUB_I(x, y) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE(ROOST_PP_SUB_P, ROOST_PP_SUB_O, (x, y)))
# endif
#
# define ROOST_PP_SUB_P(d, xy) ROOST_PP_TUPLE_ELEM(2, 1, xy)
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_SUB_O(d, xy) ROOST_PP_SUB_O_I xy
# else
#    define ROOST_PP_SUB_O(d, xy) ROOST_PP_SUB_O_I(ROOST_PP_TUPLE_ELEM(2, 0, xy), ROOST_PP_TUPLE_ELEM(2, 1, xy))
# endif
#
# define ROOST_PP_SUB_O_I(x, y) (ROOST_PP_DEC(x), ROOST_PP_DEC(y))
#
# /* ROOST_PP_SUB_D */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_SUB_D(d, x, y) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE_ ## d(ROOST_PP_SUB_P, ROOST_PP_SUB_O, (x, y)))
# else
#    define ROOST_PP_SUB_D(d, x, y) ROOST_PP_SUB_D_I(d, x, y)
#    define ROOST_PP_SUB_D_I(d, x, y) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE_ ## d(ROOST_PP_SUB_P, ROOST_PP_SUB_O, (x, y)))
# endif
#
# else
#
# include <roost/preprocessor/arithmetic/dec.hpp>
# include <roost/preprocessor/control/iif.hpp>
# include <roost/preprocessor/control/while.hpp>
# include <roost/preprocessor/facilities/identity.hpp>
# include <roost/preprocessor/logical/and.hpp>
# include <roost/preprocessor/logical/bitor.hpp>
# include <roost/preprocessor/tuple/elem.hpp>
# include <roost/preprocessor/arithmetic/detail/is_maximum_number.hpp>
# include <roost/preprocessor/arithmetic/detail/is_minimum_number.hpp>
#
# /* ROOST_PP_SUB */
#
#    define ROOST_PP_SUB(x, y) ROOST_PP_IIF(ROOST_PP_BITOR(ROOST_PP_DETAIL_IS_MAXIMUM_NUMBER(y),ROOST_PP_DETAIL_IS_MINIMUM_NUMBER(x)),ROOST_PP_IDENTITY_N(0,2),ROOST_PP_SUB_DO)(x,y)
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_SUB_DO(x, y) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE(ROOST_PP_SUB_P, ROOST_PP_SUB_O, (x, y)))
# else
#    define ROOST_PP_SUB_DO(x, y) ROOST_PP_SUB_I(x, y)
#    define ROOST_PP_SUB_I(x, y) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE(ROOST_PP_SUB_P, ROOST_PP_SUB_O, (x, y)))
# endif
#
# define ROOST_PP_SUB_P(d, xy) ROOST_PP_AND(ROOST_PP_TUPLE_ELEM(2, 1, xy),ROOST_PP_TUPLE_ELEM(2, 0, xy))
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_SUB_O(d, xy) ROOST_PP_SUB_O_I xy
# else
#    define ROOST_PP_SUB_O(d, xy) ROOST_PP_SUB_O_I(ROOST_PP_TUPLE_ELEM(2, 0, xy), ROOST_PP_TUPLE_ELEM(2, 1, xy))
# endif
#
# define ROOST_PP_SUB_O_I(x, y) (ROOST_PP_DEC(x), ROOST_PP_DEC(y))
#
# /* ROOST_PP_SUB_D */
#
#    define ROOST_PP_SUB_D(d, x, y) ROOST_PP_IIF(ROOST_PP_BITOR(ROOST_PP_DETAIL_IS_MAXIMUM_NUMBER(y),ROOST_PP_DETAIL_IS_MINIMUM_NUMBER(x)),ROOST_PP_IDENTITY_N(0,3),ROOST_PP_SUB_DO_D)(d,x,y)
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG()
#    define ROOST_PP_SUB_DO_D(d, x, y) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE_ ## d(ROOST_PP_SUB_P, ROOST_PP_SUB_O, (x, y)))
# else
#    define ROOST_PP_SUB_DO_D(d, x, y) ROOST_PP_SUB_D_I(d, x, y)
#    define ROOST_PP_SUB_D_I(d, x, y) ROOST_PP_TUPLE_ELEM(2, 0, ROOST_PP_WHILE_ ## d(ROOST_PP_SUB_P, ROOST_PP_SUB_O, (x, y)))
# endif
#
# endif
#
# endif
