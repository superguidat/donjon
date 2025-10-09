#include	"donjon_master.hh"

extern "C" {
  bunny_declare_context(game);
}

void		move_cam(t_zposition		pos_cam,
			 t_zposition		dir_cam)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(pos_cam.x, pos_cam.y, pos_cam.z,   // position caméra
	    dir_cam.x, dir_cam.y, dir_cam.z,   // regard vers
	    0.0, 1.0, 0.0);  // up vector
}

/*
void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window,true);
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
      glViewport(100, 0, 800, 600);
}
*/

int		main(void)
{
  double r, g, b;
  t_zposition		zpo[2];
  t_prog	*pro = (t_prog*)malloc(sizeof(t_prog));

  r = 1;
  g = 1;
  b = 1;

  pro->win = bunny_start(800, 600, false, "DemoGL");

  bunny_push_gl_states(&pro->win->buffer);


  gluLookAt(0.0, 0.0, 5.0,   // position caméra
	    0.0, 0.0, 0.0,   // regard vers
	    0.0, 1.0, 0.0);  // up vector

  double x = 0;
  while (1)
    {
      zpo[0].x = cos(x)*50;
      zpo[0].y = 0;
      zpo[0].z = sin(x)*50;
      zpo[1].x = 0;
      zpo[1].y = 0;
      zpo[1].z = 0;
      glClearColor(0, 0, 0, 1.f);
      glClear(GL_COLOR_BUFFER_BIT);

      move_cam(zpo[0], zpo[1]);
      /*
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

      gluLookAt(cos(x) * 50, 0, sin(x) * 50,   // position caméra
		0.0, 0.0, 0.0,   // regard vers
		0.0, 1.0, 0.0);  // up vector
      */

      glBegin(GL_TRIANGLES);
      glColor3f(r, 0.f, 0.f); glVertex3f(-0.5f, -0.5f, -10);
      glColor3f(0.f, g, 0.f); glVertex3f( 0.5f, -0.5f, 5);
      glColor3f(0.f, 0.f, b); glVertex3f( 0.f,  0.5f, 5);

      for (int i = 0; i < 10000 * 3; ++i)
	{
	  glColor4f((rand() % 1000 / 1000.0),
		    (rand() % 1000 / 1000.0),
		    (rand() % 1000 / 1000.0),
		    (rand() % 1000 / 1000.0)
		    );
	  glVertex3f(rand() % 100 / 10.0 - 5,
		     rand() % 100 / 10.0 - 5,
		     -rand() % 100 / 10.0 - 5);
	}
      glEnd();

      bunny_pop_gl_states(&pro->win->buffer);

      bunny_display(pro->win);
      x += 0.5;
      //      bunny_usleep(1e5);
    }
  bunny_set_key_response(game_key);
  bunny_set_entering_context_response(game_entering);
  bunny_set_loop_main_function(game_loop);
  bunny_set_display_function(game_display);
  bunny_loop(pro->win, 60, &pro);
  bunny_stop(pro->win);
}
