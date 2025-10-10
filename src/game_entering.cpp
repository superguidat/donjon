#include			"donjon_master.hh"

extern "C"
t_bunny_response		game_entering(t_prog	*pro)
{
  pro->pos.x = -5;
  pro->pos.y = 0;
  pro->pos.z = 0;
  pro->tilt = 0;
  pro->rot = 0;

  pro->me.setPos_cam(pro->pos);
  pro->me.setDir_cam((t_zposition){.x = (pro->pos.x + cos(pro->rot)),
				   .y = (pro->pos.y + sin(pro->rot)),
				   .z = 0});
  pro->me.setVec_cam((t_zposition){.x = 0,
				   .y = 0,
				   .z = 1});

  for (int32_t y = 0; y < 100; y ++)
    {
      for (int32_t x = 0; x < 100; x ++)
	{
	  for (int32_t i = 0; i < 9; i ++)
	    pro->tiles[y*100+x].setPoint(i, 0);
	}
    }

  return GO_ON;
}
