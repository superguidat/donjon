#include		"donjon_master.hh"

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
