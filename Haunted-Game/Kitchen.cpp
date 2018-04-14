/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: A class Kitchen which inherits from class Space. It represents a
room in the game.
*******************************************************************************/

//preprocessor directives
#include <string>
#include <iostream>

#include "Kitchen.hpp"

using namespace std;

/*******************************************************************************
Constructor which calls Space constructor to initialize member variables
*******************************************************************************/
Kitchen::Kitchen(Space* n, Space* s, Space* e, Space* w) : Space(n, s, e, w)
{
  spaceName = "Kitchen";
  numRows = 9;
  numCols = 9;

  gameBoard = new char*[numRows];

  for (int i = 0; i < numRows; i++)
  {
    gameBoard[i] = new char[numCols];
  }

  //create gameboard with border
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numCols; j++)
    {
      gameBoard[i][j] = ' ';
    }
  }

  for (int j = 0; j < numCols; j++)
  {
    gameBoard[0][j] = '.';
  }

  for (int j = 0; j < numCols; j++)
  {
    gameBoard[numRows - 1][j] = '.';
  }

  for (int i = 0; i < numRows; i++)
  {
    gameBoard[i][0] = '.';
  }

  for (int i = 0; i < numRows; i++)
  {
    gameBoard[i][numCols - 1] = '.';
  }

  //create special item tile;
  gameBoard[6][6] = '*';

  //create doors
  //door to patio
  gameBoard[0][(numCols / 2)] = 'D';

  //door to hall
  gameBoard[numRows - 1][(numCols / 2)] = 'D';

  //door to study
  gameBoard[numRows / 2][0] = 'D';

  //door to living
  gameBoard[numRows / 2][numCols - 1] = 'D';
}

/*******************************************************************************
Changes the position of the player marker depending on where the walls and doors
are on the gameBoard. It prevents the player from going out of bounds.
*******************************************************************************/
void Kitchen::changePos(Player* p, int x, int y, char input)
{
  gameBoard[x][y] = ' ';

  int newX = 0;
  int newY = 0;

  //player goes up
  if (input == 'w')
  {
    newX = (x - 1);
    newY = y;

    //player hits upper wall
    if (gameBoard[newX][newY] == '.')
    {
      cout << "You cannot move into a solid wall." << endl;
      return;
    }

    //player is attempting to enter next room
    else if (gameBoard[newX][newY] == 'D')
    {
      //change player position before switching rooms so user is by the door
      //in new room
      p->makeMove(1, 2);
      goPatio = true;
      return;
    }
  }

  //player goes left
  if (input == 'a')
  {
    newX = x;
    newY = (y - 1);

    //player hits left wall
    if (gameBoard[newX][newY] == '.')
    {
      cout << "You cannot move into a solid wall." << endl;
      return;
    }

    //player is attempting to enter next room
    else if (gameBoard[newX][newY] == 'D')
    {

      //if player has key, open the door and go to next room
      if (p->getHasKey())
      {
        cout << "You use your key to unlock the door of the study." << endl;
        //change player position before switching rooms so user is by the door
        //in new room

        cout << "Press enter to continue..." << endl;

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        p->makeMove(3, 3);
        goStudy = true;
        return;
      }

      //otherwise tell user they need a key
      else
      {
        cout << "You push against the door but your efforts are useless." << endl;
        cout << "The door appears to be locked." << endl;
        cout << "If only there was an item somewhere that could open it..." << endl;
        return;
      }
    }
  }

  //player goes right
  if (input == 'd')
  {
    newX = x;
    newY = (y + 1);

    //player hits right wall
    if (gameBoard[newX][newY] == '.')
    {
      cout << "You cannot move into a solid wall." << endl;
      return;
    }

    //player is attempting to enter next room
    else if (gameBoard[newX][newY] == 'D')
    {
      //change player position before switching rooms so user is by the door
      //in new room
      p->makeMove(2, 1);
      goLiving = true;
      return;
    }
  }

  //player goes down
  if (input == 's')
  {
    newX = (x + 1);
    newY = y;

    //player hits bottom wall
    if (gameBoard[newX][newY] == '.')
    {
      cout << "You cannot move into a solid wall." << endl;
      return;
    }

    //player is attempting to enter next room
    else if (gameBoard[newX][newY] == 'D')
    {
      //change player position before switching rooms so user is by the door
      //in new room
      p->makeMove(1, 3);
      goHall = true;
      return;
    }
  }

  char under;

  gameBoard[x][y] = ' ';
  under = gameBoard[newX][newY];

  p->makeMove(newX, newY);

  //place player character
  gameBoard[newX][newY] = 'O';

  showMap(p->getHasFlashlight());

  int attackChance = 0;
  int monsterAttack = 0;

  //20% chance of monster attack on normal tile
  if (under == ' ')
  {
    attackChance = p->rollDie(5);

    if (attackChance == 1)
    {
      monsterAttack = p->attack();
      p->defense(monsterAttack);
      showMap(p->getHasFlashlight());
    }
  }

  //50% chance of monster attack on item tile
  if (under == '*')
  {
    attackChance = p->rollDie(2);

    if (attackChance == 1)
    {
      monsterAttack = p->attack();
      p->defense(monsterAttack);
      showMap(p->getHasFlashlight());
    }

    //if player survives the attack, give them the item on the square
    if (p->getIsAlive())
    {
      displayImage("knife.txt");
      p->addItem("knife");
      showMap(p->getHasFlashlight());
    }
  }
}

/*******************************************************************************
Displays a hint for the room
*******************************************************************************/
void Kitchen::showHint()
{
  cout << "The item in here may be useful for defending against monsters." << endl;
  cout << "The patio is to the north." << endl;
  cout << "The hall is to the south." << endl;
  cout << "The study is to the west." << endl;
  cout << "The living room is to the east." << endl;
  cout << "The study requires a key from another location to enter." << endl;
}

/*******************************************************************************
Displays a map for the room if user has the item flashlight
*******************************************************************************/
void Kitchen::showMap(bool flashlight)
{
  cout << "\033[2J\033[1;1H";
  cout << "*******************************************" << endl;
  cout << " Game Menu" << endl;
  cout << "*******************************************" << endl;
  cout << " 'w' - move north     's' - move south" << endl;
  cout << " 'a' - move west      'd' - move east" << endl;
  cout << " 'i' - show items     'h' - show room hint" << endl;
  cout << " 'c' - show game cheats" << endl;
  cout << endl;
  cout << "*******************************************" << endl;
  cout << " Game Key" << endl;
  cout << "*******************************************" << endl;
  cout << " D = door  * = item tile  E = exit to house" << endl;
  cout << endl;
  cout << "*******************************************" << endl;
  cout << " " << getSpaceName() << endl;
  cout << "*******************************************" << endl;
  cout << endl;

  //display map only if user has a flashlight
  if (flashlight)
  {
    for (int i = 0; i < numRows; i++)
    {
      for (int j = 0; j < numCols; j++)
      {
        cout << gameBoard[i][j];
      }

      cout << endl;
    }
  }

  else
  {
    return;
  }
}

/*******************************************************************************
Function for placing a player marker on the gameBoard
*******************************************************************************/
void Kitchen::setPlayerMarker(int x, int y)
{
  gameBoard[x][y] = 'O';
}

/*******************************************************************************
Destructor that deallocates memory
*******************************************************************************/
Kitchen::~Kitchen()
{
  //deallocate memory to prevent memory leaks
  for (int i = 0; i < numRows; i++)
  {
    delete [] gameBoard[i];
  }

  delete [] gameBoard;
}
