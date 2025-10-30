#include		"donjon_master.hh"

static void		search_tile_me(t_prog		&pro,
				       t_zposition	&cam,
				       double		&dd,
				       double		&cami)
{
  double		d;
  double		mind;

  cam = pro.me.getPos_cam();
  for (int32_t y = 0; y < pro.height; y ++)
    for (int32_t x = 0; x < pro.width; x ++)
      if (pro.me.check_me_tile(pro.tiles[y*pro.width+x]))
	{
	  mind = distance(cam, pro.tiles[y*pro.width+x].getPos(0));
	  for (int32_t i = 0; i < 9; i ++)
	    {
	      d = distance(cam, pro.tiles[y*pro.width+x].getPos(i));
	      if (mind > d)
		{
		  dd = pro.tiles[y*pro.width+x].getPoint(i);
		  cami = pro.tiles[y*pro.width+x].getPoint(i)+5
		    < cam.z+4 ? -0.1: pro.tiles[y*pro.width+x].getPoint(i)+5
		      > cam.z+4 ? 0.1 : 0;
		  mind = d;
		}
	    }
	}
}

void			saut_graviter(t_prog		&pro)
{
  t_zposition		cam;
  double		cami;
  double		dd;
  double		current_time;
  double		deltaTime;

  cami = INT_MAX;
  dd = INT_MAX;
  current_time = pro.clock.getElapsedTime().asSeconds();
  pro.dt = pro.deltaClock.restart();
  deltaTime = pro.dt.asSeconds();
  search_tile_me(pro, cam, dd, cami);
  if (!pro.me.getIs_jumping()
      && cami != INT_MAX)
    {
      limit_gravity(cam.z, dd, cami);
      pro.me.setPos_cam(cam);
    }
  if (bunny_get_keyboard()[BKS_SPACE])
    {
      pro.me.jump(current_time, dd);
    }
  if (dd != INT_MAX)
    pro.me.update_jump(deltaTime, dd);
}
