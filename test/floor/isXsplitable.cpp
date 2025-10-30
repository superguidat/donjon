#include		"room.hh"

bool			room::isXSplitable() const
{
  return corner[3].x - corner[0].x > minsize;
}
