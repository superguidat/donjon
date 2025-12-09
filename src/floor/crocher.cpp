// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 09/12/2025 11:32:36 ******************************************************
// romain.cescutti <romain.cescutti@debian>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"floor.hh"

Subdim		Floor::operator[](size_t		idx)
{
  return (Subdim{tile[idx].pos,tile[idx].id,tile[idx].x,tile[idx].y});
}

const Subdim	Floor::operator[](size_t		idx) const
{
  return (Subdim{tile[idx].pos,tile[idx].id,tile[idx].x,tile[idx].y});
}
