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

void		supprime_et_retransmission(t_prog		*prog,
					   int32_t		&i,
					   t_reseau		&recu)
{
  close(prog->client_fd[i].fd);
  prog->client_fd.erase(prog->client_fd.begin() + i);
  std::cout << "¢łieŋt đe¢øŋŋe¢ter  " << prog->client_fd[i].fd << " !" << std::endl;
  prog->nb_client --;
  for (int32_t l = 1; l < prog->nb_client; l ++)
    {
      if (l != i)
	{
	  recu.type = -1;
	  recu.id = i;
	  std::cout << "id que je supprime  = " << i
		    << "   id qui recois  = " << l
		    << std::endl;
	  if (prog->client_fd[l].revents & POLLOUT)
	    send(prog->client_fd[l].fd, &recu, sizeof(recu), 0);
	  prog->pl[i] = prog->pl[prog->nb_client];
	}
    }
  i --;
}
