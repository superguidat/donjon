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
  double		tile_size = 30 + 20;

  bunny_push_gl_states(&prog->win->buffer);
  prog->me.setPos_cam(prog->pos);
  prog->me.setDir_cam((t_zposition){.x = (prog->pos.x + cos(prog->rot)),
				   .y = (prog->pos.y + sin(prog->rot)),
				   .z = 0});
  move_cam(prog->me.getPos_cam(), prog->me.getDir_cam(), prog->me.getVec_cam());

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
