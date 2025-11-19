#include		"room.hh"

room::room(int32_t 		ms)
  : minsize(ms)
{
  static int32_t 		colsec;
  uint32_t			colors[] = {
    RED,
    GREEN,
    BLUE,
    TEAL,
    YELLOW,
    PURPLE,
    WHITE
  };

  color = colors[colsec % NBRCELL(colors)];
  colsec++;
}

room::room(int32_t 		x1,
	   int32_t 		x2,
	   int32_t 		y1,
	   int32_t 		y2,
	   int32_t	_minsize)
  : room(_minsize)
{
  corner[0].x = x1;
  corner[1].x = x2;
  corner[2].x = x1;
  corner[3].x = x2;
  corner[0].y = y1;
  corner[1].y = y1;
  corner[2].y = y2;
  corner[3].y = y2;
}


room::room()
  : color(WHITE)
  , minsize(100)
  , w(0)
  , h(0)
  , id(0)
{
  corner[0].x = -INT_MAX;
  corner[0].y = -INT_MAX;
  corner[1].x = -INT_MAX;
  corner[1].y = -INT_MAX;
  corner[2].x = -INT_MAX;
  corner[2].y = -INT_MAX;
  corner[3].x = -INT_MAX;
  corner[3].y = -INT_MAX;
}
