#include		"donjon_master.hh"

void			clear_img(t_bunny_color		&color)
{
  glClearColor((float)color.argb[0] / 255.f,
	       (float)color.argb[1] / 255.f,
	       (float)color.argb[2] / 255.f,
	       (float)color.argb[3] / 255.f);
  glClear(GL_COLOR_BUFFER_BIT);
}
