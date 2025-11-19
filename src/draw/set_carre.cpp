#include	"donjon_master.hh"

void		set_carre(t_zposition			pos,
			  t_prog			&pro,
			  int32_t			tile_size,
			  int16_t			id)
{
  t_zposition	po[3];

  po[0] = {.x = pos.x, .y = pos.y, .z = pos.z};
  po[1] = {.x = pos.x, .y = pos.y + tile_size, .z = pos.z};
  po[2] = {.x = pos.x + tile_size, .y = pos.y, .z = pos.z};
  set_triangle_text(po, pro.textureID[id]);
  po[0] = {.x = pos.x + tile_size, .y = pos.y + tile_size, .z = pos.z};
  po[1] = {.x = pos.x + tile_size, .y = pos.y, .z = pos.z};
  po[2] = {.x = pos.x, .y = pos.y + tile_size, .z = pos.z};
  set_triangle_text(po, pro.textureID[id]);
}
