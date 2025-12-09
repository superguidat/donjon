// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 11:57:25 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include			"donjon_master.hh"

t_bunny_response		game_texture(t_prog		*pro)
{
  if (charge_texture("./res/texture/sol.png", pro, 0) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  if (charge_texture("./res/texture/ciel.png", pro, 1) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  if (charge_texture("./res/texture/mur_noir.png", pro, 2) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  if (charge_texture("./res/texture/case_inventaire.png", pro, 3) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  if (charge_texture("./res/texture/panneau_droit.png", pro, 4) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  if (charge_texture_obj("./res/texture/mur.png", &pro->def_objets[0].textID) == EXIT_ON_ERROR)
    return EXIT_ON_ERROR;
  return GO_ON;
}
