/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: Dining.hpp is the Dining class specification file.
*******************************************************************************/

#ifndef DINING_HPP
#define DINING_HPP

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

//declaration of class Dining
class Dining : public Space
{
  //member variables
  private:
    char** gameBoard;

  //member functions
  public:
    Dining(Space*, Space*, Space*, Space*);
    void setPlayerMarker(int, int);
    void changePos(Player*, int, int, char);
    void showHint();
    void showMap(bool);
    ~Dining();
};
#endif
