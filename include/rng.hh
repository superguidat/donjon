#pragma once
#include <random>

// déclaration externe
//extern std::mt19937 rng;

uint64_t			rng_stateless(uint64_t		seed,
					      uint64_t		index);
