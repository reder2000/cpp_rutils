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
# ifndef ROOST_PREPROCESSOR_DETAIL_CHECK_HPP
# define ROOST_PREPROCESSOR_DETAIL_CHECK_HPP
#
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_CHECK */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_CHECK(x, type) ROOST_PP_CHECK_D(x, type)
# else
#    define ROOST_PP_CHECK(x, type) ROOST_PP_CHECK_OO((x, type))
#    define ROOST_PP_CHECK_OO(par) ROOST_PP_CHECK_D ## par
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC() && ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_DMC()
#    define ROOST_PP_CHECK_D(x, type) ROOST_PP_CHECK_1(ROOST_PP_CAT(ROOST_PP_CHECK_RESULT_, type x))
#    define ROOST_PP_CHECK_1(chk) ROOST_PP_CHECK_2(chk)
#    define ROOST_PP_CHECK_2(res, _) res
# elif ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()
#    define ROOST_PP_CHECK_D(x, type) ROOST_PP_CHECK_1(type x)
#    define ROOST_PP_CHECK_1(chk) ROOST_PP_CHECK_2(chk)
#    define ROOST_PP_CHECK_2(chk) ROOST_PP_CHECK_3((ROOST_PP_CHECK_RESULT_ ## chk))
#    define ROOST_PP_CHECK_3(im) ROOST_PP_CHECK_5(ROOST_PP_CHECK_4 im)
#    define ROOST_PP_CHECK_4(res, _) res
#    define ROOST_PP_CHECK_5(res) res
# else /* DMC */
#    define ROOST_PP_CHECK_D(x, type) ROOST_PP_CHECK_OO((type x))
#    define ROOST_PP_CHECK_OO(par) ROOST_PP_CHECK_0 ## par
#    define ROOST_PP_CHECK_0(chk) ROOST_PP_CHECK_1(ROOST_PP_CAT(ROOST_PP_CHECK_RESULT_, chk))
#    define ROOST_PP_CHECK_1(chk) ROOST_PP_CHECK_2(chk)
#    define ROOST_PP_CHECK_2(res, _) res
# endif
#
# define ROOST_PP_CHECK_RESULT_1 1, ROOST_PP_NIL
#
# endif
