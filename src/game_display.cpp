#include		"donjon_master.hh"

extern "C"
t_bunny_response        game_display(t_prog				*prog)
{
  t_bunny_color		col;
  t_bunny_color		color[3];
  t_zposition		pos[3];
  t_zposition		pos_cam;
  t_zposition		dir_cam;
  t_zposition		vec_cam;
  double		tile_size = rand() %30 + 20;

  bunny_push_gl_states(&prog->win->buffer);
  pos_cam.x = prog->pos.x;
  pos_cam.y = prog->pos.y;
  pos_cam.z = 0;
  dir_cam.x = (prog->pos.x + cos(prog->rot));
  dir_cam.y = (prog->pos.y + sin(prog->rot));
  dir_cam.z = (0);
  vec_cam.x = (0);
  vec_cam.y = (0);
  vec_cam.z = (1);
  move_cam(pos_cam, dir_cam, vec_cam);

  col.full = BLACK;
  clear_img(col);

  color[0].full = RED;
  color[1].full = RED;
  color[2].full = RED;
  pos[0] = {.x = -tile_size, .y = -tile_size, .z = +5};
  pos[1] = {.x = -tile_size, .y = tile_size, .z = +5};
  pos[2] = {.x = tile_size, .y = -tile_size, .z = +5};
  set_triangle(pos, color);
  color[0].full = RED;
  color[1].full = RED;
  color[2].full = RED;
  pos[0] = {.x = tile_size, .y = tile_size, .z = +5};
  pos[1] = {.x = -tile_size, .y = tile_size, .z = +5};
  pos[2] = {.x = tile_size, .y = -tile_size, .z = +5};
  set_triangle(pos, color);

  color[0].full = BLUE;
  color[1].full = BLUE;
  color[2].full = BLUE;
  pos[0] = {.x = -tile_size, .y = -tile_size, .z = -5};
  pos[1] = {.x = -tile_size, .y = tile_size, .z = -5};
  pos[2] = {.x = tile_size, .y = -tile_size, .z = -5};
  set_triangle(pos, color);

  color[0].full = BLUE;
  color[1].full = BLUE;
  color[2].full = BLUE;
  pos[0] = {.x = tile_size, .y = tile_size, .z = -5};
  pos[1] = {.x = -tile_size, .y = tile_size, .z = -5};
  pos[2] = {.x = tile_size, .y = -tile_size, .z = -5};
  set_triangle(pos, color);

  glEnd();
  bunny_pop_gl_states(&prog->win->buffer);
  bunny_display(prog->win);
  return (GO_ON);
}
