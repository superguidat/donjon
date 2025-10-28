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

class room
{
 public:
  room();
  room(int x1,int x2, int y1 , int y2);
  room(t_bunny_area area) : room(area.x, area.x + area.w, area.y, area.y + area.h) {}
  tile* tiles;
  t_bunny_position corner[4];
  bool isMinimal();
};

#endif//    __ROOM_HH__
