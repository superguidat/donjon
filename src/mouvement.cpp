#include		"donjon_master.hh"

static void		lateraux(t_prog			&pro)
{
  if (bunny_get_keyboard()[BKS_Q] || bunny_get_keyboard()[BKS_A])
    {
      if (!collision_me(pro, pro.pos.x + cos(pro.rot + M_PI / 2),
			pro.pos.y + sin(pro.rot + M_PI / 2)))
	{
	  pro.pos.x += cos(pro.rot + M_PI / 2);
	  pro.pos.y += sin(pro.rot + M_PI / 2);
	}
      else
	pro.pos.z = pro.me.getPos_cam().z;
    }
  if (bunny_get_keyboard()[BKS_W])
    {
      if (!collision_me(pro, pro.pos.x + cos(pro.rot - M_PI / 2),
			pro.pos.y + sin(pro.rot - M_PI / 2)))
	{
	  pro.pos.x += cos(pro.rot - M_PI / 2);
	  pro.pos.y += sin(pro.rot - M_PI / 2);
	}
      else
	pro.pos.z = pro.me.getPos_cam().z;
    }
}

void			mouvement(t_prog		&pro)
{
  if (bunny_get_keyboard()[BKS_LEFT])
    pro.rot += 0.1;
  if (bunny_get_keyboard()[BKS_RIGHT])
    pro.rot -= 0.1;
  if (bunny_get_keyboard()[BKS_UP])
    if (!collision_me(pro, pro.pos.x + cos(pro.rot),
		      pro.pos.y + sin(pro.rot)))
      {
	pro.pos.x += cos(pro.rot);
	pro.pos.y += sin(pro.rot);
      }
    else
      pro.pos.z = pro.me.getPos_cam().z;
  if (bunny_get_keyboard()[BKS_DOWN])
    if (!collision_me(pro, pro.pos.x - cos(pro.rot),
		      pro.pos.y - sin(pro.rot)))
      {
	  pro.pos.x -= cos(pro.rot);
	  pro.pos.y -= sin(pro.rot);
      }
    else
      pro.pos.z = pro.me.getPos_cam().z;
  lateraux(pro);
}
