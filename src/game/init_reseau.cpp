// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 26/11/2025 11:02:12 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include			"donjon_master.hh"

static t_bunny_response		bind_listen(t_prog		*pro,
					    sockaddr_in		 *adl)
{
  if (bind(pro->fd_sock, (reinterpret_cast<sockaddr*>(adl)), sizeof((*adl))) < 0)
    {
      perror("erreur sur bind\n");
      close(pro->fd_sock);
      return EXIT_ON_ERROR;
    }
  if (listen(pro->fd_sock, 42) < 0)
    {
      perror("erreur sur listen\n");
      close(pro->fd_sock);
      return EXIT_ON_ERROR;
    }
  std::cout << "Serveur en écoute sur le port 11700" << std::endl;
  return GO_ON;
}

t_bunny_response		init_reseau(t_prog		*pro)
{
  int32_t			opt = 1;
  sockaddr_in			adl;

  if ((pro->fd_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
      perror("erreur creation de la socket\n");
      return EXIT_ON_ERROR;
    }
  setsockopt(pro->fd_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  std::memset(&adl, 0, sizeof(adl));
  adl.sin_family = AF_INET;
  adl.sin_port = htons(11700);
  adl.sin_addr.s_addr = INADDR_ANY;
  return bind_listen(pro, &adl);
}
