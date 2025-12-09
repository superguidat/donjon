// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 12:00:14 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include			"donjon_master.hh"

t_bunny_response		reseau_hote_client(t_prog		*pro)
{
  if (pro->hote)
    {
      pro->nb_client = 1;
      if (init_reseau(pro) == EXIT_ON_ERROR)
	return EXIT_ON_ERROR;
      pro->seed_rand = static_cast<uint64_t>(time(nullptr));
      std::cout << "seed hote = " << pro->seed_rand << std::endl;
    }
  else
    {
      if (init_reseau_client(pro) == EXIT_ON_ERROR)
	return EXIT_ON_ERROR;
      listen(pro->fd_sock, 42);
    }
  genere_tab_alea(pro);
  pro->client_fd.push_back({pro->fd_sock, POLLIN | POLLOUT, 0});
  return GO_ON;
}
