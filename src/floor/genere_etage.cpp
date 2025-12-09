#include		"donjon_master.hh"

void			genere_etage(t_prog		&pro,
				     int32_t		*tab,
				     double		base_height)
{
  t_bunny_position	Rcorner[3];
  Floor			mfloor;
  room			tempFloorroom(0, pro.width, 0, pro.height, 7);
  int32_t		j;


  mfloor.subdivide(tempFloorroom, 100, &pro);

  j = mfloor.rooms.size();
  pro.etage[pro.nb_etage] = mfloor;

  for(int32_t i = 0; i < j; i++)
    {
      Rcorner[0] = mfloor.rooms[i].corner[0];
      Rcorner[1] = mfloor.rooms[i].corner[1];
      Rcorner[2] = mfloor.rooms[i].corner[3];
      pro.etage[pro.nb_etage].rooms[i].id = i;
      pro.etage[pro.nb_etage].rooms[i].create(mfloor.tiles, Rcorner, base_height, pro.width);
    }

  mfloor.create_corridor();
  pro.etage[pro.nb_etage].number = pro.etage[pro.nb_etage].rooms.size();
  pro.nb_etage ++;
}
