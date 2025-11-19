// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 17/11/2025 12:46:29 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			draw_cube_texture(t_zposition			pos,
					  double			size,
					  GLuint			texture)
{
    double		x = pos.x;
    double		y = pos.y;
    double		z = pos.z;
    double		s = size;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);

    // face avant
    glTexCoord2f(0, 0); glVertex3f(x,     y,     z+s);
    glTexCoord2f(1, 0); glVertex3f(x+s,   y,     z+s);
    glTexCoord2f(1, 1); glVertex3f(x+s,   y+s,   z+s);
    glTexCoord2f(0, 1); glVertex3f(x,     y+s,   z+s);

    // face arrière
    glTexCoord2f(1, 0); glVertex3f(x,     y,     z);
    glTexCoord2f(1, 1); glVertex3f(x,     y+s,   z);
    glTexCoord2f(0, 1); glVertex3f(x+s,   y+s,   z);
    glTexCoord2f(0, 0); glVertex3f(x+s,   y,     z);

    // face gauche
    glTexCoord2f(0, 0); glVertex3f(x,     y,     z);
    glTexCoord2f(1, 0); glVertex3f(x,     y,     z+s);
    glTexCoord2f(1, 1); glVertex3f(x,     y+s,   z+s);
    glTexCoord2f(0, 1); glVertex3f(x,     y+s,   z);

    // face droite
    glTexCoord2f(0, 0); glVertex3f(x+s,   y,     z+s);
    glTexCoord2f(1, 0); glVertex3f(x+s,   y,     z);
    glTexCoord2f(1, 1); glVertex3f(x+s,   y+s,   z);
    glTexCoord2f(0, 1); glVertex3f(x+s,   y+s,   z+s);

    // face haut
    glTexCoord2f(0, 1); glVertex3f(x,     y+s,   z+s);
    glTexCoord2f(0, 0); glVertex3f(x+s,   y+s,   z+s);
    glTexCoord2f(1, 0); glVertex3f(x+s,   y+s,   z);
    glTexCoord2f(1, 1); glVertex3f(x,     y+s,   z);

    // face bas
    glTexCoord2f(1, 1); glVertex3f(x,     y,     z);
    glTexCoord2f(0, 1); glVertex3f(x+s,   y,     z);
    glTexCoord2f(0, 0); glVertex3f(x+s,   y,     z+s);
    glTexCoord2f(1, 0); glVertex3f(x,     y,     z+s);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}
