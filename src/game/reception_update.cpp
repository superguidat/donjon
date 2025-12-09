// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/12/2025 13:21:28 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

static void	update_pos(t_prog		*prog,
			   t_reseau		*recu)
{
  prog->pl[recu->id].setPos_cam({
      recu->pos_cam.x,
      recu->pos_cam.y,
      recu->pos_cam.z
    });
}

static void	suppression_joueur(t_prog	*prog,
				   int32_t	&nb_reception,
				   t_reseau	*recu)
{
  prog->nb_client --;
  prog->pl[recu->id] = prog->pl[prog->nb_client];
  if (prog->nb_client == prog->my_id)
    prog->my_id = recu->id;
  nb_reception --;
}

void		reception_update(t_prog		*prog,
				 char		*buf,
				 int32_t	rd)
{
  int32_t	offset;
  int32_t	nb_reception;
  t_reseau	*recu;

  offset = 0;
  nb_reception = 1;
  while ((static_cast<int32_t>(offset + sizeof(t_reseau))) <= rd)
    {
      nb_reception ++;
      recu = (reinterpret_cast<t_reseau*>(buf + offset));
      std::cout << "id recu  = " << recu->id
		<< "my_id  = " << prog->my_id
		<< std::endl;
      if (prog->nb_client <= nb_reception)
	prog->nb_client = nb_reception;

      if (recu->type == -1)
	suppression_joueur(prog, nb_reception, recu);
      else if (recu->type == 0)
	update_pos(prog, recu);

      offset += sizeof(t_reseau);
    }
}
