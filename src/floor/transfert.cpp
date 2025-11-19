#include		"floor.hh"

void			Floor::operator<<(const Floor	&other)
{
  number = other.number;
  max_height = other.max_height;
  x = other.x;
  y = other.y;
  rooms.resize(other.rooms.size());
  special_rooms = other.special_rooms;
  for (int32_t li = 0; li < WIDTH_MAP * HEIGHT_MAP; li++)
    tiles[li] = other.tiles[li];
  for (int32_t l = 0; l < static_cast<int32_t>(other.rooms.size()); l ++)
    rooms[l] = other.rooms[l];
}
