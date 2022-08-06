#pragma once
#include <string>
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
		char rebuffer[1024 * 16];
		const char* s2 = strerror_r(_ErrorMsg, rebuffer, 1024);
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
	struct tm res {};
#if !defined(HAVE_LOCALTIME_S)
	auto err = localtime_r(&tt, &res);
	MREQUIRE(err!=nullptr, "localtime_r failed");
#else
	auto err = localtime_s(&res, &tt);
	MREQUIRE(!err, "localtime_s failed {}", m_strerror_s(err));
#endif
	return res;
}

inline std::string  m_getenv_s(const std::string var) {
#if defined(HAVE_GETENV_S)
	size_t requiredSize;
	getenv_s(&requiredSize, NULL, 0, var.c_str());
	MREQUIRE(requiredSize != 0, "variable{} does not exist",var);
	constexpr size_t buffer_size = 1024;
	MREQUIRE_LESS_EQUAL(requiredSize, buffer_size);
	char buffer[buffer_size];
	getenv_s(&requiredSize, buffer, var.c_str());
	return std::string(buffer, requiredSize-1); // string must not be 0-terminated
#else
	return getenv(var.c_str());
#endif
}