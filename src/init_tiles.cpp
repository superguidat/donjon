#include			"donjon_master.hh"
/*
static void			init_tiles2(t_zposition	*pos,
					    int32_t	i,
					    Floor	&flo)
{
  flo.tiles[i].
    setPos(3, {pos[9].x, pos[9].y, pos[9].z});
  flo.tiles[i].
    setPos(4, {pos[1].x, pos[1].y, pos[1].z});
  flo.tiles[i].
    setPos(5, {pos[5].x, pos[5].y, pos[5].z});
  flo.tiles[i].
    setPos(6, {pos[18].x, pos[18].y, pos[18].z});
  flo.tiles[i].
    setPos(7, {pos[14].x, pos[14].y, pos[14].z});
  flo.tiles[i].
    setPos(8, {pos[21].x, pos[21].y, pos[21].z});
}

void				init_tiles(t_prog	*pro,
					   Floor	&flo,
					   int8_t	sup)
{
  t_zposition			pos[30];

  for (int32_t y = -(pro->height/2); y < (pro->height/2); y++)
    {
      for (int32_t x = -(pro->width/2); x < (pro->width/2); x++)
	{
	  pos[0].x = x * (TILE_SIZE);
	  pos[0].y = y * (TILE_SIZE);
	  set_coord({*pro, pos, NULL, x, y, (TILE_SIZE / 2)}, sup);
	  flo.tiles[(y + pro->height/2) * pro->width+(x + pro->width/2)].
	    setPos(0, {pos[0].x, pos[0].y, pos[0].z});
	  flo.tiles[(y + pro->height/2) * pro->width+(x + pro->width/2)].
	    setPos(1, {pos[2].x, pos[2].y, pos[2].z});
	  flo.tiles[(y + pro->height/2) * pro->width+(x + pro->width/2)].
	    setPos(2, {pos[6].x, pos[6].y, pos[6].z});
	  init_tiles2(pos, (y + pro->height/2) * pro->width+(x + pro->width/2), flo);
	  flo.tiles[(y + pro->height/2) * pro->width+(x + pro->width/2)].setSize(TILE_SIZE);
	}
    }
}
*/

static void			init_tiles2(t_zposition	*pos,
					    int32_t	i,
					    Floor	&flo)
{
  flo.tiles[i].
    setPos(3, {pos[9].x, pos[9].y, pos[9].z});
  flo.tiles[i].
    setPos(4, {pos[1].x, pos[1].y, pos[1].z});
  flo.tiles[i].
    setPos(5, {pos[5].x, pos[5].y, pos[5].z});
  flo.tiles[i].
    setPos(6, {pos[18].x, pos[18].y, pos[18].z});
  flo.tiles[i].
    setPos(7, {pos[14].x, pos[14].y, pos[14].z});
  flo.tiles[i].
    setPos(8, {pos[21].x, pos[21].y, pos[21].z});
}

void				init_tiles(t_prog	*pro,
					   Floor	&flo,
					   int8_t	etage)
{
  t_zposition			pos[30];

  for (int32_t salle = 0; salle < flo.rooms.size(); salle++)
    {
      for (int32_t id = 0; id < flo.rooms[salle].tiles.size(); id++)
	{
	  int32_t x = flo.rooms[salle].tiles[id].x - (pro->width/2);
	  int32_t y = flo.rooms[salle].tiles[id].y - (pro->height/2);
	  pos[0].x = x * (TILE_SIZE);
	  pos[0].y = y * (TILE_SIZE);
	  set_coord({*pro, pos, NULL, x, y, (TILE_SIZE / 2)}, etage);
	  flo.tiles[(y + pro->height/2) * pro->width+(x + pro->width/2)].
	    setPos(0, {pos[0].x, pos[0].y, pos[0].z});
	  flo.tiles[(y + pro->height/2) * pro->width+(x + pro->width/2)].
	    setPos(1, {pos[2].x, pos[2].y, pos[2].z});
	  flo.tiles[(y + pro->height/2) * pro->width+(x + pro->width/2)].
	    setPos(2, {pos[6].x, pos[6].y, pos[6].z});
	  init_tiles2(pos, (y + pro->height/2) * pro->width+(x + pro->width/2), flo);
	  flo.tiles[(y + pro->height/2) * pro->width+(x + pro->width/2)].setSize(TILE_SIZE);
	}
    }
}
