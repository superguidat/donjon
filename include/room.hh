// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 09/10/2025 17:17:58 ******************************************************
// romain.cescutti <romain.cescutti@laika.efrits.fr>
// - donjon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef __room_hh__
#define __room_hh__
#include <lapin.h>
#include <vector>
#include "tile.hh"

#define			SIZE_COULOIR	1

class room
{
 public:
  room(void);
  room(int		minsize);
  room(int		x1,
       int		x2,
       int		y1,
       int		y2,
       int		minsize = 100);
  //  room(t_bunny_area	area) : room(area.x, area.x + area.w, area.y, area.y + area.h) {;}

  room(const room	&ref)
  {
    (*this) = ref;
  }

  void			operator=(const room		&other);
  bool			operator==(const room		&other) const;

  void			create(int32_t			*tab,
			       t_bunny_position		*Rcorner,
			       double			base_height,
			       int32_t			width);

  unsigned int		color;
  bool			isMinimal()	const; // A priori, inutile vu les nouveaux concepts.
  bool			isXSplitable()	const;
  bool			isYSplitable()	const;
  room			splitY(const room &parent_room,
			       int32_t	checky);
  room			splitX(const room &parent_room,
			       int32_t	checkx);

  std::vector<Tile>	tiles;
  t_bunny_position	corner[4];
  int32_t		minsize;
  int32_t		w;
  int32_t		h;
  int32_t		id;
};

#endif//    __ROOM_HH__
