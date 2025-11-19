#include "donjon_master.hh"

void			sol(t_sol	&sol,
			    int8_t	id_sol,
			    int8_t	id_mur)
{
  sol.pos[0].x = sol.x * (TILE_SIZE);
  sol.pos[0].y = sol.y * (TILE_SIZE);
  set_coord((t_coord){*sol.pro, sol.pos, NULL, sol.x, sol.y, (TILE_SIZE / 2)}, sol.etage);
  if (sol.flo->tiles[(sol.y+sol.pro->height/2)*sol.pro->width + ((sol.x-1)+sol.pro->width/2)].getType() == 1)
    return;
  for(int32_t i = 0; i < 4; i++)
    set_zcarre(&sol.pos[i*6], *sol.pro, id_sol);
  if (sol.x < (sol.pro->width / 2)
      && sol.x > -(sol.pro->width/2))
    {
      init_triangle_RL(sol.pos,
		       sol.flo->tiles[(sol.y+sol.pro->height/2)*sol.pro->width + ((sol.x-1)+sol.pro->width/2)],
		       sol.flo->tiles[(sol.y+sol.pro->height/2)*sol.pro->width + ((sol.x)+sol.pro->width/2)]);
      set_zcarre(sol.pos, *sol.pro, id_mur);
      set_zcarre(&sol.pos[6], *sol.pro, id_mur);
    }
  if (sol.y < (sol.pro->height / 2)
      && sol.y > -(sol.pro->height/2))
    {
      init_triangle_HB(sol.pos,
		       sol.flo->tiles[((sol.y-1)+sol.pro->height/2)*sol.pro->width + ((sol.x)+sol.pro->width/2)],
		       sol.flo->tiles[(sol.y+sol.pro->height/2)*sol.pro->width + ((sol.x)+sol.pro->width/2)]);
      set_zcarre(sol.pos, *sol.pro, id_mur);
      set_zcarre(&sol.pos[6], *sol.pro, id_mur);
    }
}
