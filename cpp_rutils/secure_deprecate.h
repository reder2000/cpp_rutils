#pragma once
#include <string>
#include <string.h>
#include "require.h"
#include "config.h"

inline
std::string m_strerror_s(int _ErrorMsg)
{
#if !defined(HAVE_STRERROR_S)
	char buffer[1024];
	const char* s = strerror_r( _ErrorMsg, buffer, 1024);
	if (s==nullptr)
	{
		char buffer[1024 * 64];
		const char* s2 = strerror_r(_ErrorMsg, buffer, 1024);
		MREQUIRE(s2 != nullptr, "cannot allocate enough mem to strerror");
		return s;
	}
	return s;
#else
	char buffer[1024];
	auto failed = strerror_s(buffer, 1024, _ErrorMsg);
	if (failed)
	{
		constexpr size_t size = 1024*64;
		char buffer2[size];
		auto failed_again = strerror_s(buffer2, _ErrorMsg, size);
		MREQUIRE(!failed_again, "cannot allocate enough mem to strerror");
		return buffer2;
	}
	return buffer;
#endif
}

inline
struct tm m_localtime_s(const time_t & tt)
{
	struct tm res;
#if !defined(HAVE_LOCALTIME_S)
	auto err = localtime_r(&tt, &res);
	MREQUIRE(err!=nullptr, "localtime_r failed");
#else
	auto err = localtime_s(&res, &tt);
	MREQUIRE(!err, "localtime_s failed {}", m_strerror_s(err));
#endif
	return res;
}