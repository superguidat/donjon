#include		"donjon_master.hh"

void			affiche_3etage(int32_t				x,
				       int32_t				y,
				       t_prog				*prog,
				       t_zposition		        *pos)
{
  t_sol			soll;

  prog->pos.x -= (cos(prog->rot)*20);
  prog->pos.y -= (sin(prog->rot)*20);
  if (dans_champ(*prog, x, y))
    {/*
       if (prog->tab[(y + (prog->height / 2)) * (prog->width / 2) + (x + (prog->width / 2))] == 1)
       write(1, "#", 1);
       else
       write(1, "  ", 1);*/
      if (!prog->deb)
	{
	  soll = t_sol{prog, &prog->haut, x, y, pos, prog->etage_actuel+1};
	  sol(soll, 1, 1);
	}
      soll = t_sol{prog, &prog->bas, x, y, pos, prog->etage_actuel};
      sol(soll, 0, 2);
      if (!prog->deb)
	{
	  soll = t_sol{prog, &prog->sous_bas, x, y, pos, prog->etage_actuel-1};
	  sol(soll, 0, 2);
	}
    }
  prog->pos.x += (cos(prog->rot)*20);
  prog->pos.y += (sin(prog->rot)*20);
}
