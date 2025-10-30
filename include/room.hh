// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 09/10/2025 17:17:58 ******************************************************
// romain.cescutti <romain.cescutti@laika.efrits.fr>
// - donjon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef __room_hh__
#define __room_hh__
#include <lapin.h>
#include "tile.hh"

#define			SIZE_COULOIR	1

class room
{
 public:
  room(void) = delete;
  room(int		minsize);
  room(int		x1,
       int		x2,
       int		y1,
       int		y2,
       int		minsize = 100);
  //  room(t_bunny_area	area) : room(area.x, area.x + area.w, area.y, area.y + area.h) {;}

  unsigned int		color;
  bool			isMinimal()	const; // A priori, inutile vu les nouveaux concepts.
  bool			isXSplitable()	const;
  bool			isYSplitable()	const;
  room			splitY(const room &parent_room,
			       int32_t	checky);
  room			splitX(const room &parent_room,
			       int32_t	checkx);

  Tile*			tiles;
  t_bunny_position	corner[4];
  int			minsize;
};

#endif//    __ROOM_HH__
