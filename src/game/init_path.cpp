// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 14:28:01 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			init_pat(t_path			&pat,
				 t_colli		&coll,
				 t_bunny_position	&destination)
{
  pat.pos.x = coll.x;
  pat.pos.y = coll.y;
  pat.blk = true;
  pat.dist = distance((t_zposition){.x = (static_cast<double>(coll.x)),
				    .y = (static_cast<double>(coll.y)),
				    .z = 0},
    (t_zposition){.x = (static_cast<double>(destination.x)),
		  .y = (static_cast<double>(destination.y))
		  , .z = 0});
}
