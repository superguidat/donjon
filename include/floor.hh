/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 09/10/2025 12:30:24 ******************************************************
** romain.cescutti <romain.cescutti@laika.efrits.fr>
** - donjon_master -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef			__floor_hh_
#define			__floor_hh_
#include		"room.hh"
#include		<vector>

#define			WIDTH_MAP			70
#define			HEIGHT_MAP			70

struct			t_prog;

class Subdim
{
  /* tout ce qui est neccessaire poru permettre a operator[] de marcher */
public:
  Tile			&operator[](size_t		idx);
  const Tile		&operator[](size_t		idx) const;
  t_zposition pos[9];
  int32_t id;
  int32_t x;
  int32_t y;

  Subdim(/* tout ce qui est neccessaire pour permettre a opereator[] de marcher */)
  {
  }
  ~Subdim(void) = default;
};

class Floor
{
 public:
  Floor();
  Floor(const Floor	&floor)
  {
    (*this) = floor;
  }
  // private:

  Subdim		operator[](size_t		idx);
  const Subdim		operator[](size_t		idx) const;

  void			operator=(const Floor		&other);
  bool			operator==(const Floor		&other) const;
  void			operator<<(const Floor		&other);
  void			subdivide(room			parent_room,
				  int			max,
				  t_prog		*pro);

  void			room_connector(room		&mainroom);
  int			room_finder(room		&mainroom);
  void			create_corridor();

  int			number;
  double		max_height;
  //x and y size;
  t_bunny_size		size;
  std::vector<room>	rooms;
  int			special_rooms;
  Tile			tiles[WIDTH_MAP * HEIGHT_MAP];
  ef::Objet		objets[256];
  uint16_t		nb_objets;
  double		base_height;

};
#endif//	 __FLOOR_HH__
