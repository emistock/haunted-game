/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/14/17
** Description: Bedroom.hpp is the Bedroom class specification file.
*******************************************************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include <string>

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

//declaration of class Bedroom
class Bedroom : public Space
{
  //member variables
  private:
    char** gameBoard;

  //member functions
  public:
    Bedroom(Space*, Space*, Space*, Space*);
    void setPlayerMarker(int, int);
    void changePos(Player*, int, int, char);
    void showHint();
    void showMap(bool);
    ~Bedroom();
};
#endif
