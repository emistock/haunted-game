/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: Living.hpp is the Living class specification file.
*******************************************************************************/

#ifndef Living_HPP
#define Living_HPP

#include <string>

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

//declaration of class Living
class Living : public Space
{
  //member variables
  private:
    char** gameBoard;

  //member functions
  public:
    Living(Space*, Space*, Space*, Space*);
    void setPlayerMarker(int, int);
    void changePos(Player*, int, int, char);
    void showHint();
    void showMap(bool);
    ~Living();
};
#endif
