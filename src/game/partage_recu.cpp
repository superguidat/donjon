// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/12/2025 14:23:04 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

void		partage_info(t_prog		*prog,
			     int32_t		i,
			     t_reseau		&recu)
{
  prog->pl[recu.id].setPos_cam({recu.pos_cam.x, recu.pos_cam.y, recu.pos_cam.z});
  for (int32_t l = 1; l < prog->nb_client; l ++)
    {
      if (l != i)
	{
	  std::cout << "id que jenvoie  = " << i
		    << "   id qui recois  = " << l
		    << std::endl;
	  if (prog->client_fd[l].revents & POLLOUT)
	    send(prog->client_fd[l].fd, &recu, sizeof(recu), 0);
	}
    }
}
