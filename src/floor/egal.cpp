#include			"floor.hh"

void				Floor::operator=(const Floor     &other)
{
  number = other.number;
  max_height = other.max_height;
  size.x = other.size.x;
  size.y = other.size.y;
  rooms = other.rooms;
  special_rooms = other.special_rooms;
}
