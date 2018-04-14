/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: Study.hpp is the Study class specification file.
*******************************************************************************/

#ifndef Study_HPP
#define Study_HPP

#include <string>

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

//declaration of class Study
class Study : public Space
{
  //member variables
  private:
    char** gameBoard;

  //member functions
  public:
    Study(Space*, Space*, Space*, Space*);
    void changePos(Player*, int, int, char);
    void setPlayerMarker(int, int);
    void showHint();
    void showMap(bool);
    ~Study();
};
#endif
