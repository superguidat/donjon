#include		"donjon_master.hh"

extern "C"
t_bunny_response        game_key(t_bunny_event_state	state,
				 t_bunny_keysym		sym,
				 t_prog			*prog)
{
  if (state == GO_DOWN)
    return GO_ON;
  if (sym == BKS_ESCAPE)
    return EXIT_ON_SUCCESS;
  if (sym == BKS_F1)
    {
      if (prog->ecran == 0)
	prog->ecran = 1;
      else if (prog->ecran == 1)
	prog->ecran = 0;
    }
  if (prog->ecran == 0)
    {
      if (sym == BKS_P)
	{
	  if ((prog->etage_actuel +1) == (prog->nb_etage - 1))
	    prog->etage_actuel = 0;
	  prog->etage_actuel +=1;
	  prog->sous_bas<<prog->etage[prog->etage_actuel-1];
	  prog->bas<<prog->etage[prog->etage_actuel];
	  prog->haut<<prog->etage[prog->etage_actuel+1];
	}
      if (sym == BKS_O)
	{
	  if ((prog->etage_actuel -1) > 0)
	    prog->etage_actuel = (prog->nb_etage - 2);
	  prog->etage_actuel -=1;
	  prog->sous_bas<<prog->etage[prog->etage_actuel-1];
	  prog->bas<<prog->etage[prog->etage_actuel];
	  prog->haut<<prog->etage[prog->etage_actuel+1];
	}
    }
  return GO_ON;
}
