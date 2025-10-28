#include	"donjon_master.hh"

bool		ef::Unit::check_me_tile(Tile		&tuil)
{
  if (pos_cam.x > tuil.getPos(0).x
      && pos_cam.y > tuil.getPos(0).y
      && pos_cam.x < tuil.getPos(2).x
      && pos_cam.y < tuil.getPos(6).y)
    return true;//je suis sur la tuile
  return false;//je ne suis pas sur la tuile
}
