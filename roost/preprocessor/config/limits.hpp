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
# /* Revised by Edward Diener (2011,2020) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_CONFIG_LIMITS_HPP
# define ROOST_PREPROCESSOR_CONFIG_LIMITS_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# if defined(ROOST_PP_LIMIT_DIM)
# undef ROOST_PP_LIMIT_DIM
# endif
# if defined(ROOST_PP_LIMIT_ITERATION_DIM)
# undef ROOST_PP_LIMIT_ITERATION_DIM
# endif
# if defined(ROOST_PP_LIMIT_SLOT_SIG)
# undef ROOST_PP_LIMIT_SLOT_SIG
# endif
# if defined(ROOST_PP_LIMIT_SLOT_COUNT)
# undef ROOST_PP_LIMIT_SLOT_COUNT
# endif
# if defined(ROOST_PP_LIMIT_WHILE)
# undef ROOST_PP_LIMIT_WHILE
# endif
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_STRICT()
#
# if defined(ROOST_PP_LIMIT_MAG)
# undef ROOST_PP_LIMIT_MAG
# endif
# if defined(ROOST_PP_LIMIT_VARIADIC)
# undef ROOST_PP_LIMIT_VARIADIC
# endif
# if defined(ROOST_PP_LIMIT_TUPLE)
# undef ROOST_PP_LIMIT_TUPLE
# endif
# if defined(ROOST_PP_LIMIT_FOR)
# undef ROOST_PP_LIMIT_FOR
# endif
# if defined(ROOST_PP_LIMIT_REPEAT)
# undef ROOST_PP_LIMIT_REPEAT
# endif
# if defined(ROOST_PP_LIMIT_SEQ)
# undef ROOST_PP_LIMIT_SEQ
# endif
# if defined(ROOST_PP_LIMIT_ITERATION)
# undef ROOST_PP_LIMIT_ITERATION
# endif
#
# define ROOST_PP_LIMIT_MAG 256
# define ROOST_PP_LIMIT_WHILE 256
# define ROOST_PP_LIMIT_VARIADIC 64
# define ROOST_PP_LIMIT_TUPLE 64
# define ROOST_PP_LIMIT_FOR 256
# define ROOST_PP_LIMIT_SEQ 256
# define ROOST_PP_LIMIT_REPEAT 256
# define ROOST_PP_LIMIT_ITERATION 256
#
#else
#
# if defined(ROOST_PP_LIMIT_MAG)
# if !(ROOST_PP_LIMIT_MAG == 256 || ROOST_PP_LIMIT_MAG == 512 || ROOST_PP_LIMIT_MAG == 1024)
# undef ROOST_PP_LIMIT_MAG
# define ROOST_PP_LIMIT_MAG 256
# define ROOST_PP_LIMIT_WHILE 256
# else
# define ROOST_PP_LIMIT_WHILE ROOST_PP_LIMIT_MAG
# if !defined(ROOST_PP_LIMIT_SEQ)
# define ROOST_PP_LIMIT_SEQ ROOST_PP_LIMIT_MAG
# endif
# endif
# else
# define ROOST_PP_LIMIT_MAG 256
# define ROOST_PP_LIMIT_WHILE 256
# endif
#
# if defined(ROOST_PP_LIMIT_VARIADIC)
# if !(ROOST_PP_LIMIT_VARIADIC == 64 || ROOST_PP_LIMIT_VARIADIC == 128 || ROOST_PP_LIMIT_VARIADIC == 256)
# undef ROOST_PP_LIMIT_VARIADIC
# define ROOST_PP_LIMIT_VARIADIC 64
# endif
# else
# define ROOST_PP_LIMIT_VARIADIC 64
# endif
#
# if defined(ROOST_PP_LIMIT_TUPLE)
# if !(ROOST_PP_LIMIT_TUPLE == 64 || ROOST_PP_LIMIT_TUPLE == 128 || ROOST_PP_LIMIT_TUPLE == 256)
# undef ROOST_PP_LIMIT_TUPLE
# define ROOST_PP_LIMIT_TUPLE 64
# elif ROOST_PP_LIMIT_TUPLE > ROOST_PP_LIMIT_VARIADIC
# undef ROOST_PP_LIMIT_VARIADIC
# define ROOST_PP_LIMIT_VARIADIC ROOST_PP_LIMIT_TUPLE
# endif
# else
# define ROOST_PP_LIMIT_TUPLE 64
# endif
#
# if defined(ROOST_PP_LIMIT_FOR)
# if !(ROOST_PP_LIMIT_FOR == 256 || ROOST_PP_LIMIT_FOR == 512 || ROOST_PP_LIMIT_FOR == 1024)
# undef ROOST_PP_LIMIT_FOR
# define ROOST_PP_LIMIT_FOR 256
# elif ROOST_PP_LIMIT_FOR > ROOST_PP_LIMIT_MAG
# undef ROOST_PP_LIMIT_FOR
# define ROOST_PP_LIMIT_FOR ROOST_PP_LIMIT_MAG
# endif
# else
# define ROOST_PP_LIMIT_FOR 256
# endif
#
# if defined(ROOST_PP_LIMIT_REPEAT)
# if !(ROOST_PP_LIMIT_REPEAT == 256 || ROOST_PP_LIMIT_REPEAT == 512 || ROOST_PP_LIMIT_REPEAT == 1024)
# undef ROOST_PP_LIMIT_REPEAT
# define ROOST_PP_LIMIT_REPEAT 256
# elif ROOST_PP_LIMIT_REPEAT > ROOST_PP_LIMIT_MAG
# undef ROOST_PP_LIMIT_REPEAT
# define ROOST_PP_LIMIT_REPEAT ROOST_PP_LIMIT_MAG
# endif
# else
# define ROOST_PP_LIMIT_REPEAT 256
# endif
#
# if defined(ROOST_PP_LIMIT_SEQ)
# if !(ROOST_PP_LIMIT_SEQ == 256 || ROOST_PP_LIMIT_SEQ == 512 || ROOST_PP_LIMIT_SEQ == 1024)
# undef ROOST_PP_LIMIT_SEQ
# define ROOST_PP_LIMIT_SEQ 256
# elif ROOST_PP_LIMIT_SEQ > ROOST_PP_LIMIT_MAG
# undef ROOST_PP_LIMIT_SEQ
# define ROOST_PP_LIMIT_SEQ ROOST_PP_LIMIT_MAG
# endif
# else
# define ROOST_PP_LIMIT_SEQ 256
# endif
#
# if defined(ROOST_PP_LIMIT_ITERATION)
# if !(ROOST_PP_LIMIT_ITERATION == 256 || ROOST_PP_LIMIT_ITERATION == 512 || ROOST_PP_LIMIT_ITERATION == 1024)
# undef ROOST_PP_LIMIT_ITERATION
# define ROOST_PP_LIMIT_ITERATION 256
# elif ROOST_PP_LIMIT_ITERATION > ROOST_PP_LIMIT_MAG
# undef ROOST_PP_LIMIT_ITERATION
# define ROOST_PP_LIMIT_ITERATION ROOST_PP_LIMIT_MAG
# endif
# else
# define ROOST_PP_LIMIT_ITERATION 256
# endif
#
# endif
#
# define ROOST_PP_LIMIT_DIM 3
# define ROOST_PP_LIMIT_ITERATION_DIM 3
# define ROOST_PP_LIMIT_SLOT_SIG 10
# define ROOST_PP_LIMIT_SLOT_COUNT 5
#
# endif
