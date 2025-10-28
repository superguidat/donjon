/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 09/10/2025 12:30:24 ******************************************************
** romain.cescutti <romain.cescutti@laika.efrits.fr>
** - donjon_master -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef __floor_hh_
#define __floor_hh_
#include "tile.hh"
#include "room.hh"
#include <vector>

class Floor
{
 public:
  Floor();
  // private:
  int number;
  double max_height;
  //x and y size;
  int x;
  int y;
  std::vector<room> rooms;
  int special_rooms;
  void subdivide(room parent_room);
};

#endif//	 __FLOOR_HH__
