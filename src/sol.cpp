#include		"donjon_master.hh"

void			sol(t_prog		&pro,
			    int32_t		x,
			    int32_t		y,
			    t_zposition		*pos)
{
  pos[0].x = x * (TILE_SIZE);
  pos[0].y = y * (TILE_SIZE);
  set_coord((t_coord){pro, pos, NULL, x, y, (TILE_SIZE / 2)}, -1);
  for(int32_t i = 0; i < 4; i++)
    set_zcarre(&pos[i*6], pro, 0);

  if (x < (pro.width / 2)
      && x > -(pro.width/2))
    {
      init_triangle_RL(pos,
		       pro.tiles[(y+pro.height/2)*pro.width + ((x-1)+pro.width/2)],
		       pro.tiles[(y+pro.height/2)*pro.width + ((x)+pro.width/2)]);
      set_zcarre(pos, pro, 2);
      set_zcarre(&pos[6], pro, 2);
    }
  if (y < (pro.height / 2)
      && y > -(pro.height/2))
    {
      init_triangle_HB(pos,
		       pro.tiles[((y-1)+pro.height/2)*pro.width + ((x)+pro.width/2)],
		       pro.tiles[(y+pro.height/2)*pro.width + ((x)+pro.width/2)]);
      set_zcarre(pos, pro, 2);
      set_zcarre(&pos[6], pro, 2);
    }
}
