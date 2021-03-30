# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.                                    *
#  *     Distributed under the Roost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.roost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP
# define ROOST_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_TUPLE_IS_SINGLE_RETURN */
#
# if ROOST_PP_VARIADICS_MSVC
# include <roost/preprocessor/control/iif.hpp>
# include <roost/preprocessor/facilities/is_1.hpp>
# include <roost/preprocessor/tuple/size.hpp>
# define ROOST_PP_TUPLE_IS_SINGLE_RETURN(sr,nsr,tuple)  \
    ROOST_PP_IIF(ROOST_PP_IS_1(ROOST_PP_TUPLE_SIZE(tuple)),sr,nsr) \
    /**/
# endif /* ROOST_PP_VARIADICS_MSVC */
#
# endif /* ROOST_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP */
