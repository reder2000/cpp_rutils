#pragma once

// assign
#define A_(a) _##a(a)

// assign move
#define AM_(a) _##a(std::move(a))

