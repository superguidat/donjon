// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 14:11:25 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			deplacement_x_rec(t_dep				dep,
					  uint8_t			*posi,
					  t_bunny_position		&pos1,
					  t_map				&nmap)
{
  posi[dep.i5] = dep.mv;
  nmap.map[(static_cast<uint32_t>(index_map(nmap.width, pos1.x + dep.av_re, pos1.y)))] = INT_MAX;
  pos1.x += dep.av_re;
}
