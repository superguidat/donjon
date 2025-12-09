// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 14:08:00 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

t_rec			init_rec_path(t_bunny_position			destination,
				      int32_t				i,
				      int32_t				r,
				      t_map				*nmap)
{
  t_rec			rec;

  rec.i = i;
  rec.r = r;
  rec.destination.x = destination.x;
  rec.destination.y = destination.y;
  rec.map = nmap;
  rec.max_step = MAX_STEP;

  return rec;
}
