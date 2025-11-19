#include		"donjon_master.hh"

void			set_triangle_text(t_zposition	*pos,
					  GLuint	textureID)
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, textureID);
  glBegin(GL_TRIANGLES);

  glColor3f(1.0f, 1.0f, 1.0f); // ne modifie pas la texture

  // glEnable(GL_TEXTURE_2D);

  glTexCoord2f(0.0f, 0.0f); glVertex3f((float)pos[0].x,
				       (float)pos[0].y,
				       (float)pos[0].z);
  glTexCoord2f(1.0f, 0.0f); glVertex3f((float)pos[1].x,
				       (float)pos[1].y,
				       (float)pos[1].z);
  glTexCoord2f(0.5f, 1.0f); glVertex3f((float)pos[2].x,
				       (float)pos[2].y,
				       (float)pos[2].z);

  glEnd();
}
