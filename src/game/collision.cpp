// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 14:22:05 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

bool		collision(t_bunny_pixelarray	&pix,
			  t_colli		&coll,
			  int32_t		step,
			  t_map			*map)
{
  if (!check_collide_pix(coll, pix)
      && coll.x < (static_cast<int32_t>(map->width)) - (MAX_RAY + MINI_RAY)
      && coll.x > (0 + MAX_RAY + MINI_RAY)
      && coll.y < (static_cast<int32_t>(map->height)) - (MAX_RAY + MINI_RAY)
      && coll.y > (0 + MAX_RAY + MINI_RAY)
      && map->map[(static_cast<uint32_t>(index_map(map->width, coll.x, coll.y)))] != -1
      && map->map[(static_cast<uint32_t>(index_map(map->width, coll.x, coll.y)))] > (step + 1))
    return false;
  return true;
}

