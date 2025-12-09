// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 13:18:51 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			move_units(t_prog		&prog)
{
  int32_t		d;
  t_bunny_position	pos;
  t_move		mv;
  t_map			map;

  fabric_map(map, prog);
  if (map.map == NULL)
    return ;
  for (int16_t i = 0; i < prog.nb_units; i++)
    {
      mv.pnj = &prog.units[i];
      d = distance((t_zposition){.x = mv.pnj->getX(), .y = mv.pnj->getY(), .z = 0},
		   (t_zposition){.x = prog.me.getX(), .y = prog.me.getY(), .z = 0});
      if (d < (mv.pnj->getR() * 10.0))
	continue;
      if (mv.pnj->getMove_type() == 2)
	if (suit_route(pos, mv, prog, map) == 1)
	  continue;
      if (mv.pnj->getMove_type() != 2)
	{
	  if (mv.pnj->getPv() > 30)
	    pos = mv.pnj->pathfinding(&map, *(prog.map2), prog.me.getPos());
	  else
	    pos = mv.pnj->pathfinding(&map, *(prog.map2), mv.pnj->getPosDest());
	  mv.pnj->move(pos.x, pos.y, 0, 0, 2, prog);
	  continue;
	}
    }
}
