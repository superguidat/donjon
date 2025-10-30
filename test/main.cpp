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
#include "tile.hh"
#include <lapin.h>
#include <cstdlib>
#include <cstddef>

int main(int	argc,
	 char	**argv)
{
  (void)argc;
  char *subdiv = argv[1];
  t_bunny_picture *pix;
  t_bunny_window *win;
  t_bunny_position Rcorner[5];
  Floor mfloor;
  int i;
  int j;

  srand(time(NULL));
  i = 0;
  win = bunny_start(800, 800, false, "sawg");
  pix = bunny_new_picture(win->buffer.width, win->buffer.height);
  bunny_clear(&pix->buffer, BLACK);

  room tempFloorroom(0, 50, 0, 50, 2);

  if (argv[1] == NULL)
    subdiv = (char*)"1";
  mfloor.subdivide(tempFloorroom, atoi(subdiv));
  j = mfloor.rooms.size();
  std::cout << j << std::endl;
  while(i<j)
    {
      t_bunny_color color[2] = { {.full = mfloor.rooms[i].color}, {.full = mfloor.rooms[i].color } };
      Rcorner[0] = mfloor.rooms[i].corner[0];
      Rcorner[1] = mfloor.rooms[i].corner[1];
      Rcorner[2] = mfloor.rooms[i].corner[3];
      Rcorner[3] = mfloor.rooms[i].corner[2];
      Rcorner[4] = mfloor.rooms[i].corner[0];
      t_bunny_position pos[4] = {
	{Rcorner[0].x, Rcorner[0].y},
	{Rcorner[2].x, Rcorner[2].y},
	{Rcorner[1].x, Rcorner[1].y},
	{Rcorner[3].x, Rcorner[3].y}
      };
      bunny_set_line(&pix->buffer,Rcorner,&color->full);
      bunny_set_line(&pix->buffer,&Rcorner[1],&color->full);
      bunny_set_line(&pix->buffer,&Rcorner[2],&color->full);
      bunny_set_line(&pix->buffer,&Rcorner[3],&color->full);
      bunny_set_line(&pix->buffer,&pos[0],&color->full);
      bunny_set_line(&pix->buffer,&pos[2],&color->full);
      i++;
    }
  bunny_blit(&win->buffer, pix,NULL);
  bunny_display(win);
  bunny_usleep(100000000);
}
