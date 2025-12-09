// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/12/2025 14:06:05 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

t_bunny_response	reseau_client_loop(t_prog		*prog)
{
  t_reseau		send_me;
  int32_t		r;
  struct pollfd		p;
  char			buf[1024];
  int			rd;

  p.fd = prog->fd_sock;
  p.events = POLLIN | POLLOUT;
  if ((r = poll(&p, 1, 1)) > 0 && (p.revents & POLLIN))
    {
      if ((rd  = recv(prog->fd_sock, buf, sizeof(buf), 0)) <= 0)
	{
	  std::cout << "Déconnecté du serveur !" << std::endl;
	  close(prog->fd_sock);
	  return EXIT_ON_ERROR;
	}
      reception_update(prog, buf, rd);
    }
  send_me.id = prog->my_id;
  send_me.pos_cam = prog->me.getPos_cam();
  send(prog->fd_sock, &send_me, sizeof(send_me), 0);
  return GO_ON;
}
