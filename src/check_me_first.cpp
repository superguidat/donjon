#include	"donjon_master.hh"

bool		check_me_first(t_zposition	&pos,
			       Tile		&tuil)
{
  if (pos.x > tuil.getPos(0).x
      && pos.y > tuil.getPos(0).y
      && pos.x < tuil.getPos(2).x
      && pos.y < tuil.getPos(6).y)
    return true;//je suis sur la tuile
  return false;//je ne suis pas sur la tuile
}
