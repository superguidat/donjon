// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 14:00:34 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			draw_joueur(t_prog				*prog)
{
  t_zposition		posm;

  for (int32_t i = 0 ; i < prog->nb_client; i ++)
    {
      if (prog->my_id == i)
	{
	  continue;
	}
      posm.x = prog->pl[i].getPos_cam().x;
      posm.y = prog->pl[i].getPos_cam().y;
      posm.z = prog->pl[i].getPos_cam().z - 5;
      /*std::cout << "client  = " << i
	<< "  fd = " <<  prog->client_fd[i].fd
	<< "  x = " << posm.x
	<< "  y = " << posm.y
	<< "  z = " << posm.z
	<< std::endl;*/
      //{0.08, 0.08, 1}
      draw_pave_texture(0, posm, {0.8, 0.8, 5}, prog->etage[prog->etage_actuel].objets[0].textID);
    }
}
