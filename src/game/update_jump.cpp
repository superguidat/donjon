#include	"donjon_master.hh"


void		ef::Unit::update_jump(double		deltaTime,
				      double		dd)
{
  if (is_jumping)
    {
      vertical_speed -= gravity * deltaTime;
      pos_cam.z += vertical_speed * deltaTime;
      if (pos_cam.z <= dd)
        {
	  pos_cam.z = dd;
	  vertical_speed = 0;
	  is_jumping = false;
        }
    }
  else
    if (pos_cam.z > dd)
      is_jumping = true;
}
