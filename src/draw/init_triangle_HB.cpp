#include		"donjon_master.hh"
/*
void			init_triangle_HB(t_zposition	*pos,
					 t_zposition	*posi)
{
  pos[0] = pos[6];//2
  pos[1] = pos[6];//0
  pos[1].z = posi[0].z;//0
  pos[2] = pos[5];//5

  pos[3] = pos[5];//3
  pos[3].z = posi[13].z;//3
  pos[4] = pos[5];//5
  pos[5] = pos[6];//0
  pos[5].z = posi[0].z;//0

  pos[6] = pos[4];//5
  pos[7] = pos[4];//3
  pos[7].z = posi[13].z;//3
  pos[8] = pos[21];//8

  pos[9] = pos[21];//6
  pos[9].z = posi[18].z;//6
  pos[10] = pos[4];//3
  pos[10].z = posi[13].z;//3
  pos[11] = pos[21];//8
}
*/
void			init_triangle_HB(t_zposition	*posf,
					 Tile		&tuil,
					 Tile		&tuil2)
{
  posf[0] = tuil.getPos(6);//6
  posf[1] = tuil2.getPos(0);//0
  posf[2] = tuil2.getPos(1);//1

  posf[3] = tuil.getPos(6);//6
  posf[4] = tuil.getPos(7);//7
  posf[5] = tuil2.getPos(1);//1

  posf[6] = tuil.getPos(7);//7
  posf[7] = tuil2.getPos(1);//1
  posf[8] = tuil2.getPos(2);//2

  posf[9] = tuil.getPos(7);//7
  posf[10] = tuil.getPos(8);//8
  posf[11] = tuil2.getPos(2);//2
}
