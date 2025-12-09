// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 16:07:04 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			ef::Unit::move(double				_x,
				       double				_y,
				       double				_a,
				       uint32_t				_color,
				       int32_t				move,
				       t_prog				&pro)
{
  t_colli		coll;
  bool			colli;

  coll.x = _x;
  coll.y = _y;
  coll.r = r;
  coll.i = i;
  colli = check_collide_pix(coll, *(pro.map2));

  if (!colli
      && _x >= 0 + (MAX_RAY + MINI_RAY)
      && _y >= 0 + (MAX_RAY + MINI_RAY)
      && _x < pro.map->clipable.buffer.width - (MAX_RAY + MINI_RAY)
      && _y < pro.map->clipable.buffer.height - (MAX_RAY + MINI_RAY))
    {
      set_carre_pix(pro.map2, *this, INT_MAX);
      x = _x;
      y = _y;
      a = _a;
      color = _color;
      set_carre_pix(pro.map2, *this, i);
      move_type = move;
    }
}
