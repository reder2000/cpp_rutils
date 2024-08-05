#include "user_path.h"

#include "format.h"

TEST(cpp_rutils,user_path) {
		auto foo = get_home_path();
	std__print("{}", foo);
}