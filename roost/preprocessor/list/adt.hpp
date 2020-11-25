# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Roost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.roost.org/LICENSE_1_0.txt)
#  *
#  * See http://www.roost.org for most recent version.
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# ifndef ROOST_PREPROCESSOR_LIST_ADT_HPP
# define ROOST_PREPROCESSOR_LIST_ADT_HPP
#
# include <roost/preprocessor/config/config.hpp>
# include <roost/preprocessor/detail/is_binary.hpp>
# include <roost/preprocessor/logical/compl.hpp>
# include <roost/preprocessor/tuple/eat.hpp>
#
# /* ROOST_PP_LIST_CONS */
#
# define ROOST_PP_LIST_CONS(head, tail) (head, tail)
#
# /* ROOST_PP_LIST_NIL */
#
# define ROOST_PP_LIST_NIL ROOST_PP_NIL
#
# /* ROOST_PP_LIST_FIRST */
#
# define ROOST_PP_LIST_FIRST(list) ROOST_PP_LIST_FIRST_D(list)
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_LIST_FIRST_D(list) ROOST_PP_LIST_FIRST_I list
# else
#    define ROOST_PP_LIST_FIRST_D(list) ROOST_PP_LIST_FIRST_I ## list
# endif
#
# define ROOST_PP_LIST_FIRST_I(head, tail) head
#
# /* ROOST_PP_LIST_REST */
#
# define ROOST_PP_LIST_REST(list) ROOST_PP_LIST_REST_D(list)
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_LIST_REST_D(list) ROOST_PP_LIST_REST_I list
# else
#    define ROOST_PP_LIST_REST_D(list) ROOST_PP_LIST_REST_I ## list
# endif
#
# define ROOST_PP_LIST_REST_I(head, tail) tail
#
# /* ROOST_PP_LIST_IS_CONS */
#
# if ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_BCC()
#    define ROOST_PP_LIST_IS_CONS(list) ROOST_PP_LIST_IS_CONS_D(list)
#    define ROOST_PP_LIST_IS_CONS_D(list) ROOST_PP_LIST_IS_CONS_ ## list
#    define ROOST_PP_LIST_IS_CONS_(head, tail) 1
#    define ROOST_PP_LIST_IS_CONS_ROOST_PP_NIL 0
# else
#    define ROOST_PP_LIST_IS_CONS(list) ROOST_PP_IS_BINARY(list)
# endif
#
# /* ROOST_PP_LIST_IS_NIL */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_BCC()
#    define ROOST_PP_LIST_IS_NIL(list) ROOST_PP_COMPL(ROOST_PP_IS_BINARY(list))
# else
#    define ROOST_PP_LIST_IS_NIL(list) ROOST_PP_COMPL(ROOST_PP_LIST_IS_CONS(list))
# endif
#
# endif
