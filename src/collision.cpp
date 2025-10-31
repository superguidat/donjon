#include		"donjon_master.hh"

static double		min_dist_point(Tile		&tuil,
				       t_zposition	&cam)
{
  double		mind;
  double		d;
  double		z;

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

bool			collision_me(t_prog		&pro,
				     double		x,
				     double		y)
{
  t_zposition		cam;
  double		z;

  cam.z = pro.me.getPos_cam().z;
  cam.x = x;
  cam.y = y;
  for (int32_t y = 0; y < pro.height; y ++)
    for (int32_t x = 0; x < pro.width; x ++)
      {
	if (check_me_first(cam, pro.bas.tiles[y * pro.width + x]))
	  {
	    z = min_dist_point(pro.bas.tiles[y * pro.width + x], cam);
	    if (cam.z <= z - LIMITE_FRANCHISSEMENT)
	      return true;
	    else
	      return false;
	  }
      }
  return false;
}
