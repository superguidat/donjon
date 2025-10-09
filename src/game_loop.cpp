#include			"donjon_master.hh"

extern "C"

t_bunny_response                game_loop(t_prog			*prog)
{
   if (bunny_get_keyboard()[BKS_UP])
    {
      ;
    }
   return (GO_ON);
}
