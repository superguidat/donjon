// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 15:20:41 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

static void		search_tile_me(t_prog		&pro,
				       t_zposition	&cam,
				       double		&dd,
				       double		&cami)
{
  double		d;
  double		mind;
  Tile			tuil;

  cam = pro.me.getPos_cam();
  for (int32_t y = 0; y < pro.height; y ++)
    for (int32_t x = 0; x < pro.width; x ++)
      if (pro.me.check_me_tile(pro.bas.tiles[y*pro.width+x]))
	{
	  if (pro.bas.tiles[y*pro.width+x].getType() == 1)
	    tuil = pro.sous_bas.tiles[y*pro.width+x];
	  else
	    tuil = pro.bas.tiles[y*pro.width+x];
	  mind = distance(cam, tuil.getPos(0));
	  //mind = distance(cam, pro.bas.tiles[y*pro.width+x].getPos(0));
	  for (int32_t i = 0; i < 9; i ++)
	    {
	      d = distance(cam, tuil.getPos(i));// pro.bas.tiles[y*pro.width+x].getPos(i));
	      if (mind > d)
		{
		  dd = tuil.getPoint(i);//pro.bas.tiles[y*pro.width+x].getPoint(i);
		  cami = tuil.getPoint(i)+5//pro.bas.tiles[y*pro.width+x].getPoint(i)+5
		    < cam.z+4 ? -0.1: tuil.getPoint(i)+5//pro.bas.tiles[y*pro.width+x].getPoint(i)+5
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
