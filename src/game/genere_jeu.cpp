// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 12:08:17 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"donjon_master.hh"

void			genere_jeu(t_prog		*pro,
				   uint16_t		hauteur_sous_plafond,
				   uint16_t		nb_etage)
{
  int32_t		tab[WIDTH_MAP * HEIGHT_MAP];
  int32_t		h;

  h = 0;
  for (int32_t m = 0; m < 1; m ++)
    {
      //      for (int32_t y = 0; y < pro->map->clipable.buffer.height; y ++)
	//	for (int32_t x = 0; x < pro->map->clipable.buffer.width; x ++)
	  //	  ((uint32_t *)(pro->map2[m]->pixels))[y * pro->map2->clipable.buffer.width + x] = INT_MAX;
      genere_etage(*pro, tab, h);
      genere_floor(pro->width, pro->height, pro->etage[pro->nb_etage-1], tab, h);
      pro->etage[pro->nb_etage-1].max_height = hauteur_sous_plafond;
      init_tiles(pro, pro->etage[pro->nb_etage-1], pro->nb_etage-1);

      h += hauteur_sous_plafond;

      genere_etage(*pro, tab, h);
      genere_floor(pro->width, pro->height, pro->etage[pro->nb_etage-1], tab, h);
      pro->etage[pro->nb_etage-1].max_height = hauteur_sous_plafond;
      init_tiles(pro, pro->etage[pro->nb_etage-1], pro->nb_etage-1);

      h += hauteur_sous_plafond;
      //std::cout << "\nmap bas = " << m << "   map haut = " << m + 1 << std::endl;
    }
  pro->sous_bas<<pro->etage[0];
  pro->bas<<pro->etage[1];
  pro->haut<<pro->etage[2];
}
