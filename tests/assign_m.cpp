#include "assign_m.h"

#include <catch2/catch_test_macros.hpp>

namespace {

	struct toto {
		toto(int a, std::shared_ptr<int> b);
		int _a;
		std::shared_ptr<int> _b;
	};

	toto::toto(int a, std::shared_ptr<int> b) : A_(a), AM_(b) {}
}



