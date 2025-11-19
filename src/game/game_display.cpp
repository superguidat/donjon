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

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
  move_cam(prog->me.getPos_cam(), prog->me.getDir_cam(), prog->me.getVec_cam());

  col.full = BLACK;
  clear_img(col);

  if (prog->ecran == 0)
    {
      //write(1, "\e[H\e[2J", 7);
      for (int32_t y = -(prog->height / 2); y < (prog->height / 2); y++)
	{
	  //write(1, "\n", 1);
	  for (int32_t x = -(prog->width / 2); x < (prog->width / 2); x++)
	    affiche_3etage(x, y, prog, pos);
	}
      for (int32_t i = 0 ; i < prog->etage[prog->etage_actuel].nb_objets; i ++)
	{
	  prog->etage[prog->etage_actuel].objets[i];
	  posm.x = prog->bas.tiles[prog->etage[prog->etage_actuel].objets[i].tileID].x + prog->etage[prog->etage_actuel].objets[i].getX();
	  posm.y = prog->bas.tiles[prog->etage[prog->etage_actuel].objets[i].tileID].y + prog->etage[prog->etage_actuel].objets[i].getY();
	  posm.z = min_dist_point(prog->bas.tiles[prog->etage[prog->etage_actuel].objets[i].tileID], posm) + 2;
	  draw_cube_texture(posm, 10, prog->etage[prog->etage_actuel].objets[i].textID);
	}
    }
  if (prog->ecran == 1)
    {
      int32_t maxx = prog->win->buffer.width / 20;
      int32_t maxy = prog->win->buffer.height / 20;
      for (int32_t y = 4; y + 20 < maxy - 4; y += 4)
	{
	  for (int32_t x = 4; x + 20 < maxx - 4; x += 4)
	    {
	      posm.x = x;
	      posm.y = y;
	      posm.z = 0;
	      set_carre(posm, *prog, 20, 0);
	    }
	}
    }

  bunny_display(prog->win);
  return (GO_ON);
}
