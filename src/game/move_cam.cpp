#include		"donjon_master.hh"

void			move_cam(t_zposition	pos_cam,
				 t_zposition	dir_cam,
				 t_zposition	vec_cam,
				 int		ecran)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (ecran == 0)   // MODE 3D
    {
        gluPerspective(45.0, WIDTH / HEIGHT, 0.1, 2000.0);
    }
    else              // MODE 2D
    {
        glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (ecran == 0)   // MODE 3D → lookAt
    {
        gluLookAt(pos_cam.x, pos_cam.y, pos_cam.z,
                  dir_cam.x, dir_cam.y, dir_cam.z,
                  vec_cam.x, vec_cam.y, vec_cam.z);
    }
    // MODE 2D → pas de caméra, le repère est déjà bon
}
