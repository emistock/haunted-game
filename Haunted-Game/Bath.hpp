/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/14/17
** Description: Bath.hpp is the Bath class specification file.
*******************************************************************************/

#ifndef Bath_HPP
#define Bath_HPP

#include <string>

#include "Player.hpp"
#include "Space.hpp"

using namespace std;

//declaration of class Bath
class Bath : public Space
{
  //member variables
  private:
    char** gameBoard;

  //member functions
  public:
    Bath(Space*, Space*, Space*, Space*);
    void changePos(Player*, int, int, char);
    void setPlayerMarker(int, int);
    void showHint();
    void showMap(bool);
    ~Bath();
};
#endif
