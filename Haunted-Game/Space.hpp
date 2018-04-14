/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/9/17
** Description: Space.hpp is the Space class specification file.
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

#include "Player.hpp"
#include <limits>

using namespace std;

//declaration of class Space
class Space
{
  //member variables
  protected:
    Space* north;
    Space* south;
    Space* east;
    Space* west;
    string spaceName;
    int numRows;
    int numCols;
    bool goKitchen;
    bool goBedroom;
    bool goBath;
    bool goHall;
    bool goStudy;
    bool goDining;
    bool goPatio;
    bool goLiving;
    bool goExit;

  //member functions
  public:
    Space(Space*, Space*, Space*, Space*);
    string getSpaceName();
    void setNorth(Space*);
    void setSouth(Space*);
    void setEast(Space*);
    void setWest(Space*);
    void setGoKitchen(bool);
    void setGoBedroom(bool);
    void setGoBath(bool);
    void setGoHall(bool);
    void setGoStudy(bool);
    void setGoDining(bool);
    void setGoPatio(bool);
    void setGoLiving(bool);
    void setExit(bool);
    bool getGoKitchen();
    bool getGoBedroom();
    bool getGoBath();
    bool getGoHall();
    bool getGoStudy();
    bool getGoDining();
    bool getGoPatio();
    bool getGoLiving();
    bool getExit();
    virtual void setPlayerMarker(int, int) = 0;
    virtual void changePos(Player*, int, int, char) = 0;
    virtual void showHint() = 0;
    virtual void showMap(bool) = 0;
    virtual ~Space();
};
#endif
