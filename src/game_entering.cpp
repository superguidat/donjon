#include			"donjon_master.hh"

extern "C"

t_bunny_response		game_entering(t_prog	*pro)
{
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  if (charge_texture("./res/texture/sol.png", pro, 0) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  if (charge_texture("./res/texture/ciel.png", pro, 1) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  if (charge_texture("./res/texture/mur_noir.png", pro, 2) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  pro->tilt = 0;
  pro->rot = 0;

  pro->me.setPos_cam(pro->pos);
  pro->me.setDir_cam((t_zposition){.x = (pro->pos.x + cos(pro->rot)),
				   .y = (pro->pos.y + sin(pro->rot)),
				   .z = 0});
  pro->me.setVec_cam((t_zposition){.x = 0,
				   .y = 0,
				   .z = 1});

  pro->me.setLast_jump_time(-1.0);
  pro->me.setJump_cooldown(JUMP_COOLDOWN);
  pro->me.setJump_force(JUMP_FORCE);
  pro->me.setGravity(GRAVITY);
  pro->me.setIs_jumping(false);
  pro->me.setVertical_speed(0.0);

  //generation d'une carte aleatoire
  pro->height = 20;
  pro->width = 20;
  srand(time(NULL));
  for (int32_t y = 0; y < pro->height; y ++)
    {
      for (int32_t x = 0; x < pro->width; x ++)
	{
	  for (int32_t i = 0; i < 9; i ++)
	    {
	      int r = rand()%5;
	      if ((i == 2
		   || i == 5
		   || i == 8)
		  || i > 5)
		{
		  pro->tiles[y*pro->width+x].setPoint(i, r);
		  pro->tiles_sup[y*pro->width+x].setPoint(i, 15+r);
		}
	      else
		{
		  pro->tiles[y*pro->width+x].setPoint(i, r);
		  pro->tiles_sup[y*pro->width+x].setPoint(i, 15+r);
		}
	    }
	}
    }
  //
  init_tiles(pro);
  init_tiles_sup(pro);
  return GO_ON;
}
