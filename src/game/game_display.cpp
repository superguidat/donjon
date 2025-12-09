// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 17/11/2025 12:47:41 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

extern "C"
t_bunny_response        game_display(t_prog				*prog)
{
  t_bunny_color		col;
  t_zposition		pos[30];
  t_zposition		posm;

  posm = prog->pos;
  if (!prog->deb)
    posm.z = prog->me.getPos_cam().z;
  prog->me.setPos_cam(posm);
  if (!prog->deb)
    prog->me.setDir_cam((t_zposition){.x = (prog->pos.x + cos(prog->rot)),
				      .y = (prog->pos.y + sin(prog->rot)),
				      .z = prog->me.getPos_cam().z});
  else
    prog->me.setDir_cam((t_zposition){.x = (prog->pos.x + cos(prog->rot)),
				      .y = (prog->pos.y + sin(prog->rot)),
				      .z = 249});
  move_cam(prog->me.getPos_cam(), prog->me.getDir_cam(), prog->me.getVec_cam(), prog->ecran);

  if (prog->ecran == 0)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      col.full = BLACK;
      clear_img(col);
      //write(1, "\e[H\e[2J", 7);
      for (int32_t y = -(prog->height / 2); y < (prog->height / 2); y++)
	{
	  //write(1, "\n", 1);
	  for (int32_t x = -(prog->width / 2); x < (prog->width / 2); x++)
	    affiche_3etage(x, y, prog, pos);
	}
      for (int32_t i = 0 ; i < prog->etage[prog->etage_actuel].nb_objets; i ++)
	{
	  sf::Time	delta = prog->clock.getElapsedTime();
	  double	z;

	  posm.x = prog->bas.tiles[prog->etage[prog->etage_actuel].objets[i].tileID].x + prog->etage[prog->etage_actuel].objets[i].getX();
	  posm.y = prog->bas.tiles[prog->etage[prog->etage_actuel].objets[i].tileID].y + prog->etage[prog->etage_actuel].objets[i].getY();
	  posm.z = min_dist_point(prog->bas.tiles[prog->etage[prog->etage_actuel].objets[i].tileID], posm) + -((static_cast<int32_t>(prog->bas.max_height/2))+1);
	  z = posm.z;
	  posm.z = computeLevitation(delta, z, 2, 1);
	  if (posm.z < z)
	    posm.z = z;
	  draw_cube_texture(0, posm, 1, prog->etage[prog->etage_actuel].objets[i].textID);
	}
      draw_joueur(prog);
    }
  if (prog->ecran == 1)
    {
      glClearColor(0.2, 0.2, 0.2, 1.0);
      glClear(GL_COLOR_BUFFER_BIT);
      right_panel(prog);
      int32_t sizex = (prog->win->buffer.width - 404) / 20;
      case_inventaire(prog, sizex);
    }
  bunny_display(prog->win);
  return (GO_ON);
}
