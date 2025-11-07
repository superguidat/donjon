#include			"donjon_master.hh"

extern "C"

t_bunny_response		game_entering(t_prog	*pro)
{
  //srand(time(NULL));
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
  pro->height = WIDTH_MAP;
  pro->width = HEIGHT_MAP;
  pro->etage_actuel = 0;
  pro->nb_etage = 0;

  int32_t		tab[WIDTH_MAP * HEIGHT_MAP];
  int32_t		h=0;

  for (int32_t m = 0; m < 15; m ++)
    {
      genere_etage(*pro, tab, h);
      genere_floor(pro->width, pro->height, pro->etage[pro->nb_etage-1], tab, h);
      init_tiles(pro, pro->etage[pro->nb_etage-1], pro->nb_etage-1);

      h += 9;

      genere_etage(*pro, tab, h);
      genere_floor(pro->width, pro->height, pro->etage[pro->nb_etage-1], tab, h);
      init_tiles(pro, pro->etage[pro->nb_etage-1], pro->nb_etage-1);

      h += 9;

      std::cout << "\nmap bas = " << m << "   map haut = " << m + 1 << std::endl;
    }

  /*  genere_etage(*pro, tab, 0);
  genere_floor(pro->width, pro->height, pro->etage[0], tab, 0);
  init_tiles(pro, pro->etage[0], 0);
  pro->bas<<pro->etage[0];

  genere_etage(*pro, tab, 9);
  genere_floor(pro->width, pro->height, pro->etage[1], tab, 9);
  init_tiles(pro, pro->etage[1], 1);*/

  pro->bas<<pro->etage[0];
  pro->haut<<pro->etage[1];
  if ((pro->bas == pro->etage[0]) == false)
    std::cout << "\nsa marche pas 0 " << std::endl;
  else
    std::cout << "\ncarte superieur bien charger" << std::endl;
  if ((pro->haut == pro->etage[1]) == false)
    std::cout << "\nsa marche pas 1 " << std::endl;
  else
    std::cout << "\ncarte actuelle bien charger" << std::endl;

  //pro->bas<<pro->etage[0];
  //init_tiles(pro, pro->bas, -1);
  return GO_ON;
}
