// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/12/2025 14:26:04 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"donjon_master.hh"

bool		new_connexion(t_prog		*prog)
{
  t_connexion	recu;
  int32_t	client;

  std::cout << "id que jenvoie  = " << 0
	    << "   nb_client  = " << prog->nb_client
	    << std::endl;
  if ((recu.id = prog->nb_client) == 10)
    {
      std::cout << "Connexion refuser limite atteinte !" << std::endl;
      return true;
    }
  if ((client = accept(prog->fd_sock, NULL, NULL)) <= 0)
    return true;
  std::cout << "ŋøµvełłe ¢øŋŋexiøŋ " << client << " !" << std::endl;
  prog->nb_client ++;
  recu.seed = prog->seed_rand;
  recu.pos_cam.x = prog->me.getPos_cam().x;
  recu.pos_cam.y = prog->me.getPos_cam().y;
  recu.pos_cam.z = prog->me.getPos_cam().z;
  send(client, &recu, sizeof(recu), 0);
  prog->client_fd.push_back({client, POLLIN, 0});
  return false;
}
