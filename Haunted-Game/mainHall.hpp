/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/14/17
** Description: mainHall.hpp is the mainHall class specification file.
*******************************************************************************/

#ifndef MAINHALL_HPP
#define MAINHALL_HPP

#include <string>

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

//declaration of class mainHall
class mainHall : public Space
{
  //member variables
  private:
    char** gameBoard;

  //member functions
  public:
    mainHall(Space*, Space*, Space*, Space*);
    void setPlayerMarker(int, int);
    void changePos(Player*, int, int, char);
    void showHint();
    void showMap(bool);
    ~mainHall();
};
#endif
