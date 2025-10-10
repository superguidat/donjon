/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 09/10/2025 12:30:04 ******************************************************
** romain.cescutti <romain.cescutti@laika.efrits.fr>
** - donjon_master -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef		__tile_hh__
#define		__tile_hh__

class Tile
{
 public:
  Tile(void);
  ~Tile(void){;};

  double		getPoint(int8_t		point)		{return (points_of_elevation[point]);}
  int32_t		getType()				{return (type);}
  double		getBase_height()			{return (base_height);}
  t_bunny_position	getPos()				{return (pos);}

  void			setPoint(int8_t		point,
				 double		h)		{points_of_elevation[point] = h;}
  void			setType(int32_t		_type)		{type = _type;}
  void			setBase_height(double	_base_height)	{base_height = _base_height;}
  void			setPos(t_bunny_position	_pos)		{pos = _pos;}
 private:
  int32_t		type; // 0 null/outside of play range , 1 floor-tile
  double		base_height;
  t_bunny_position	pos;
  double		points_of_elevation[9]; // base_height + 9 pique de + ou - hauteur. = {0} pour avoir aucun changement
};

#endif//		__tile_hh__
