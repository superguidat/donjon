// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 27/11/2025 12:11:30 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"
#include		<arpa/inet.h>

static t_bunny_response	init_prog(t_prog	*pro)
{
  t_connexion		recu;
  int			r;

  std::cout << "Connecté au serveur !" << std::endl;
  if ((r  = recv(pro->fd_sock, &recu, sizeof(recu), 0)) <= 0)
    {
      std::cout << "Impossible de recevoir les données initiales" << std::endl;
      close(pro->fd_sock);
      return EXIT_ON_ERROR;
    }
  pro->nb_client = recu.id+1;
  pro->my_id = recu.id;
  pro->seed_rand = recu.seed;
  pro->me.setPos_cam({
      recu.pos_cam.x,
      recu.pos_cam.y,
      recu.pos_cam.z
    });
  std::cout << "id reçue : " << recu.id
	    << "    Seed reçue : " << recu.seed
	    << "    Position initiale : "
            << recu.pos_cam.x << ", "
            << recu.pos_cam.y << ", "
            << recu.pos_cam.z << std::endl;
  return GO_ON;
}

t_bunny_response	init_reseau_client(t_prog	*pro)
{
  sockaddr_in		serv;

  pro->fd_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (pro->fd_sock < 0)
    {
      perror("Erreur creation socket client");
      return EXIT_ON_ERROR;
    }
  std::memset(&serv, 0, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(11700);
  if (inet_pton(AF_INET, pro->ip, &serv.sin_addr) <= 0)
    {
      std::cout << "Adresse IP invalide !" << std::endl;
      return EXIT_ON_ERROR;
    }
  if (connect(pro->fd_sock, (reinterpret_cast<sockaddr*>(&serv)), sizeof(serv)) < 0)
    {
      perror("Erreur connexion serveur");
      close(pro->fd_sock);
      return EXIT_ON_ERROR;
    }
  return init_prog(pro);
}
