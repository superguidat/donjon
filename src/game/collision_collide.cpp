// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 13:48:35 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

bool			collision_collide(t_prog		&pro,
					  t_move		&mv)
{
  for (int16_t l = 0; l < pro.nb_units; l++)
    {
      ef::Unit		tmp;
      tmp.setX(mv.pnj->getX());
      tmp.setY(mv.pnj->getY());
      if (tmp.Collide(pro.units[l], false))
	{
	  mv.pnj->setMove_type(1);
	  return true;
	}
    }
  return false;
}
