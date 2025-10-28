#include			"donjon_master.hh"

extern "C"

t_bunny_response                game_loop(t_prog			*prog)
{
  mouvement(*prog);
  if (bunny_get_keyboard()[BKS_PAGEUP])
    prog->pos.z -= 0.02;
  else if (bunny_get_keyboard()[BKS_PAGEDOWN])
    prog->pos.z += 0.02;
  /*  else
    {
      if (prog->me.getPos_cam().z >= 0.001)
	prog->me.appendPos_cam({0, 0, -0.05});
      prog->pos.z *= 0.99;
    }*/
  if (!prog->deb)
    saut_graviter(*prog);
  return (GO_ON);
}
