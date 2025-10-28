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

#include <lapin.h>

#define		SOUS_POINT			9
#define		TILE_SIZE			36

struct				t_zposition
{
  double			x;
  double			y;
  double			z;
};

class Tile
{
 public:
  Tile(void);
  ~Tile(void){;};

  double		getPoint(int8_t		point)		{return (points_of_elevation[point]);}
  int32_t		getType()				{return (type);}
  int32_t		getSize()				{return size;}
  double		getBase_height()			{return (base_height);}
  t_zposition		getPos(int32_t		i)		{return (pos[i]);}

  void			setPoint(int8_t		point,
				 double		h)		{points_of_elevation[point] = h;}
  void			setType(int32_t		_type)		{type = _type;}
  void			setSize(int32_t		_size)		{size = _size;}
  void			setBase_height(double	_base_height)	{base_height = _base_height;}
  void			setPos(int32_t		i,
			       t_zposition	_pos)		{pos[i] = _pos;}
 private:
  int32_t		size;
  int32_t		type; // 0 null/outside of play range , 1 floor-tile
  double		base_height;
  double		points_of_elevation[9]; // base_height + 9 pique de + ou - hauteur. = {0} pour avoir aucun changement
  t_zposition		pos[9];
};

void                    limit_gravity(double    &posz,
				      double    destz,
				      double	vz);

double                  distance(t_zposition	pos1,
				 t_zposition    pos2);

#endif//		__tile_hh__
