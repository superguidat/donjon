// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 14:22:53 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

bool		check_collide_pix(t_colli			&co,
				  t_bunny_pixelarray		&pix)
{
  for (int16_t y2 = co.y - co.r; y2 < co.y + co.r; y2 ++)
    {
      for (int16_t x2 = co.x - co.r; x2 < co.x + co.r; x2 ++)
	{
	  if ((reinterpret_cast<uint32_t*>(pix.pixels))
	      [(static_cast<int32_t>(index_map(pix.clipable.buffer.width, x2, y2)))] != INT_MAX
	      && (reinterpret_cast<uint32_t*>(pix.pixels))
	      [(static_cast<int32_t>(index_map(pix.clipable.buffer.width, x2, y2)))] != (static_cast<uint32_t>(co.i)))
	    return true;
	}
    }
  return false;
}
