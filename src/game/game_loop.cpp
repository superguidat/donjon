// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 27/11/2025 12:17:00 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include			"donjon_master.hh"

extern "C"

t_bunny_response                game_loop(t_prog			*prog)
{
  int32_t			res;

  if (prog->hote)
    {
      if ((res = poll(prog->client_fd.data(), prog->client_fd.size(), 1)) > 0)
	{
	  for (int32_t i = 0; i < (static_cast<int32_t>(prog->client_fd.size())); i ++)
	    {
	      if (prog->client_fd[i].fd == prog->fd_sock
		  && (prog->client_fd[i].revents & POLLIN))
		{
		  if (new_connexion(prog))
		    continue;
		}
	      else if (prog->client_fd[i].revents & POLLIN)
		{
		  t_reseau	recu;;
		  int32_t	r;

		  r = recv(prog->client_fd[i].fd , &recu, sizeof(t_reseau), 0);
		  if (r <= 0)
		    supprime_et_retransmission(prog, i, recu);
		  else
		    partage_info(prog, i, recu);
		}
	      else
		{
		  int32_t	r = 0;
		  t_reseau_ext	host;

		  partage_host(prog, r, host);
		  rattrape_retard(prog);
		}
	    }
	}
    }
  else
    if (reseau_client_loop(prog) == EXIT_ON_ERROR)
      return EXIT_ON_ERROR;

  if (prog->ecran == 0)
    {
      mouvement(*prog);
      if (bunny_get_keyboard()[BKS_PAGEUP])
	prog->pos.z -= 0.02;
      else if (bunny_get_keyboard()[BKS_PAGEDOWN])
	prog->pos.z += 0.02;
      /*  else
	  {
	  if (prog->me.getPos_cam().z >= 0.001)
	  prog->me.appendPos_cam({0, 0, -0.05});
	  prog->pos.z *= 0.99;
	  }*/
      if (!prog->deb)
	saut_graviter(*prog);
    }
  else
    {
      t_bunny_position *pos;
      pos = (const_cast<t_bunny_position*>(bunny_get_mouse_position()));
      pos->x = pos->x % prog->win->buffer.width;
      pos->y = pos->y % prog->win->buffer.height;
    }
  //move_units(*prog);
  return (GO_ON);
}
