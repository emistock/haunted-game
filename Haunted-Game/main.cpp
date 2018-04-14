/*******************************************************************************
** Program Name: main.cpp
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: A program that allows the user to play a text based game.
There are eight different rooms, each designated by a class which inherits from
class Space. Some items (key, rope) are necessary to beat the game.
There is a class Player that represents the player playing the game. There is a
class Game, which allows allow the player to play the game, calls functions from
Player and Space derives classes, and prints if they win or loose. There are two
ways for the player to lose the game. They can die from using an item or die
from monster attacks, or they can take too long to escape. In order to win the
game, the player must obtain a key from the bedroom that unlocks the study.
This then allows the player to pick up the rope from the study, which can be
used on the exit in the patio to exit the building.

ASCII art used in this game was obtained from the website
http://www.oocities.org/spunk1111/ with the exception of the text art which was
created with a generator from the website
http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
*******************************************************************************/

//preprocessor directive
#include <iostream>
#include <ctime>
#include <cstdlib>

//header files
#include "Game.hpp"
#include "menu.hpp"

using namespace std;

int main()
{
  //seed random number generator
  srand((unsigned)time(NULL));

  int choice = menu();

  if (choice == 2)
  {
    return 0;
  }

  displayImage("haunted.txt");

  do
  {
    //create Game object
    Game game;

    //start the game
    game.play();

    cout << endl;

    //display menus again once game is finished
    choice = menu();

  } while(choice != 2);

  return 0;
}
