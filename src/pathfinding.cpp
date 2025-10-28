/*#include		"donjon_master.hh"

static const		t_bunny_position tabs[4] =
  {
    {.x = -1, .y = 0},
    {.x = 0, .y = 1},
    {.x = 1, .y = 0},
    {.x = 0, .y = -1},
  };

static void		init_coll(t_colli		&coll,
				  t_path		&origin,
				  int32_t		p,
				  int32_t		*next_pas)
{
  t_bunny_position	cpas;

  cpas = (t_bunny_position)tabs[next_pas[p]];
  coll.x = (origin.pos.x + cpas.x);
  coll.y = (origin.pos.y + cpas.y);
}

static t_path		_pathfinding(t_rec		&rec,
				     t_path		origin,
				     t_bunny_pixelarray	&pix,
				     int32_t		step)
{
  t_path		pat;
  t_colli		coll;
  int32_t		next_pas[4];

  rec.map->map[(uint32_t)index_map(rec.map->width, origin.pos.x, origin.pos.y)] = step;
  if (test_sorti_rec(rec, step, origin))
    return origin;

  next_pas[0] = {which_direction(origin.pos.x - rec.destination.x, origin.pos.y - rec.destination.y)};
  init_next_pas(next_pas);
  for (int32_t p = 0; p < 4; p ++)
    {
      init_coll(coll, origin, p, next_pas);
      coll.r = (rec.r);
      coll.i = (rec.i);
      if (!collision(pix, coll, step, rec.map))
	{
	  init_pat(pat, coll, rec.destination);
	  test_dist(_pathfinding(rec, pat, pix, step+1), pat, rec.map);
	  if (!pat.blk)
	    return pat;
	}
    }
      origin.blk = true;
  return origin;
}

t_bunny_position	ef::Unit::pathfinding(t_map			*map,
					      t_bunny_pixelarray	&pix,
					      t_bunny_position		destination)
{
  t_rec			rec;
  t_bunny_position	pos1;
  t_path		origi;
  uint8_t		*posi;
  t_bunny_position	origin;
  int			min;
  t_map			nmap = *map;

  posi = pos;

  if ((nmap = init_map(map, i)).map == NULL)
    return origin;

  rec = init_rec_path(destination, i, r, &nmap);
  init_origi(x, y, origi);
  origi = _pathfinding(rec, origi, pix, 0);
  pos1 = init_check_pos_rec(nmap, destination, origin, origi);
  min = nmap.map[(uint32_t)index_map(nmap.width, destination.x, destination.y)];
  if ((pos1 = track_chemin((t_track){.origin = origin, .nmap = nmap}, pos1, posi, min)).x == -1)
    {
      t = pos1.y;
      bouge_rec(t, pos, origin);
    }
  free(nmap.map);
  return (origin);
*/
