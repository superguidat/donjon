#include			"donjon_master.hh"

extern "C"
t_bunny_response		game_entering(t_prog	*pro)
{
  pro->pos.x = -5;
  pro->pos.y = 0;
  pro->tilt = 0;
  pro->rot = 0;

  return GO_ON;
}
