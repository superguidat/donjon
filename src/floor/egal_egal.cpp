#include		<assert.h>
#include		"floor.hh"

bool			Floor::operator==(const Floor		&other) const
{
  if (number != other.number
      || max_height != other.max_height
      || size.x != other.size.x
      || size.y != other.size.y
      || special_rooms != other.special_rooms)
    return false;
   for (int32_t l = 0; l < other.number; l ++)
     if ((rooms[l] == other.rooms[l]) == false)
       return false;
   return true;
}
