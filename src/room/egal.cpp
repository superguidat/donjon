#include			"room.hh"

void				room::operator=(const room     &other)
{
  w = other.w;
  h = other.h;
  minsize = other.minsize;
  corner[0] = other.corner[0];
  corner[1] = other.corner[1];
  corner[2] = other.corner[2];
  corner[3] = other.corner[3];
  tiles.resize(other.tiles.size());
  for (int32_t i = 0; i < other.tiles.size(); i ++)
    tiles[i] = other.tiles[i];
}
