#include	"donjon_master.hh"

extern "C" {
  bunny_declare_context(game);
}

t_prog			*charge_prog()
{
  t_prog		*pro;

  if ((pro = (t_prog*) malloc( sizeof(t_prog) ) ) == NULL)
    return NULL;
  if ((pro->win = bunny_start(WIDTH, HEIGHT, false, "DemoGL")) == NULL)
    {
      free(pro);
      return NULL;
    }
  return pro;
}

int		main(void)
{
  t_prog		*pro;


  if ((pro = charge_prog()) == NULL)
    return -1;
  /*  bunny_push_gl_states(&pro->win->buffer);


  gluLookAt(0.0, 0.0, 5.0,   // position caméra
	    0.0, 0.0, 0.0,   // regard vers
	    0.0, 1.0, 0.0);  // up vector

  double x = 0;
  while (1)
    {
      colo[0].full = RED;
      colo[1].full = GREEN;
      colo[2].full = BLUE;

      pos[0].x = -0.5;
      pos[0].y = -0.5;
      pos[0].z = -10;

      pos[1].x = 0.5;
      pos[1].y = -0.5;
      pos[1].z = 5;

      pos[2].x = 0;
      pos[2].y = 0.5;
      pos[2].z = 5;

      zpo[0].x = cos(x)*50;
      zpo[0].y = 0;
      zpo[0].z = sin(x)*50;

      zpo[1].x = 0;
      zpo[1].y = 0;
      zpo[1].z = 0;

      color.argb[0] = 0;
      color.argb[1] = 0;
      color.argb[2] = 0;
      color.argb[3] = 1;

      clear_img(color);
      move_cam(zpo[0], zpo[1]);
      set_triangle(pos, colo);

      for (int i = 0; i < 10000 * 3; ++i)
	{
	  colo[0].argb[0] = (rand() % 255);
	  colo[0].argb[1] = (rand() % 255);
	  colo[0].argb[2] = (rand() % 255);
	  colo[0].argb[3] = (rand() % 255);

	  pos[0].x = rand() % 100 / 10 - 5;
	  pos[0].y = rand() % 100 / 10 - 5;
	  pos[0].z = -rand() % 100 / 10 - 5;

	  colo[1].argb[0] = (rand() % 255);
	  colo[1].argb[1] = (rand() % 255);
	  colo[1].argb[2] = (rand() % 255);
	  colo[1].argb[3] = (rand() % 255);

	  pos[1].x = rand() % 100 / 10 - 5;
	  pos[1].y = rand() % 100 / 10 - 5;
	  pos[1].z = -rand() % 100 / 10 - 5;

	  colo[2].argb[0] = (rand() % 255);
	  colo[2].argb[1] = (rand() % 255);
	  colo[2].argb[2] = (rand() % 255);
	  colo[2].argb[3] = (rand() % 255);

	  pos[2].x = rand() % 100 / 10 - 5;
	  pos[2].y = rand() % 100 / 10 - 5;
	  pos[2].z = -rand() % 100 / 10 - 5;

	  set_triangle(pos, colo);
	}
      glEnd();

      bunny_pop_gl_states(&pro->win->buffer);

      bunny_display(pro->win);
      x += 0.5;
      //      bunny_usleep(1e5);
      }*/
  pro->pos.x = -5;
  pro->pos.y = 0;
  pro->tilt = 0;
  pro->rot = 0;
  bunny_set_key_response(game_key);
  bunny_set_entering_context_response(game_entering);
  bunny_set_loop_main_function(game_loop);
  bunny_set_display_function(game_display);
  bunny_loop(pro->win, 60, pro);
  bunny_stop(pro->win);
  free(pro);
}
