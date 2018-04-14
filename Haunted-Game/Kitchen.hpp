/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: Kitchen.hpp is the Kitchen class specification file.
*******************************************************************************/

#ifndef Kitchen_HPP
#define Kitchen_HPP

#include <string>

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

//declaration of class Kitchen
class Kitchen : public Space
{
  //member variables
  private:
    char** gameBoard;

  //member functions
  public:
    Kitchen(Space*, Space*, Space*, Space*);
    void setPlayerMarker(int, int);
    void changePos(Player*, int, int, char);
    void showHint();
    void showMap(bool);
    ~Kitchen();
};
#endif
