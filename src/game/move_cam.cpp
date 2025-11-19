#include		"donjon_master.hh"

void			move_cam(t_zposition		pos_cam,
				 t_zposition		dir_cam,
				 t_zposition		vec_cam)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, WIDTH / HEIGHT, 0.1, 2000.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(pos_cam.x, pos_cam.y, pos_cam.z,   // position caméra
	    dir_cam.x, dir_cam.y, dir_cam.z,   // regard vers
	    vec_cam.x, vec_cam.y, vec_cam.z);  // up vector
}
