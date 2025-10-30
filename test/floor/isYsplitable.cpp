#include		"room.hh"

bool			room::isYSplitable() const
{
  int			sizey;

  sizey = corner[3].y - corner[0].y;
  if (sizey < minsize)
    return false;
  return true;
}
