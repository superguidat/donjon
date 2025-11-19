#include		<assert.h>
#include		"room.hh"

bool			room::operator==(const room		&other) const
{
  if (w != other.w
      || h != other.h
      || minsize != other.minsize
      || corner[0].x != other.corner[0].x
      || corner[0].y != other.corner[0].y
      || corner[1].x != other.corner[1].x
      || corner[1].y != other.corner[1].y
      || corner[2].x != other.corner[2].x
      || corner[2].y != other.corner[2].y
      || corner[3].x != other.corner[3].x
      || corner[3].y != other.corner[3].y
      || tiles.size() != other.tiles.size())
    return false;
  for (int32_t i = 0; i < static_cast<int32_t>(other.tiles.size()); i ++)
    {
      assert(tiles[i]==other.tiles[i]);
      if ((tiles[i]==other.tiles[i]) == false)
	return false;
    }
  return true;
}
