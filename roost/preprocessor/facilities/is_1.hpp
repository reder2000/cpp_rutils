# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     Distributed under the Roost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_FACILITIES_IS_1_HPP
# define ROOST_PREPROCESSOR_FACILITIES_IS_1_HPP
#
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/facilities/is_empty.hpp>
#
# /* ROOST_PP_IS_1 */
#
# define ROOST_PP_IS_1(x) ROOST_PP_IS_EMPTY(ROOST_PP_CAT(ROOST_PP_IS_1_HELPER_, x))
# define ROOST_PP_IS_1_HELPER_1
#
# endif
