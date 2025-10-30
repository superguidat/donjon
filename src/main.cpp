#include	"donjon_master.hh"

extern "C" {
  bunny_declare_context(game);
}

t_prog			*charge_prog()
{
  t_prog		*pro;

  pro = new t_prog;
  if ((pro->win = bunny_start_style(WIDTH, HEIGHT, (t_bunny_window_style)(DEFAULT_WIN_STYLE | DEPTH_BUFFER), "Dungeon Master")) == NULL)
    {
      delete pro;
      return NULL;
    }
  return pro;
}

int		main(int32_t		ac,
		     char		**av)
{
  t_prog		*pro;

  if ((pro = charge_prog()) == NULL)
    return -1;
  pro->pos.x = 0;
  pro->pos.y = 0;
  pro->pos.z = 0;
  pro->deb = false;
  if (ac > 1)
    {
      if (av[1][0] == 'd')
	{
	  pro->deb = true;
	  pro->pos.x = 0;
	  pro->pos.y = 0;
	  pro->pos.z = 250;
	}
    }
  std::cout << "execute avec : ./dungeon_master d\nPour avoir la vue de haut" << std::endl;
  bunny_set_key_response(game_key);
  bunny_set_entering_context_response(game_entering);
  bunny_set_loop_main_function(game_loop);
  bunny_set_display_function(game_display);
  bunny_loop(pro->win, 60, pro);
  bunny_stop(pro->win);
  free(pro);
}
