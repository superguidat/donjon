#include		"donjon_master.hh"

void			init_triangle_LR(t_zposition	*pos,
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
