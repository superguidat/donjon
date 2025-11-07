#include			"tile.hh"

void				Tile::operator=(const Tile     &other)
{
  size = other.size;
  type = other.type;
  x = other.x;
  y = other.y;
  id = other.id;
  base_height = other.base_height;
  for (int32_t i = 0; i < 9; i++)
    {
      points_of_elevation[i] = other.points_of_elevation[i];
      pos[i].x = other.pos[i].x;
      pos[i].y = other.pos[i].y;
      pos[i].z = other.pos[i].z;
    }
}
