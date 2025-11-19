#include			"donjon_master.hh"

double				distance(t_zposition			pos1,
					 t_zposition			pos2)
{
  double			dist;
  double			xd;
  double			yd;

  xd = pos1.x - pos2.x;
  yd = pos1.y - pos2.y;
  xd *= xd;
  yd *= yd;
  dist = sqrt(xd + yd);
  return dist;
}
/*
double				distance(t_zposition			pos1,
					 t_zposition			pos2)
{
  double			xd;
  double			yd;
  double			zd;

  xd = pos1.x - pos2.x;
  yd = pos1.y - pos2.y;
  zd = pos1.z - pos2.z;
  xd *= xd;
  yd *= yd;
  zd *= zd;

  return sqrt(xd + yd + zd);
}
*/
