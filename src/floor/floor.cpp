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

//#define KEEP_TMP_SHAPE
#ifdef KEEP_TMP_SHAPE
# define TST(a)
#else
# define TST(a) a
#endif

void Floor::subdivide(room parent_room, int max)
{
  room subdiv1(parent_room.minsize);
  room subdiv2(parent_room.minsize);
  int checkx;
  int checky;
  int R;

  if ((!parent_room.isXSplitable() && !parent_room.isYSplitable())
      || parent_room.isMinimal() || max == 0)
    {
      TST(rooms.push_back(parent_room));
      return;
    }

  // Remplacer ca par un découpage variant entre 25 et 75% de la dimension considéré comme découpable
  double d = ((rand() % 51) + 25.0) / 100.0;
  checky = d * (parent_room.corner[3].y - parent_room.corner[0].y);
  checkx = d * (parent_room.corner[3].x - parent_room.corner[0].x);
  // Une dimension découpable doit pouvoir etre découpée, meme si l'autre dimension n'est pas découpable.

  if (checky <= checkx && parent_room.isYSplitable())
    R = 2;
  else if (checkx >= checky && parent_room.isXSplitable())
    R = 0;
  else
    {
      // R = rand() % 2 ? 2 : 0;
      R = 0;
    }
  checky += parent_room.corner[0].y;
  checkx += parent_room.corner[0].x;
  if(R > 1)
    {
      subdiv2 = subdiv1.splitX(parent_room, checkx);
      // Subdivise horizontalement?

      TST(if(roomcheck(roomarea(subdiv1))))
	rooms.push_back(subdiv1);
      TST(else)
	subdivide(subdiv1, max - 1);

      TST(if(roomcheck(roomarea(subdiv2))))
	rooms.push_back(subdiv2);
      TST(else)
	subdivide(subdiv2, max - 1);
    }
  else
    {
      // Subdivise verticalement?
      subdiv2 = subdiv1.splitY(parent_room, checky);

      TST(if(roomcheck(roomarea(subdiv1))))
      rooms.push_back(subdiv1);
      TST(else)
	subdivide(subdiv1, max - 1);

      TST(if(roomcheck(roomarea(subdiv2))))
	rooms.push_back(subdiv2);
      TST(else)
	subdivide(subdiv2, max - 1);
    }
}
