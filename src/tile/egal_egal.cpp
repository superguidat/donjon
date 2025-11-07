#include		<assert.h>
#include		"tile.hh"

bool			Tile::operator==(const Tile     &other) const
{
  assert(size == other.size);
  assert(type == other.type);
  assert(base_height == other.base_height);
  if (size != other.size)
    return false;
  if (type != other.type)
    return false;
  if (base_height != other.base_height)
    return false;
  for (int32_t i = 0; i < 9; i++)
    {
      assert(points_of_elevation[i] == other.points_of_elevation[i]);
      if (points_of_elevation[i] != other.points_of_elevation[i])
	return false;
      assert(pos[i].x == other.pos[i].x);
      assert(pos[i].y == other.pos[i].y);
      assert(pos[i].z == other.pos[i].z);
      if (pos[i].x != other.pos[i].x
	  || pos[i].y != other.pos[i].y
	  || pos[i].z != other.pos[i].z)
	return false;
    }
  return true;
}
