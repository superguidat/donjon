/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 09/10/2025 12:30:04 ******************************************************
** romain.cescutti <romain.cescutti@laika.efrits.fr>
** - donjon_master -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef __tile_hh_
#define __tile_hh_

class Tile;
{
 public:
  tile();
 private:
  int type; // 0 null/outside of play range , 1 floor-tile
  double base_height;
  double points_of_elevation[9]; // base_height + 9 pique de + ou - hauteur. = {0} pour avoir aucun changement
}

