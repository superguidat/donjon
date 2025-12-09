// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 14:07:51 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

void		right_panel(t_prog		*prog)
{
  t_zposition	posz[3];

  posz[0].x = prog->win->buffer.width-400;
  posz[0].y = 0;
  posz[0].z = 0;
  posz[1].x = prog->win->buffer.width;
  posz[1].y = 0;
  posz[1].z = 0;
  posz[2].x = prog->win->buffer.width-400;
  posz[2].y = prog->win->buffer.height;
  posz[2].z = 0;
  set_triangle_text(posz, prog->textureID[4]);
  posz[0].x = prog->win->buffer.width;
  posz[0].y = 0;
  posz[0].z = 0;
  posz[1].x = prog->win->buffer.width;
  posz[1].y = prog->win->buffer.height;
  posz[1].z = 0;
  posz[2].x = prog->win->buffer.width-400;
  posz[2].y = prog->win->buffer.height;
  posz[2].z = 0;
  set_triangle_text(posz , prog->textureID[4]);
}
