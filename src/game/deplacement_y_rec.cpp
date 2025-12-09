// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 14:12:56 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			deplacement_y_rec(t_dep				dep,
					  uint8_t			*posi,
					  t_bunny_position		&pos1,
					  t_map				&nmap)
{
  posi[dep.i5] = dep.mv;
  nmap.map[(static_cast<uint32_t>(index_map(nmap.width, pos1.x, pos1.y + dep.av_re)))] = INT_MAX;
  pos1.y += dep.av_re;
}
