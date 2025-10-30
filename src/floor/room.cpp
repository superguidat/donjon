// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 24/10/2025 17:14:04 ******************************************************
// romain.cescutti <romain.cescutti@jemison.efrits.fr>
// - donjon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "room.hh"

room::room(int ms)
  : minsize(ms)
{
  static int colsec;
  unsigned int colors[] = {
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

room::room(int x1,int x2, int y1 , int y2, int32_t _minsize)
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

bool room::isMinimal() const
{
  int sizex = corner[3].x - corner[0].x;
  int sizey = corner[3].y - corner[0].y;

  if (sizex * sizey < (minsize / 4) * (minsize / 4))
    return (true);
  if (sizex < minsize)
    return true;
  if(sizey < minsize)
    return true;
  return false;
}
