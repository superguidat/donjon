// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 13:23:27 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

void		fabric_map(t_map		&map,
			   t_prog		&pro)
{
  map.width = pro.map2->clipable.buffer.width;
  map.height = pro.map2->clipable.buffer.height;
  if ((map.map = (reinterpret_cast<int32_t*>(malloc(map.height *
						    map.width *
						    sizeof(int32_t))))) == NULL)
    return ;
  for (uint32_t y = 0; y < map.height; y ++)
    {
      for (uint32_t x = 0; x < map.width; x ++)
	{
	  if ((reinterpret_cast<int32_t*>(pro.map2->pixels))
	      [(static_cast<int32_t>(index_map(map.width, x, y)))] != INT_MAX)
	    map.map[(static_cast<int32_t>(index_map(map.width, x, y)))] =
	      (reinterpret_cast<int32_t*>(pro.map2->pixels))
	      [(static_cast<int32_t>(index_map(map.width, x, y)))];
	  else
	    map.map[(static_cast<int32_t>(index_map(map.width, x, y)))] = INT_MAX;
	}
    }
}
