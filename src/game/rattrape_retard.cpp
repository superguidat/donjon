// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/12/2025 16:34:36 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			rattrape_retard(t_prog		*prog)
{
  int32_t		r;
  int64_t		li;

  li = 0;
  while (prog->file.size())
    {
      r  = send(prog->client_fd[prog->file[0].sock_id].fd, &prog->file[0], sizeof(t_reseau), 0);
      if (errno == EWOULDBLOCK || errno == EAGAIN || r < (static_cast<int32_t>(sizeof(t_reseau))))
	{
	  li ++;
	  continue ;
	}
      prog->file.erase(prog->file.begin() + li);
    }
}
