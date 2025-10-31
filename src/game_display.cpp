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

  //write(1, "\e[H\e[2J", 7);
  for (int32_t y = -(prog->height / 2); y < (prog->height / 2); y++)
    {
      //write(1, "\n", 1);
      for (int32_t x = -(prog->width / 2); x < (prog->width / 2); x++)
	{
	  prog->pos.x -= (cos(prog->rot)*20);
	  prog->pos.y -= (sin(prog->rot)*20);
	  if (dans_champ(*prog, x, y))
	    {/*
	      if (prog->tab[(y + (prog->height / 2)) * (prog->width / 2) + (x + (prog->width / 2))] == 1)
		write(1, "#", 1);
	      else
		write(1, "  ", 1);*/
	      if (!prog->deb)
		plafond(*prog, x, y);
	      sol(*prog, x, y, pos);
	    }
	  prog->pos.x += (cos(prog->rot)*20);
	  prog->pos.y += (sin(prog->rot)*20);
	}
    }

  bunny_display(prog->win);
  return (GO_ON);
}
