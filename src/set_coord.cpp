#include	"donjon_master.hh"

static void     set_coord2(t_coord			&coo)
{
  coo.pos[0] = {.x = coo.pos[0].x, .y = coo.pos[0].y, .z = -5 + coo.p[0].z};
  coo.pos[1] = {.x = coo.pos[0].x + coo.tile_size, .y = coo.pos[0].y + coo.tile_size, .z = -5 + coo.p[4].z};
  coo.pos[2] = {.x = coo.pos[0].x + coo.tile_size, .y = coo.pos[0].y, .z = -5 + coo.p[1].z};

  coo.pos[3] = {.x = coo.pos[2].x, .y = coo.pos[2].y, .z = -5 + coo.p[1].z};
  coo.pos[4] = {.x = coo.pos[2].x, .y = coo.pos[2].y + coo.tile_size, .z = -5 + coo.p[4].z};
  coo.pos[5] = {.x = coo.pos[2].x + coo.tile_size, .y = coo.pos[2].y + coo.tile_size, .z = -5 + coo.p[5].z};

  coo.pos[6] = {.x = coo.pos[3].x + coo.tile_size, .y = coo.pos[0].y, .z = -5 + coo.p[2].z};
  coo.pos[7] = {.x = coo.pos[3].x, .y = coo.pos[3].y, .z = -5 + coo.p[1].z};
  coo.pos[8] = {.x = coo.pos[5].x, .y = coo.pos[5].y, .z = -5 + coo.p[5].z};

  coo.pos[9] = {.x = coo.pos[0].x, .y = coo.pos[0].y + coo.tile_size, .z = -5 + coo.p[3].z};
  coo.pos[10] = {.x = coo.pos[0].x, .y = coo.pos[0].y, .z = -5 + coo.p[0].z};
  coo.pos[11] = {.x = coo.pos[1].x, .y = coo.pos[1].y, .z = -5 + coo.p[4].z};

}

static void	init_p(t_coord				&coo,
		       int8_t				sup)
{
  for (int8_t i = 0; i < 9; i++)
    {
      if (sup > 0)
	coo.p[i] = {.x = coo.pos[0].x,
		    .y = coo.pos[0].y + coo.tile_size,
		    .z = coo.pro.haut.tiles[(coo.y + coo.pro.height / 2)
					   * coo.pro.width
					   + (coo.x + coo.pro.width / 2)].getPoint(i)};
      else
	coo.p[i] = {.x = coo.pos[0].x,
		    .y = coo.pos[0].y + coo.tile_size,
		    .z = coo.pro.bas.tiles[(coo.y + coo.pro.height / 2)
				       * coo.pro.width
				       + (coo.x + coo.pro.width / 2)].getPoint(i)};
    }
}

void		set_coord(t_coord			coo,
			  int8_t			sup)
{
  t_zposition	p[9];

  coo.p = p;
  init_p(coo, sup);
  set_coord2(coo);
  coo.pos[12] = {.x = coo.pos[11].x, .y = coo.pos[11].y, .z = -5 + coo.p[4].z};
  coo.pos[13] = {.x = coo.pos[9].x, .y = coo.pos[9].y, .z = -5 + coo.p[3].z};
  coo.pos[14] = {.x = coo.pos[12].x, .y = coo.pos[12].y + coo.tile_size, .z = -5 + coo.p[7].z};

  coo.pos[15] = {.x = coo.pos[8].x, .y = coo.pos[8].y, .z = -5 + coo.p[5].z};
  coo.pos[16] = {.x = coo.pos[12].x, .y = coo.pos[12].y, .z = -5 + coo.p[4].z};
  coo.pos[17] = {.x = coo.pos[14].x, .y = coo.pos[14].y, .z = -5 + coo.p[7].z};

  coo.pos[18] = {.x = coo.pos[9].x, .y = coo.pos[9].y + coo.tile_size, .z = -5 + coo.p[6].z};
  coo.pos[19] = {.x = coo.pos[9].x, .y = coo.pos[9].y, .z = -5 + coo.p[3].z};
  coo.pos[20] = {.x = coo.pos[14].x, .y = coo.pos[14].y, .z = -5 + coo.p[7].z};

  coo.pos[21] = {.x = coo.pos[14].x + coo.tile_size, .y = coo.pos[14].y, .z = -5 + coo.p[8].z};
  coo.pos[22] = {.x = coo.pos[14].x, .y = coo.pos[14].y, .z = -5 + coo.p[7].z};
  coo.pos[23] = {.x = coo.pos[8].x, .y = coo.pos[8].y, .z = -5 + coo.p[5].z};
}
