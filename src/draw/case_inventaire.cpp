// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 14:12:33 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			case_inventaire(t_prog		*prog,
					int32_t		sizex)
{
  t_bunny_position	*posa;
  t_zposition		posm;

  for (int32_t y = 4; y + sizex < (prog->win->buffer.height); y += sizex+4)
    {
      for (int32_t x = 4; x + sizex < (prog->win->buffer.width-404); x += sizex+4)
	{
	  posm.x = x;
	  posm.y = y;
	  posm.z = 0;
	  posa = (const_cast<t_bunny_position*>(bunny_get_mouse_position()));
	  posa->x = posa->x % prog->win->buffer.width;
	  posa->y = posa->y % prog->win->buffer.height;
	  if (posa->x >= posm.x && posa->x <= posm.x+sizex
	      && posa->y >= posm.y && posa->y <= posm.y+sizex)
	    set_carre(posm, *prog, sizex, 1);
	  else
	    set_carre(posm, *prog, sizex, 3);
	}
    }
}
