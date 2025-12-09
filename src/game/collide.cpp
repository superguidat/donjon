// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 16:03:46 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include			"donjon_master.hh"

bool				ef::Unit::Collide(const ef::Unit	&u,
						  bool			next_move)
{
  if (next_move)
    {
      ef::Unit			tmp;

      tmp.Init(x + cos(a) * v, y + sin(a) * v);
      tmp.r = r;
      tmp.v = v;
      tmp.a = a;
      return (tmp.Collide(u, false));
    }
  double			total_r;
  double			dist;
  double			xd;
  double			yd;

  double			arbitrary_bullshit = 0;

  total_r = (r + arbitrary_bullshit) + (u.r + arbitrary_bullshit);
  xd = x - u.x;
  yd = y - u.y;
  xd *= xd;
  yd *= yd;
  dist = sqrt(xd + yd);
  return (dist < total_r);
}
