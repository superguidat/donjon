// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 13:45:30 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

int32_t			suit_route(t_bunny_position	&pos,
				   t_move		&mv,
				   t_prog		&pro,
				   t_map		&map)
{
  pos = mv.pnj->getPos();
  if (mv.pnj->getT() <= 0)
    {
      mv.pnj->setMove_type(1);
      return 1;
    }
  init_pos_move(pos, mv);

  if (check_pos_move(pro, mv, pos))
    {
      applique_deplacement(pro, mv, map, pos);
      return 1;
    }
  else
    mv.pnj->setMove_type(1);
  return 0;
}
