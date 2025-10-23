#include	"donjon_master.hh"

void		set_zcarre(t_zposition			*pos,
			   t_prog			&pro,
			   int16_t			id)
{
  set_triangle_text(pos, pro.textureID[id]);
  set_triangle_text(&pos[3], pro.textureID[id]);
}
