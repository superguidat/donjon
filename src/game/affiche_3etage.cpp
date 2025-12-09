#include		"donjon_master.hh"

void			affiche_3etage(int32_t				x,
				       int32_t				y,
				       t_prog				*prog,
				       t_zposition		        *pos)
{
  t_sol			soll;
  t_zposition		zp;

  zp = prog->bas.tiles[(y+prog->height/2)*prog->width + ((x)+prog->width/2)].pos[0];
  prog->pos.x -= (cos(prog->rot)*20);
  prog->pos.y -= (sin(prog->rot)*20);
  if (dans_champ(*prog, x, y)
      && distance(prog->me.getPos_cam(), zp) < 1000)
    {/*
       if (prog->tab[(y + (prog->height / 2)) * (prog->width / 2) + (x + (prog->width / 2))] == 1)
       write(1, "#", 1);
       else
       write(1, "  ", 1);*/
      if (!prog->deb)
	{
	  soll = t_sol{prog, &prog->haut, x, y, pos, (static_cast<int8_t>(prog->etage_actuel+1))};
	  sol(soll, 1, 1);
	}
      soll = t_sol{prog, &prog->bas, x, y, pos, (static_cast<int8_t>(prog->etage_actuel))};
      sol(soll, 0, 2);
      if (!prog->deb)
	{
	  soll = t_sol{prog, &prog->sous_bas, x, y, pos, (static_cast<int8_t>(prog->etage_actuel-1))};
	  sol(soll, 0, 2);
	}
    }
  t_zposition sie;

  t_zposition temp = prog->pos;
  temp.x += 0;//(cos(prog->rot)*40);
  temp.y += 0;//(sin(prog->rot)*40);
  temp.z -=5;
  sie.x=1;
  sie.y=1;
  sie.z=7;
  draw_pave_texture(0, temp, sie, 0);
  prog->pos.x += (cos(prog->rot)*20);
  prog->pos.y += (sin(prog->rot)*20);
}
