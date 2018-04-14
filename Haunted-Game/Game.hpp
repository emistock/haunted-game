/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/9/17
** Description: Game.hpp is the Game class specification file.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>

#include "Space.hpp"
#include "Player.hpp"
#include "mainHall.hpp"
#include "Bath.hpp"
#include "Bedroom.hpp"
#include "Kitchen.hpp"
#include "Study.hpp"
#include "Living.hpp"
#include "Patio.hpp"
#include "Dining.hpp"

using namespace std;

//declaration of class Game
class Game
{
  //member variables
  private:
    Player* player;
    char choice;

  //member functions
  public:
    Game();
    void play();
    char getUserInput();
    ~Game();
};
#endif
