#include			"floor.hh"

void				Floor::operator=(const Floor     &other)
{
  number = other.number;
  max_height = other.max_height;
  x = other.x;
  y = other.y;
  rooms = other.rooms;
  special_rooms = other.special_rooms;
}
