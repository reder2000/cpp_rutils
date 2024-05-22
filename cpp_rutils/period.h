#pragma once
#include "enum.h"
#include "require.h"

// Instant represents a "spot" event (like a close)
#define TimeUnit_tuple \
  (Days, Weeks, Months, Years, Hours, Minutes, Seconds, Milliseconds, Microseconds, Instant, invalid)

EMIT_ENUM_CLASS(TimeUnit);

class Period
{
public:
	Period() = default;
	Period(int64_t length, TimeUnit units) : _length(length), _units(units) {}

	[[nodiscard]] int64_t to_seconds() const;
	[[nodiscard]] int64_t to_minutes() const;

	int64_t _length = 0;
	TimeUnit _units = TimeUnit::Days;
};

inline
int64_t Period::to_seconds() const
{
	switch (_units)
	{
	case TimeUnit::Seconds:
		return _length;
	case TimeUnit::Minutes:
		return _length * 60;
	default:
		MFAIL("{} not handled", _units);
	}
}

inline
int64_t Period::to_minutes() const
{
	switch (_units)
	{
	case TimeUnit::Seconds:
		MREQUIRE(_length % 60 == 0, "cannot convert {} to minutes", _length);
		return _length / 60;
	case TimeUnit::Minutes:
		return _length;
	default:
		MFAIL("{} not handled", _units);
	}
}


template <>
struct std__formatter<Period> : formatter<std::string>
{
	// parse is inherited from formatter<string_view>.
	template <typename FormatContext>
	auto format(Period c, FormatContext& ctx) const
	{
          std::string ss = std__format("{} {}", c._length, c._units);
		return formatter<std::string>::format(ss, ctx);
	}
};

