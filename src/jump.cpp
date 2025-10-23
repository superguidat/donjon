#include	"donjon_master.hh"

void		ef::Unit::jump(double		current_time,
			       double		dd)
{
  if (!is_jumping
      && (current_time - last_jump_time >= jump_cooldown)
      && pos_cam.z <= dd)
    {
      vertical_speed = jump_force;
      is_jumping = true;
      last_jump_time = current_time;
    }
}
