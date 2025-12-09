// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 11:56:15 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include			<rng.hh>
#include			<ctime>
#include			<stdint.h>

//std::mt19937			rng(static_cast<unsigned int>(time(nullptr)));

static uint64_t			splitmix64(uint64_t		x)
{
  x += 0x9E3779B97F4A7C15ULL;
  x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9ULL;
  x = (x ^ (x >> 27)) * 0x94D049BB133111EBULL;
  return x ^ (x >> 31);
}

uint64_t			rng_stateless(uint64_t		seed,
					      uint64_t		index)
{
    return splitmix64(seed + index * 0x9E3779B97F4A7C15ULL);
}
