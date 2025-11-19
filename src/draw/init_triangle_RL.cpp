#include		"donjon_master.hh"
/*
void			init_triangle_RL(t_zposition	*pos,
					 t_zposition	*posi)
{
  pos[0] = pos[18];//6
  pos[1] = pos[18];//6
  pos[1].z = posi[0].z;//0
  pos[2] = pos[14];//7

  pos[3] = pos[18];//6
  pos[3].z = posi[0].z;//6
  pos[4] = pos[14];//7
  pos[5] = pos[14];//7
  pos[5].z = posi[3].z;//1

  pos[6] = pos[14];//7
  pos[7] = pos[14];//7
  pos[7].z = posi[3].z;//1
  pos[8] = pos[21];//8

  pos[9] = pos[14];//7
  pos[9].z = posi[3].z;//1
  pos[10] = pos[21];//8
  pos[11] = pos[21];//8
  pos[11].z = posi[6].z;//2
}
*/
void			init_triangle_RL(t_zposition	*posf,
					 Tile		&tuil,
					 Tile		&tuil2)
{
  posf[0] = tuil.getPos(2);//2
  posf[1] = tuil.getPos(2);//2
  posf[1].z = tuil2.getPos(0).z;//0
  posf[2] = tuil.getPos(5);//5

  posf[3] = tuil.getPos(2);//2
  posf[3].z = tuil2.getPos(0).z;//0
  posf[4] = tuil.getPos(5);//5
  posf[5] = tuil.getPos(5);//5
  posf[5].z = tuil2.getPos(3).z;//3

  posf[6] = tuil.getPos(5);//5
  posf[7] = tuil.getPos(5);//5
  posf[7].z = tuil2.getPos(3).z;//3
  posf[8] = tuil.getPos(8);//8

  posf[9] = tuil.getPos(5);//7
  posf[9].z = tuil2.getPos(3).z;//3
  posf[10] = tuil.getPos(8);//8
  posf[11] = tuil.getPos(8);//8
  posf[11].z = tuil2.getPos(6).z;//6
}
