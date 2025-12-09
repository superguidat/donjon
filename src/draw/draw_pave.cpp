// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 25/11/2025 12:21:01 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			draw_pave_texture(double			zdelt,
					  t_zposition			pos,
					  t_zposition			s,
					  GLuint			texture)
{
  double		x = pos.x;
  double		y = pos.y;
  double		z = pos.z + zdelt;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);

  glBegin(GL_QUADS);

  // face avant
  glTexCoord2f(0, 0); glVertex3f(x,     y,     z+s.z);
  glTexCoord2f(1, 0); glVertex3f(x+s.x,   y,     z+s.z);
  glTexCoord2f(1, 1); glVertex3f(x+s.x,   y+s.y,   z+s.z);
  glTexCoord2f(0, 1); glVertex3f(x,     y+s.y,   z+s.z);

  // face arrière
  glTexCoord2f(1, 0); glVertex3f(x,     y,     z);
  glTexCoord2f(1, 1); glVertex3f(x,     y+s.y,   z);
  glTexCoord2f(0, 1); glVertex3f(x+s.x,   y+s.y,   z);
  glTexCoord2f(0, 0); glVertex3f(x+s.x,   y,     z);

  // face gauche
  glTexCoord2f(0, 0); glVertex3f(x,     y,     z);
  glTexCoord2f(1, 0); glVertex3f(x,     y,     z+s.z);
  glTexCoord2f(1, 1); glVertex3f(x,     y+s.y,   z+s.z);
  glTexCoord2f(0, 1); glVertex3f(x,     y+s.y,   z);

  // face droite
  glTexCoord2f(0, 0); glVertex3f(x+s.x,   y,     z+s.z);
  glTexCoord2f(1, 0); glVertex3f(x+s.x,   y,     z);
  glTexCoord2f(1, 1); glVertex3f(x+s.x,   y+s.y,   z);
  glTexCoord2f(0, 1); glVertex3f(x+s.x,   y+s.y,   z+s.z);

  // face haut
  glTexCoord2f(0, 1); glVertex3f(x,     y+s.y,   z+s.z);
  glTexCoord2f(0, 0); glVertex3f(x+s.x,   y+s.y,   z+s.z);
  glTexCoord2f(1, 0); glVertex3f(x+s.x,   y+s.y,   z);
  glTexCoord2f(1, 1); glVertex3f(x,     y+s.y,   z);

  // face bas
  glTexCoord2f(1, 1); glVertex3f(x,     y,     z);
  glTexCoord2f(0, 1); glVertex3f(x+s.x,   y,     z);
  glTexCoord2f(0, 0); glVertex3f(x+s.x,   y,     z+s.z);
  glTexCoord2f(1, 0); glVertex3f(x,     y, z+s.z);

  glEnd();

  glDisable(GL_TEXTURE_2D);
}
