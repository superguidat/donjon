// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 10/10/2025 12:30:53 ******************************************************
// romain.cescutti <romain.cescutti@laika.efrits.fr>
// - donjon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "floor.hh"
#include <lapin.h>
#include <cstdlib>
#include <cstddef>

int main(void)
{
  t_bunny_picture *pix;
  t_bunny_window *win;
  t_bunny_position Rcorner[5];
  Floor mfloor;
  room tempFloorroom(200,600,200,600);
  int i;
  int j;
  t_bunny_color color[2] = { {.full = RED}, {.full = BLUE} };

  i = 0;
  win = bunny_start(800, 800, false, "sawg");
  pix = bunny_new_picture(win->buffer.width, win->buffer.height);

  mfloor.subdivide(tempFloorroom);
  j = mfloor.rooms.size();
  std::cout << j << std::endl;
  srand(time(NULL));
  while(i<j)
    {
      Rcorner[0] = mfloor.rooms[i].corner[0];
      Rcorner[1] = mfloor.rooms[i].corner[1];
      Rcorner[2] = mfloor.rooms[i].corner[3];
      Rcorner[3] = mfloor.rooms[i].corner[2];
      Rcorner[4] = mfloor.rooms[i].corner[0];
      bunny_set_line(&pix->buffer,Rcorner,&color->full);
      bunny_set_line(&pix->buffer,&Rcorner[1],&color->full);
      bunny_set_line(&pix->buffer,&Rcorner[2],&color->full);
      bunny_set_line(&pix->buffer,&Rcorner[3],&color->full);
      i++;
    }
  bunny_blit(&win->buffer, pix,NULL);
  bunny_display(win);
  bunny_usleep(100000000);
}
