#include		"donjon_master.hh"

void			mouvement(t_prog		&pro)
{
  if (bunny_get_keyboard()[BKS_LEFT])
    pro.rot += 0.1;
  if (bunny_get_keyboard()[BKS_RIGHT])
    pro.rot -= 0.1;
  if (bunny_get_keyboard()[BKS_UP])
    {
      pro.pos.x += cos(pro.rot);
      pro.pos.y += sin(pro.rot);
    }
  if (bunny_get_keyboard()[BKS_DOWN])
    {
      pro.pos.x -= cos(pro.rot);
      pro.pos.y -= sin(pro.rot);
    }
  if (bunny_get_keyboard()[BKS_Q] || bunny_get_keyboard()[BKS_A])
    {
      pro.pos.x += cos(pro.rot + M_PI / 2);
      pro.pos.y += sin(pro.rot + M_PI / 2);
    }
  if (bunny_get_keyboard()[BKS_W])
    {
      pro.pos.x += cos(pro.rot - M_PI / 2);
      pro.pos.y += sin(pro.rot - M_PI / 2);
    }
}
