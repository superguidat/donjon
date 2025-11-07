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
  if (sym == BKS_P)
    {
      int f=(rand()%(prog->nb_etage-1));
      prog->etage_actuel +=1;
      prog->bas<<prog->etage[prog->etage_actuel];
      prog->haut<<prog->etage[prog->etage_actuel+1];
    }
  if (sym == BKS_O)
    {
      int f=(rand()%(prog->nb_etage-1));
      prog->etage_actuel -=1;
      prog->bas<<prog->etage[prog->etage_actuel];
      prog->haut<<prog->etage[prog->etage_actuel+1];
    }
  return GO_ON;
}
