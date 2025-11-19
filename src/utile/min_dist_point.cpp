// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 17/11/2025 13:34:13 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

double		min_dist_point(Tile		&tuil,
			       t_zposition	&cam)
{
  double	mind;
  double	d;
  double	z;

  mind = distance(cam, tuil.getPos(0));
  for (int32_t i = 0; i < 9; i ++)
    {
      d = distance(cam, tuil.getPos(i));
      if (mind > d)
	{
	  z = tuil.getPoint(i);
	  mind = d;
	}
    }
  return z;
}
