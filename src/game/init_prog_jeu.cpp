// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 12:06:09 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			init_prog_jeu(t_prog		*pro)
{
  pro->tilt = 0;
  pro->rot = 0;
  pro->me.setPos_cam(pro->pos);
  pro->me.setDir_cam((t_zposition){.x = (pro->pos.x + cos(pro->rot)),
				   .y = (pro->pos.y + sin(pro->rot)),
				   .z = 0});
  pro->me.setVec_cam((t_zposition){.x = 0,
				   .y = 0,
				   .z = 1});
  pro->me.setLast_jump_time(-1.0);
  pro->me.setJump_cooldown(JUMP_COOLDOWN);
  pro->me.setJump_force(JUMP_FORCE);
  pro->me.setGravity(GRAVITY);
  pro->me.setIs_jumping(false);
  pro->me.setVertical_speed(0.0);
  pro->height = WIDTH_MAP;
  pro->width = HEIGHT_MAP;
  pro->etage_actuel = 1;
  pro->nb_etage = 0;
  pro->ecran = 0;
}
