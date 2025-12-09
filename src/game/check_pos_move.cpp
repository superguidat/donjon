// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 13:47:44 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

bool		check_pos_move(t_prog		&pro,
			       t_move		&mv,
			       t_bunny_position	pos)
{
  return (!collision_collide(pro, mv)
	  && pos.x >= 0 + (MAX_RAY + MINI_RAY)
	  && pos.y >= 0 + (MAX_RAY + MINI_RAY)
	  && pos.x < pro.map->clipable.buffer.width - (MAX_RAY + MINI_RAY)
	  && pos.y < pro.map->clipable.buffer.height - (MAX_RAY + MINI_RAY));
}
