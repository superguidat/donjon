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

void Floor::room_connector(room mainroom)
{
  room *neighbour;
  int i,j,k,x1,y1,x2,y2,turnpoint= 0;
  side roomside;
  while(i < mainroom.neighbours.size())
    {
      neighbour = mainroom.neighbours[i];
      roomside = neighbour.side;
      switch(roomside)
	{
	case left:
	y1 = (rand() % (max(mainroom.corner[0].y,neighbour.corner[0].y))) + min(mainroom.corner[0].y,neighbour.corner[0].y);
	y2 = (rand() % (min(mainroom.corner[2].y,neighbour.corner[2].y))) + min(mainroom.corner[2].y,neighbour.corner[2].y);
	turnpoint = rand() % (mainroom.corner[0].x -neighbour.corner[1].x);
	x1 = mainroom.corner[0].x;
	x2 = neighbour.corner[3].x;
	j = x2;
	k = y1;
	break;
	case right:
	y1 = (rand() % (max(mainroom.corner[0].y,neighbour.corner[0].y))) + min(mainroom.corner[0].y,neighbour.corner[0].y);
	y2 = (rand() % (min(mainroom.corner[2].y,neighbour.corner[2].y))) + min(mainroom.corner[2].y,neighbour.corner[2].y);
	turnpoint = rand() % (mainroom.corner[0].x -neighbour.corner[1].x);
	x1 = mainroom.corner[1].x;
	x2 = neighbour.corner[0].x;
	j = x1;
	k = y1;
	break;
	case top:
	x1 = (rand() % (max(mainroom.corner[0].x,neighbour.corner[0].x))) + min(mainroom.corner[0].x,neighbour.corner[0].x) ;
	x2 = (rand() % (min(mainroom.corner[2].x,neighbour.corner[2].x))) + min(mainroom.corner[2].x,neighbour.corner[2].x);
	turnpoint = rand() % (mainroom.corner[0].y -neighbour.corner[1].y);
	y1 = mainroom.corner[0].y;
	y2 = neighbour.corner[3].y;
	j = y2;
	k = x1;
	break;
	case down:
	x1 = (rand() % (max(mainroom.corner[0].x,neighbour.corner[0].x))) + min(mainroom.corner[0].x,neighbour.corner[0].x) ;
	x2 = (rand() % (min(mainroom.corner[2].x,neighbour.corner[2].x))) + min(mainroom.corner[2].x,neighbour.corner[2].x);
	turnpoint = rand() % (mainroom.corner[0].y -neighbour.corner[1].y);
	y1 = mainroom.corner[2].y;
	y2 = neighbour.corner[0].y;
	j = y1;
	k = x1;
	break;
	}
      if(mainroom.sides[i] == left || mainroom.sides[i] == right)
	{
	  while()
	    {
	      this->tiles[y1 * y + j].getType() = 1;
	      if (turnpoint == j)
		{
		  while(k != y2)
		    {
		      k++;
		      this->tiles[y1 * k + j];
		    }
		}
	    }
	  else if(mainroom.sides[i] == top || mainroom.sides[i] == down)
	    {
	      while()
		this->tiles[y1 * y + j].getType() = 1;
	      if (turnpoint == j)
		{
		  while(k != x2)
		    {
		      k++;
		      this->tiles[y1 * k + j];
		    }
		}
	    }
	}
      i++;
    }
}

int Floor::room_finder(room mainroom)
{
  room neighbour;
  int searchx;
  int searchy;
  int i;
  int score;
  i = 0;
  searchx = mainroom.corner[0].x;
  searchy = mainroom.corner[0].y;
  while (searchx > 0)
    {
      i = 0;
      while(i < 5)
	{
	  searchx--;
	  if (neighbour == *tiles[searchy * y + searchx].getRoom())
	    {
	      score++;
	      if (score < 5)
		{
		  mainroom.neighbours.push_back(neighbour);
		  mainroom.connections += 1;
		  //mainroom.sides.push_back()
		  searchy += (searchy - neighbour.corner[3].y);
		}
	    }
	  if (tiles[searchy * x + searchx].getRoom() != NULL)
	    {
	      neighbour = tiles[searchy * y + searchx].getRoom();
	    }
	  i++;
	}
      if (searchy < mainroom.corner[3].y)
	searchx = -1;
      searchy++;
      searchx = mainroom.corner[0].x;
    }
  //left sides checked!
  searchx = mainroom.corner[1].x;
  searchy = mainroom.corner[1].y;
  while (searchx < x)
    {
      i = 0;
      while(i < 5)
	{
	  searchx++;
	  if (neighbour == *tiles[searchy * y + searchx].getRoom())
	    {
	      score++;
	      if (score < 5)
		{
		  mainroom.neighbours.push_back(neighbour);
		  searchy += (searchy - neighbour.corner[3].y);
		}
	    }
	  if (tiles[searchy * x + searchx].getRoom() != NULL)
	    {
	      neighbour = tiles[searchy * y + searchx].getRoom();
	    }
	  i++;
	}
      if (searchy < mainroom.corner[3].y)
	searchx = -1;
      searchy++;
      searchx = mainroom.corner[1].x;
    }
  //right side checked!
  searchx = mainroom.corner[0].x;
  searchy = mainroom.corner[0].y;
  while (searchy > 0)
    {
      i = 0;
	while(i < 5)
	  {
	    searchy--;
	    if (neighbour == *tiles[searchy * y + searchx].getRoom())
	      {
		score++;
		if (score < 5)
		  {
		    mainroom.neighbours.push_back(neighbour);
		    searchy += (searchy - neighbour.corner[3].y);
		  }
	      }
	    if (tiles[searchy * x + searchx].getRoom() != NULL)
	      {
		neighbour = tiles[searchy * y + searchx].getRoom();
	      }
	    i++;
	  }
      if (searchx < mainroom.corner[3].y)
	searchy = -1;
      searchx++;
      searchy = mainroom.corner[0].x;
    }
  //Top side checked!
  searchx = mainroom.corner[2].x;
  searchy = mainroom.corner[2].y;
  while (searchy > 0)
    {
      i = 0;
	while(i < 5)
	  {
	    searchy++;
	    if (neighbour == *tiles[searchy * y + searchx].getRoom())
	      {
		score++;
		if (score < 5)
		  {
		    mainroom.neighbours.push_back(neighbour);
		    searchy += (searchy - neighbour.corner[3].y);
		  }
	      }
	    if (tiles[searchy * x + searchx].getRoom() != NULL)
	      {
		neighbour = tiles[searchy * y + searchx].getRoom();
	      }
	    i++;
	  }
      if (searchx < mainroom.corner[3].y)
	searchy = -1;
      searchx++;
      searchy = mainroom.corner[0].x;
    }
  //bottom side checked!
  return(mainroom.neighbours.size());
}
