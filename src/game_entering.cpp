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
  pro->height = WIDTH_MAP;
  pro->width = HEIGHT_MAP;
  //srand(time(NULL));

  t_bunny_position Rcorner[5];
  Floor mfloor;
  room tempFloorroom(0, pro->width, 0, pro->height, 7);
  int i;
  int j;
  uint32_t			tab[WIDTH_MAP * HEIGHT_MAP];

  srand(time(NULL));
  i = 0;

  mfloor.subdivide(tempFloorroom, 100);
  j = mfloor.rooms.size();

  for (int32_t y = 0; y < pro->height; y ++)
    for (int32_t x = 0; x < pro->width; x ++)
      tab[y*pro->width+x] = 0;

  while(i < j)
    {
      Rcorner[0] = mfloor.rooms[i].corner[0];
      Rcorner[1] = mfloor.rooms[i].corner[1];
      Rcorner[2] = mfloor.rooms[i].corner[3];
      Rcorner[3] = mfloor.rooms[i].corner[2];
      Rcorner[4] = mfloor.rooms[i].corner[0];
      for (int32_t y2 = Rcorner[0].y; y2 < Rcorner[2].y; y2 ++)
	for (int32_t x2 = Rcorner[0].x; x2 < Rcorner[1].x; x2 ++)
	  if (x2 == Rcorner[0].x
	      || x2 == Rcorner[1].x-1
	      || y2 == Rcorner[0].y
	      || y2 == Rcorner[2].y-1)
	    tab[y2*pro->width+x2] = 1;
      i++;
    }
  std::cout << "largeur de la carte : " << pro->width << "\nhauteur de la carte : " << pro->height << std::endl;
  for (int32_t y = 0; y < pro->height; y ++)
    {
      write(1, "\n", 1);
      for (int32_t x = 0; x < pro->width; x ++)
	{
	  double h = 0;
	  if (tab[y*pro->width + x] == 1)
	    {
	      write(1, " #", 2);
	      h = 9;
	    }
	  else
	    {
	      write(1, "  ", 2);
	      h = 0;
	    }
	  for (int32_t li = 0; li < 9; li ++)
	    {
	      int r = rand()%5;
	      pro->bas.tiles[y*pro->width+x].setPoint(li, h);
	      pro->haut.tiles[y*pro->width+x].setPoint(li, 15+r);
	    }
	}
    }
  //
  init_tiles(pro);
  init_tiles_sup(pro);
  return GO_ON;
}
