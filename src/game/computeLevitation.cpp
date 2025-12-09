// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 25/11/2025 10:58:40 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

double			computeLevitation(const sf::Time		&passer,
					  double			z,
					  double			speed,
					  double			amp)
{
  float			t;

  t = passer.asSeconds();
  float minZ = z;
  float maxZ = z + amp;
  float zz = minZ + (std::sin(t * speed) * 0.5f + 0.5f) * (maxZ - minZ);

  return zz;
}
