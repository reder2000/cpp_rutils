#include "stdafx.h"

#pragma warning(1: 4996)

#include <secure_deprecate.h>

#include <iostream>

#pragma warning(1: 4996)

TEST(cpp_rutils,secure_deprecate_strerror)
{
	std::cout << m_strerror_s(0) << std::endl;
	
}

TEST(cpp_rutils,secure_deprecate_localtime)
{
	time_t tt;
	time(&tt);
	m_localtime_s(tt);
}