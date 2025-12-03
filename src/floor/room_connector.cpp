// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 30/10/2025 15:53:01 ******************************************************
// romain.cescutti <romain.cescutti@debian>
// - donjon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "floor.hh"
#include "room.hh"

void Floor::room_connector(room mainroom)
{
  room *neighbour;
  int i,j,k,x1,y1,x2,y2,turnpoint;
  i = j = k = x1 = y1 = x2 = y2 = turnpoint = 0;
  room::side roomside;
  while(i < (int)mainroom.neighbours.size())
    {
      neighbour = &mainroom.neighbours[i];
      roomside = neighbour->sides[i];
      switch(roomside)
	{
	case room::left:
	y1 = (rand() % (std::max(mainroom.corner[0].y,neighbour->corner[0].y))) + std::min(mainroom.corner[0].y,neighbour->corner[0].y);
	y2 = (rand() % (std::min(mainroom.corner[2].y,neighbour->corner[2].y))) + std::min(mainroom.corner[2].y,neighbour->corner[2].y);
	turnpoint = rand() % (mainroom.corner[0].x -neighbour->corner[1].x);
	x1 = mainroom.corner[0].x;
	x2 = neighbour->corner[3].x;
	j = x2;
	k = y1;
	break;
	case room::right:
	y1 = (rand() % (std::max(mainroom.corner[0].y,neighbour->corner[0].y))) + std::min(mainroom.corner[0].y,neighbour->corner[0].y);
	y2 = (rand() % (std::min(mainroom.corner[2].y,neighbour->corner[2].y))) + std::min(mainroom.corner[2].y,neighbour->corner[2].y);
	turnpoint = rand() % (mainroom.corner[0].x -neighbour->corner[1].x);
	x1 = mainroom.corner[1].x;
	x2 = neighbour->corner[0].x;
	j = x1;
	k = y1;
	break;
	case room::top:
	x1 = (rand() % (std::max(mainroom.corner[0].x,neighbour->corner[0].x))) + std::min(mainroom.corner[0].x,neighbour->corner[0].x) ;
	x2 = (rand() % (std::min(mainroom.corner[2].x,neighbour->corner[2].x))) + std::min(mainroom.corner[2].x,neighbour->corner[2].x);
	turnpoint = rand() % (mainroom.corner[0].y -neighbour->corner[1].y);
	y1 = mainroom.corner[0].y;
	y2 = neighbour->corner[3].y;
	j = y2;
	k = x1;
	break;
	case room::down:
	x1 = (rand() % (std::max(mainroom.corner[0].x,neighbour->corner[0].x))) + std::min(mainroom.corner[0].x,neighbour->corner[0].x) ;
	x2 = (rand() % (std::min(mainroom.corner[2].x,neighbour->corner[2].x))) + std::min(mainroom.corner[2].x,neighbour->corner[2].x);
	turnpoint = rand() % (mainroom.corner[0].y -neighbour->corner[1].y);
	y1 = mainroom.corner[2].y;
	y2 = neighbour->corner[0].y;
	j = y1;
	k = x1;
	break;
	}
      if(mainroom.sides[i] == room::left || mainroom.sides[i] == room::right)
	{
	  while(turnpoint != j)
	    {
	      this->tiles[y1 * size.y + j].setType(0);
	      if (turnpoint == j)
		{
		  k = size.y;
		  while(k != y2)
		    {
		      this->tiles[y1 * k + j].setType(0);
		      k++;
		    }
		}
	    }
	}
      else if(mainroom.sides[i] == room::top || mainroom.sides[i] == room::down)
	{
	  while(turnpoint != j)
	    this->tiles[y1 * size.y + j].setType(0);
	  if (turnpoint == j)
	    {
	      k = size.y;
	      while(k != x2)
		{
		  k++;
		  this->tiles[y1 * k + j].setType(0);
		}
	    }
	}
    }
  i++;
}

int Floor::room_finder(room mainroom)
{
  room neighbour;
  int x;
  int y;
  int i;
  int score;

  i = 0;
  x = mainroom.corner[0].x;
  y = mainroom.corner[0].y;
  while (x > 0 && y < size.y)
    {
      i = 0;
      while(i < 5)
	{
	  x--;
 	  if (tiles[y * size.x + x].getId_room() != 0)
	    {
	      neighbour.id = tiles[y * size.x + x].getId_room();
	    }
	  if (neighbour.id == tiles[y * size.x + x].getId_room())
	    {
	      score++;
	      if (score < 5)
		{
		  mainroom.neighbours.push_back(neighbour);
		  mainroom.connections += 1;
		  //mainroom.sides.push_back()
		  y += (y - neighbour.corner[3].y);
		}
	    }
	  i++;
	}
      if (y < mainroom.corner[3].y)
	x = -1;
      y++;
      x = mainroom.corner[0].x;
    }

  return(mainroom.neighbours.size());
  //left sides checked!
  x = mainroom.corner[1].x;
  y = mainroom.corner[1].y;
  while (x < size.x)
    {
      i = 0;
      while(i < 5)
	{
	  x++;
	  if (neighbour.id == tiles[y * y + x].getId_room())
	    {
	      score++;
	      if (score < 5)
		{
		  mainroom.neighbours.push_back(neighbour);
		  y += (y - neighbour.corner[3].y);
		}
	    }
	  if (tiles[y * x + x].getId_room() != 0)
	    {
	      neighbour = rooms[tiles[y * y + x].getId_room()];
	    }
	  i++;
	}
      if (y < mainroom.corner[3].y)
	x = -1;
      y++;
      x = mainroom.corner[1].x;
    }
  //right side checked!
  x = mainroom.corner[0].x;
  y = mainroom.corner[0].y;
  while (y > 0)
    {
      i = 0;
      while(i < 5)
	{
	  y--;
	  if (neighbour.id == rooms[tiles[y * y + x].getId_room()])
	    {
	      score++;
	      if (score < 5)
		{
		  mainroom.neighbours.push_back(neighbour);
		  y += (y - neighbour.corner[3].y);
		}
	    }
	  if (tiles[y * x + x].getId_room() != 0)
	    {
	      neighbour = rooms[tiles[y * y + x].getId_room()];
	    }
	  i++;
	}
      if (x < mainroom.corner[3].y)
	y = -1;
      x++;
      y = mainroom.corner[0].x;
    }
  //Top side checked!
  x = mainroom.corner[2].x;
  y = mainroom.corner[2].y;
  while (y > 0)
    {
      i = 0;
      while(i < 5)
	{
	  y++;
	  if (neighbour == rooms[tiles[y * y + x].getId_room()])
	    {
	      score++;
	      if (score < 5)
		{
		  mainroom.neighbours.push_back(neighbour);
		  y += (y - neighbour.corner[3].y);
		}
	    }
	  if (tiles[y * x + x].getId_room() != 0)
	    {
	      neighbour = rooms[tiles[y * y + x].getId_room()];
	    }
	  i++;
	}
      if (x < mainroom.corner[3].y)
	y = -1;
      x++;
      y = mainroom.corner[0].x;
    }
  //bottom side checked!
  return(mainroom.neighbours.size());
}
