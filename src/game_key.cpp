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
  return GO_ON;
}
