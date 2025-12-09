// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 17/11/2025 12:46:53 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include			"donjon_master.hh"

extern "C"

t_bunny_response		game_entering(t_prog	*pro)
{
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  if (game_texture(pro) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  init_prog_jeu(pro);
  if (reseau_hote_client(pro) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  genere_jeu(pro, 9, 15);
  int id;
  for (int32_t y = 0; y < pro->height; y ++)
    for (int32_t x = 0; x < pro->width; x ++)
      if (pro->me.check_me_tile(pro->bas.tiles[y*pro->width+x]))
	id = pro->bas.tiles[y*pro->width+x].id;
  pro->etage[1].objets[0].tileID = id;
  pro->etage[1].objets[0].textID = pro->def_objets[0].textID;
  pro->etage[1].objets[0].setY(0);
  pro->etage[1].objets[0].setX(0);
  pro->etage[1].objets[0].setDegat(0);
  pro->etage[1].objets[0].setI(0);
  pro->etage[1].nb_objets = 1;

  return GO_ON;
}
