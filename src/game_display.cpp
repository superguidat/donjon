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

  for (int32_t y = -(prog->height / 2); y < (prog->height / 2); y++)
    {
      for (int32_t x = -(prog->width / 2); x < (prog->width / 2); x++)
	{

	  //haut
	  if (!prog->deb)
	    plafond(*prog, x, y);

	  //bas
	  sol(*prog, x, y, pos);
	}
    }

  bunny_display(prog->win);
  return (GO_ON);
}
