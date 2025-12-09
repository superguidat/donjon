// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 14:03:59 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

t_map		init_map(t_map					*map,
			 int32_t				i)
{
  t_map			nmap;

  if ((nmap.map = (reinterpret_cast<int32_t*>(malloc(sizeof(*nmap.map)
						     * map->width
						     * map->height)))) == NULL)
    return nmap;
  nmap.width = map->width;
  nmap.height = map->height;
  memcpy(nmap.map, map->map, sizeof(*nmap.map) * map->width * map->height);
  for (int32_t j = 0; j < (static_cast<int32_t>(nmap.height)); j++)
    {
      for (int32_t l = 0; l < (static_cast<int32_t>(nmap.width)); l++)
	{
	  if (nmap.map[(static_cast<uint32_t>(index_map(nmap.width, l, j)))] == i)
	    nmap.map[(static_cast<uint32_t>(index_map(nmap.width, l, j)))] = INT_MAX;
	  else if (nmap.map[(static_cast<uint32_t>(index_map(nmap.width, l, j)))] != -1
		   && nmap.map[(static_cast<uint32_t>(index_map(nmap.width, l, j)))] != INT_MAX)
	    nmap.map[(static_cast<uint32_t>(index_map(nmap.width, l, j)))] = -1;
	}
    }
  nmap.dist = INT_MAX;
  nmap.best_pos.x = INT_MAX;
  nmap.best_pos.y = INT_MAX;
  return nmap;
}
