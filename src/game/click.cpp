#include			"donjon_master.hh"

extern "C"

t_bunny_response                game_click(t_bunny_event_state		state,
					   t_bunny_mouse_button		button,
					   t_prog			*prog)
{
  if (prog->ecran == 1)
    {
      t_bunny_position *pos;
      pos = (t_bunny_position*)bunny_get_mouse_position();
      pos->x = pos->x % prog->win->buffer.width;
      pos->y = pos->y % prog->win->buffer.height;
    }
  return (GO_ON);
}
