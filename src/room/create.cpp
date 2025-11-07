#include		"room.hh"

void			room::create(int32_t		*tab,
				     t_bunny_position	*Rcorner,
				     double		base_height,
				     int32_t		width)
{
  h = Rcorner[2].y - Rcorner[0].y;
  w = Rcorner[1].x - Rcorner[0].x;
  tiles.resize(h * w);
  for (int32_t y2 = Rcorner[0].y; y2 < Rcorner[2].y; y2 ++)
    {
      for (int32_t x2 = Rcorner[0].x; x2 < Rcorner[1].x; x2 ++)
	{
	  if (x2 == Rcorner[0].x
	      || x2 == Rcorner[2].x-1
	      || y2 == Rcorner[0].y
	      || y2 == Rcorner[2].y-1)
	    {
	      tab[y2 * width + x2] = 1;
	      for (int32_t l = 0; l < 9; l ++)
		tiles[(y2 -  Rcorner[0].y) * w + (x2 - Rcorner[0].x)].setPoint(l, 9);
	    }
	  else
	    {
	      ;
	      /*if ((x2+1) < Rcorner[1].x)
		{
		tab[y2*pro.width+x2] = 2;
		tab[y2*pro.width+(x2+1)] = 3;
		}
		else if ((x2-1) > Rcorner[0].x)
		{
		tab[y2*pro.width+x2] = 2;
		tab[y2*pro.width+(x2-1)] = 3;
		}*/
	      tab[y2 * width + x2] = -1;
	      for (int32_t l = 0; l < 9; l ++)
		tiles[(y2 -  Rcorner[0].y) * w + (x2 - Rcorner[0].x)].setPoint(l, 0);
	    }
	  tiles[(y2 -  Rcorner[0].y) * w + (x2 - Rcorner[0].x)].setBase_height(base_height);
	  tiles[(y2 -  Rcorner[0].y) * w + (x2 - Rcorner[0].x)].id = y2 * width + x2;
	  tiles[(y2 -  Rcorner[0].y) * w + (x2 - Rcorner[0].x)].y = y2;
	  tiles[(y2 -  Rcorner[0].y) * w + (x2 - Rcorner[0].x)].x = x2;
	  tiles[(y2 -  Rcorner[0].y) * w + (x2 - Rcorner[0].x)].setType(0);
	  tiles[(y2 -  Rcorner[0].y) * w + (x2 - Rcorner[0].x)].setSize(TILE_SIZE);
	}
    }
}
