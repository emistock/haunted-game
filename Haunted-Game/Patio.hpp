/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: Patio.hpp is the Patio class specification file.
*******************************************************************************/

#ifndef Patio_HPP
#define Patio_HPP

#include <string>

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

//declaration of class Patio
class Patio : public Space
{
  //member variables
  private:
    char** gameBoard;

  //member functions
  public:
    Patio(Space*, Space*, Space*, Space*);
    void setPlayerMarker(int, int);
    void changePos(Player*, int, int, char);
    void showHint();
    void showMap(bool);
    ~Patio();
};
#endif
