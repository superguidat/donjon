#include "floor.hh"
#include "room.hh"

void Floor::create_corridor()
{
  int i;
  i = 0;
  while(i < (int)rooms.size())
    {
      room_finder(rooms[i]);
      i++;
    }
  i = 0;
  while(i < (int)rooms.size())
    {
      room_connector(rooms[i]);
      i++;
    }
}
