// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/12/2025 13:50:31 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			applique_deplacement(t_prog		&pro,
					     t_move		&mv,
					     t_map		&map,
					     t_bunny_position	pos)
{
  set_carre_pix(pro.map2, *mv.pnj, INT_MAX);
  for (uint32_t y = mv.pnj->getY() - mv.pnj->getR(); y < mv.pnj->getY() + mv.pnj->getR(); y ++)
    for (uint32_t x = mv.pnj->getX() - mv.pnj->getR(); x < mv.pnj->getX() + mv.pnj->getR(); x ++)
      map.map[map.width * y + x] = INT_MAX;
  mv.pnj->setX(pos.x);
  mv.pnj->setY(pos.y);
  mv.pnj->setA(0);
  mv.pnj->SetColor(TEAL);
  set_carre_pix(pro.map2, *mv.pnj, mv.pnj->getI());
  for (int32_t y = pos.y - mv.pnj->getR(); y < pos.y + mv.pnj->getR(); y ++)
    for (int32_t x = pos.x - mv.pnj->getR(); x < pos.x + mv.pnj->getR(); x ++)
      map.map[map.width * y + x] = -1;
  mv.moved = true;
  mv.pnj->setMove_type(2);
}
