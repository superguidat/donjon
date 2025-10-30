#include	"room.hh"

room		room::splitY(const room	&parent_room,
			     int32_t	checky)
{
  room		subdiv2(parent_room.minsize);

  corner[0].x = parent_room.corner[0].x;
  corner[1].x = parent_room.corner[1].x;
  corner[2].x = parent_room.corner[2].x;
  corner[3].x = parent_room.corner[3].x;
  corner[0].y = checky + SIZE_COULOIR;
  corner[1].y = checky + SIZE_COULOIR;
  corner[2].y = parent_room.corner[2].y;
  corner[3].y = parent_room.corner[3].y;

  subdiv2.corner[0].x = parent_room.corner[0].x;
  subdiv2.corner[1].x = parent_room.corner[1].x;
  subdiv2.corner[2].x = parent_room.corner[2].x;
  subdiv2.corner[3].x = parent_room.corner[3].x;
  subdiv2.corner[0].y = parent_room.corner[0].y;
  subdiv2.corner[1].y = parent_room.corner[1].y;
  subdiv2.corner[2].y = checky;
  subdiv2.corner[3].y = checky;

  return subdiv2;
}
