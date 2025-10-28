// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 10/10/2025 12:30:53 ******************************************************
// romain.cescutti <romain.cescutti@laika.efrits.fr>
// - donjon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "floor.hh"
#include <lapin.h>
#include <cstdlib>

Floor::Floor()
{
}

bool roomcheck(int roomsize)
{
  float val;
  val = 225 / roomsize;
  if (val == 0)
    return false;
  if(rand()%(int)val)
    return false;
  return true;
}

int roomarea(room R)
{
  int x = R.corner[3].x-R.corner[0].x;
  int y = R.corner[3].y-R.corner[0].y;

  // Solution grosse chiasse.
  if (x == 0)
    {
      std::cout << "alert zero" << std::endl;
      x = 1;
    }
  if (y == 0)
    {
      std::cout << "alert zero" << std::endl;
      y = 1;
    }
  return(x*y);
}

int clamp(int		val,
	  int		min,
	  int		max)
{
  if (val < min)
    return (min);
  if (val > max)
    return (max);
  return (val);
}

void Floor::subdivide(room parent_room)
{
  room subdiv1;
  room subdiv2;
  int checkx;
  int checky;
  int R;
  R= rand()%2;
  if (parent_room.isMinimal())
    {
      rooms.push_back(parent_room);
      return;
    }

  checky = clamp(rand() % (parent_room.corner[3].y - parent_room.corner[0].y), 10, 100) + parent_room.corner[0].y;
  checkx = clamp(rand() % (parent_room.corner[3].x - parent_room.corner[0].x), 10, 100) + parent_room.corner[0].x;

  if(R)
    {
      subdiv1.corner[0].x = checkx;
      subdiv1.corner[1].x = parent_room.corner[1].x;
      subdiv1.corner[2].x = checkx;
      subdiv1.corner[3].x = parent_room.corner[3].x;
      subdiv1.corner[0].y = parent_room.corner[0].y;
      subdiv1.corner[1].y = parent_room.corner[1].y;
      subdiv1.corner[2].y = parent_room.corner[2].y;
      subdiv1.corner[3].y = parent_room.corner[3].y;

      subdiv2.corner[0].x = parent_room.corner[0].x;
      subdiv2.corner[1].x = checkx;
      subdiv2.corner[2].x = parent_room.corner[2].x;
      subdiv2.corner[3].x = checkx;
      subdiv2.corner[0].y = parent_room.corner[0].y;
      subdiv2.corner[1].y = parent_room.corner[1].y;
      subdiv2.corner[2].y = parent_room.corner[2].y;
      subdiv2.corner[3].y = parent_room.corner[3].y;

      if(roomcheck(roomarea(subdiv1)))
	rooms.push_back(subdiv1);
      else
	subdivide(subdiv1);

      if(roomcheck(roomarea(subdiv2)))
	rooms.push_back(subdiv2);
      else
	subdivide(subdiv2);
    }
  else
    {
      subdiv1.corner[0].x = parent_room.corner[0].x;
      subdiv1.corner[1].x = parent_room.corner[1].x;
      subdiv1.corner[2].x = parent_room.corner[2].x;
      subdiv1.corner[3].x = parent_room.corner[3].x;
      subdiv1.corner[0].y = checky;
      subdiv1.corner[1].y = checky;
      subdiv1.corner[2].y = parent_room.corner[2].y;
      subdiv1.corner[3].y = parent_room.corner[3].y;

      subdiv2.corner[0].x = parent_room.corner[0].x;
      subdiv2.corner[1].x = parent_room.corner[1].x;
      subdiv2.corner[2].x = parent_room.corner[2].x;
      subdiv2.corner[3].x = parent_room.corner[3].x;
      subdiv2.corner[0].y = parent_room.corner[0].y;
      subdiv2.corner[1].y = parent_room.corner[1].y;
      subdiv2.corner[2].y = checky;
      subdiv2.corner[3].y = checky;

      if(roomcheck(roomarea(subdiv1)))
	rooms.push_back(subdiv1);
      else
	subdivide(subdiv1);

      if(roomcheck(roomarea(subdiv2)))
	rooms.push_back(subdiv2);
      else
	subdivide(subdiv2);
    }
}
