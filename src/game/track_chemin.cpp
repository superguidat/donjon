// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 14:10:29 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

t_bunny_position	track_chemin(t_track				tr,
				     t_bunny_position			pos1,
				     uint8_t				*posi,
				     int32_t				min)
{
  int32_t		i5;

  i5 = 0;
  while (pos1.x != tr.origin.x
	 || pos1.y != tr.origin.y)
    {
      if (pos1.x + 1 < (int32_t)tr.nmap.width
	  && tr.nmap.map[(uint32_t)index_map(tr.nmap.width, pos1.x + 1, pos1.y)] == min - 1)
	deplacement_x_rec((t_dep){.i5 = i5, .mv = 2, .av_re = 1}, posi, pos1, tr.nmap);
      else if (pos1.x - 1 >= 0
	  && tr.nmap.map[(uint32_t)index_map(tr.nmap.width, pos1.x - 1, pos1.y)] == min-1)
	deplacement_x_rec((t_dep){.i5 = i5, .mv = 0, .av_re = -1}, posi, pos1, tr.nmap);
      else if (pos1.y + 1 < (int32_t)tr.nmap.height
	  && tr.nmap.map[(uint32_t)index_map(tr.nmap.width, pos1.x, pos1.y + 1)] == min-1)
	deplacement_y_rec((t_dep){.i5 = i5, .mv = 3, .av_re = 1}, posi, pos1, tr.nmap);
      else if (pos1.y - 1 >= 0
	  && tr.nmap.map[(uint32_t)index_map(tr.nmap.width, pos1.x, pos1.y - 1)] == min-1)
	deplacement_y_rec((t_dep){.i5 = i5, .mv = 1, .av_re = -1}, posi, pos1, tr.nmap);
      else
	  return (tr.origin);
      min --;
      i5 ++;
    }
  return((t_bunny_position){.x = -1, .y = i5});
}
