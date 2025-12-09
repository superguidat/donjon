// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/12/2025 16:14:01 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			partage_host(t_prog		*prog,
				     int32_t		r,
				     t_reseau_ext	&host)
{
  host.type = 0;
  host.id = 0;
  host.pos_cam.x = prog->me.getPos_cam().x;
  host.pos_cam.y = prog->me.getPos_cam().y;
  host.pos_cam.z = prog->me.getPos_cam().z;
  for (int32_t l = 1; l < prog->nb_client; l ++)
    {
      //if (prog->client_fd[l].revents & POLLOUT)

      if ((r  = send(prog->client_fd[l].fd, &host, sizeof(t_reseau), 0)) < 0)
	{
	  if (errno == EWOULDBLOCK || errno == EAGAIN || r < (static_cast<int32_t>(sizeof(t_reseau))))
	    {
	      // Le socket n'est pas prêt à écrire (non-blocking)
	      // -> ce n'est pas une erreur fatale
	      host.sock_id = l;
	      prog->file.push_back(host);
	    }
	}
      else if (r < (static_cast<int32_t>(sizeof(t_reseau))))
	{
	  host.sock_id = l;
	  prog->file.push_back(host);
	}
    }
}
