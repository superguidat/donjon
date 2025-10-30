#include	"room.hh"

room		room::splitX(const room	&parent_room,
			     int32_t	checkx)
{
  room		subdiv2(parent_room.minsize);

  corner[0].x = checkx + SIZE_COULOIR;
  corner[1].x = parent_room.corner[1].x;
  corner[2].x = checkx + SIZE_COULOIR;
  corner[3].x = parent_room.corner[3].x;
  corner[0].y = parent_room.corner[0].y;
  corner[1].y = parent_room.corner[1].y;
  corner[2].y = parent_room.corner[2].y;
  corner[3].y = parent_room.corner[3].y;

  subdiv2.corner[0].x = parent_room.corner[0].x;
  subdiv2.corner[1].x = checkx;
  subdiv2.corner[2].x = parent_room.corner[2].x;
  subdiv2.corner[3].x = checkx;
  subdiv2.corner[0].y = parent_room.corner[0].y;
  subdiv2.corner[1].y = parent_room.corner[1].y;
  subdiv2.corner[2].y = parent_room.corner[2].y;
  subdiv2.corner[3].y = parent_room.corner[3].y;

  return subdiv2;
}
