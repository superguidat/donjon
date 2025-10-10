#include			"donjon_master.hh"

extern "C"

t_bunny_response                game_loop(t_prog			*prog)
{
  if (bunny_get_keyboard()[BKS_LEFT])
    prog->rot += 0.1;
  if (bunny_get_keyboard()[BKS_RIGHT])
    prog->rot -= 0.1;
  if (bunny_get_keyboard()[BKS_UP])
    {
      prog->pos.x += cos(prog->rot);
      prog->pos.y += sin(prog->rot);
    }
  if (bunny_get_keyboard()[BKS_DOWN])
    {
      prog->pos.x -= cos(prog->rot);
      prog->pos.y -= sin(prog->rot);
    }
  if (bunny_get_keyboard()[BKS_Q] || bunny_get_keyboard()[BKS_A])
    {
      // Strafe left
      prog->pos.x += cos(prog->rot + M_PI / 2);
      prog->pos.y += sin(prog->rot + M_PI / 2);
    }
  if (bunny_get_keyboard()[BKS_W])
    {
      // Strafe right
      prog->pos.x += cos(prog->rot - M_PI / 2);
      prog->pos.y += sin(prog->rot - M_PI / 2);
    }

  if (bunny_get_keyboard()[BKS_PAGEUP])
    prog->tilt += 0.02;
  else if (bunny_get_keyboard()[BKS_PAGEDOWN])
    prog->tilt -= 0.02;
  else
    prog->tilt *= 0.97;
   return (GO_ON);
}
