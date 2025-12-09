// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 15:45:26 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

t_bunny_position	init_check_pos_rec(t_map			&nmap,
					   t_bunny_position		&destination,
					   t_bunny_position		&origin,
					   t_path			&origi)
{
  t_bunny_position	pos1;

  if (nmap.best_pos.x != INT_MAX)
    {
      destination.x = nmap.best_pos.x;
      destination.y = nmap.best_pos.y;
    }
      origin.x = origi.pos.x;
  origin.y = origi.pos.y;
  pos1.x = destination.x;
  pos1.y = destination.y;
  return pos1;
}
