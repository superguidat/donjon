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

#include	<GL/glu.h>
#include	<lapin.h>
#include	<climits>
#include	<vector>
#include	<lapin.h>
#include	"room.hh"

#define		SOUS_POINT	9
#define		TILE_SIZE	36

struct				t_zposition
{
  double			x = 0;
  double			y = 0;
  double			z = 0;
};

namespace			ef
{
  class				Objet
  {
  public :
    Objet(void);
    ~Objet();// destructeur

    int32_t			getI()			{return (i);}
    double			getX()			{return (x);}
    double			getY()			{return (y);}
    double			getDegat()		{return degat;}
    t_bunny_position		getPos()		{return (t_bunny_position)
							{.x = (int)x, .y = (int)y};}

    void			setI(int32_t		_i)	{i = _i;}
    void			setX(double		_x)	{x = _x;}
    void			setY(double		_y)	{y = _y;}
    void			setDegat(double		_degat)	{degat = _degat;}
    void			setPos(double		_x,
				       double		_y)	{x = _x; y = _y;}

    GLuint			textID;
    int32_t			tileID;
  private:
    int32_t			i;
    double			x;
    double			y;
    double			degat;
  };
}
class Tile
{
 public:
  Tile(void);
  ~Tile(void);

  void			operator=(const Tile     &other);
  bool			operator==(const Tile     &other) const;


  double		getPoint(int8_t		point)		{return (points_of_elevation[point]);}
  int32_t		getType()				{return (type);}
  int32_t		getSize()				{return size;}
  double		getBase_height()			{return (base_height);}
  t_zposition		getPos(int32_t		i)		{return (pos[i]);}
  int32_t		getId_room()				{return id_room;}

  void			setId_room(int32_t	_id_room)		{id_room = _id_room;}
  void			setPoint(int8_t		point,
				 double		h)		{points_of_elevation[point] = h;}
  void			setType(int32_t		_type)		{type = _type;}
  void			setSize(int32_t		_size)		{size = _size;}
  void			setBase_height(double	_base_height)	{base_height = _base_height;}
  void			setPos(int32_t		i,
			       t_zposition	_pos)		{pos[i] = _pos;}

  double		points_of_elevation[9]; // base_height + 9 pique de + ou - hauteur. = {0} pour avoir aucun changement
  t_zposition		pos[9];
  int32_t		id;
  int32_t		x;
  int32_t		y;

 private:
  int32_t		id_room;
  room			*hroom;
  int32_t		size;
  int32_t		type; // 0 null/outside of play range , 1 floor-tile
  double		base_height;
};

void                    limit_gravity(double    &posz,
				      double    destz,
				      double	vz);

double                  distance(t_zposition	pos1,
				 t_zposition    pos2);

#endif//		__tile_hh__
