/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/9/17
** Description: A class Space that represents a space in the game. It is an
abstract base class. It has get functions and set functions for all of its
member variables. Its constructor takes four parameters that are pointers to
Space objects and sets them equal to the member variables north, south, east,
and west. 
*******************************************************************************/

//preprocessor directives
#include <string>

#include "Space.hpp"

using namespace std;

Space::Space(Space* n, Space* s, Space* e, Space* w)
{
  north = n;
  south = s;
  east = e;
  west = w;

  goKitchen = false;
  goBedroom = false;
  goBath = false;
  goHall = false;
  goStudy = false;
  goDining = false;
  goPatio = false;
  goLiving = false;
}

string Space::getSpaceName()
{
  return spaceName;
}

void Space::setNorth(Space* n)
{
  north = n;
}

void Space::setSouth(Space* s)
{
  south = s;
}

void Space::setEast(Space* e)
{
  east = e;
}

void Space::setWest(Space* w)
{
  west = w;
}

void Space::setGoKitchen(bool k)
{
  goKitchen = k;
}

void Space::setGoBedroom(bool bed)
{
  goBedroom = bed;
}

void Space::setGoBath(bool bath)
{
  goBath = bath;
}

void Space::setGoHall(bool h)
{
  goHall = h;
}

void Space::setGoStudy(bool s)
{
  goStudy = s;
}

void Space::setGoDining(bool d)
{
  goDining = d;
}

void Space::setGoPatio(bool p)
{
  goPatio = p;
}

void Space::setGoLiving(bool l)
{
  goLiving = l;
}

void Space::setExit(bool e)
{
  goExit = e;
}

bool Space::getGoKitchen()
{
  return goKitchen;
}

bool Space::getGoBedroom()
{
  return goBedroom;
}

bool Space::getGoBath()
{
  return goBath;
}

bool Space::getGoHall()
{
  return goHall;
}

bool Space::getGoStudy()
{
  return goStudy;
}

bool Space::getGoDining()
{
  return goDining;
}

bool Space::getGoPatio()
{
  return goPatio;
}

bool Space::getGoLiving()
{
  return goLiving;
}

bool Space::getExit()
{
  return goExit;
}

Space::~Space()
{
}
