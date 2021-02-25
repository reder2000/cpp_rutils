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
# /* Revised by Edward Diener (2015) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_FACILITIES_IDENTITY_HPP
# define ROOST_PREPROCESSOR_FACILITIES_IDENTITY_HPP
#
# include <roost/preprocessor/facilities/empty.hpp>
# include <roost/preprocessor/tuple/eat.hpp>
#
# /* ROOST_PP_IDENTITY */
#
# define ROOST_PP_IDENTITY(item) item ROOST_PP_EMPTY
#
# define ROOST_PP_IDENTITY_N(item,n) item ROOST_PP_TUPLE_EAT_N(n)
#
# endif
