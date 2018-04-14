/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: A class Dining which inherits from class Space. It represents a
room in the game.
*******************************************************************************/

//preprocessor directives
#include <string>
#include <iostream>

#include "Dining.hpp"

using namespace std;

/*******************************************************************************
Constructor which calls Space constructor to initialize member variables
*******************************************************************************/
Dining::Dining(Space* n, Space* s, Space* e, Space* w) : Space(n, s, e, w)
{
  spaceName = "Dining Room";
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

  //create special tiles;
  gameBoard[6][3] = '*';
  gameBoard[2][2] = '*';

  //create doors
  //door to patio
  gameBoard[numRows / 2][0] = 'D';

  //door to living
  gameBoard[numRows - 1][numCols / 2] = 'D';
}

/*******************************************************************************
Changes the position of the player marker depending on where the walls and doors
are on the gameBoard. It prevents the player from going out of bounds.
*******************************************************************************/
void Dining::changePos(Player* p, int x, int y, char input)
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
      return;
    }

    //player is attempting to enter next room
    else if (gameBoard[newX][newY] == 'D')
    {
      //change player position before switching rooms so user is by the door
      //in new room
      p->makeMove(1, 3);

      goPatio = true;;
      return;
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
      return;
    }

    //player is attempting to enter next room
    else if (gameBoard[newX][newY] == 'D')
    {
      //change player position before switching rooms so user is by the door
      //in new room
      p->makeMove(1, 2);
      goLiving = true;
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

    char choice;

    //if player survives the attack, show candy or apple
    if (p->getIsAlive())
    {
      if (p->getXPos() == 2 && p->getYPos() == 2)
      {
        displayImage("candy.txt");

        do
        {
          cout << "Would you like to eat the candy? (Y/N)" << endl;

          cin >> choice;

          //accept lowercase and uppercase input, convert to lowercase
          if (choice == 'y' || choice == 'n' || choice == 'Y' || choice == 'N')
          {
            choice = tolower(choice);
          }

          //if user does not enter a valid choice, alert user
          else
          {
            cout << "Invalid input, please try again." << endl;
          }

        } while (choice != 'y' && choice != 'n');

        //ignore last character in buffer
        cin.ignore();

        if (choice == 'y')
        {
          //player health restored
          p->setHitPoints(100);

          cout << "You have been restored to full health!" << endl;
          cout << "You have 100 hitpoints remaining." << endl;

          cout << "Press enter to continue..." << endl;

          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        showMap(p->getHasFlashlight());
      }

      if (p->getXPos() == 6 && p->getYPos() == 3)
      {
        displayImage("apple.txt");

        do
        {
          cout << "Would you like to eat the apple? (Y/N)" << endl;

          cin >> choice;

          //accept lowercase and uppercase input, convert to lowercase
          if (choice == 'y' || choice == 'n' || choice == 'Y' || choice == 'N')
          {
            choice = tolower(choice);
          }

          //if user does not enter a valid choice, alert user
          else
          {
            cout << "Invalid input, please try again." << endl;
          }

        } while (choice != 'y' && choice != 'n');

        if (choice == 'y')
        {
          //player dies
          p->setIsAlive(false);
        }

        if (choice == 'n')
        {
          showMap(p->getHasFlashlight());
        }

        //ignore last character in buffer
        cin.ignore();
      }
    }
  }
}

/*******************************************************************************
Displays a hint for the room
*******************************************************************************/
void Dining::showHint()
{
  cout << "The items in here may restore your health or kill you." << endl;
  cout << "The patio is to the west." << endl;
  cout << "The living room is to the south." << endl;
}

/*******************************************************************************
Displays a map for the room if user has the item flashlight
*******************************************************************************/
void Dining::showMap(bool flashlight)
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
void Dining::setPlayerMarker(int x, int y)
{
  gameBoard[x][y] = 'O';
}

/*******************************************************************************
Destructor that deallocates memory
*******************************************************************************/
Dining::~Dining()
{
  //deallocate memory to prevent memory leaks
  for (int i = 0; i < numRows; i++)
  {
    delete [] gameBoard[i];
  }

  delete [] gameBoard;
}
