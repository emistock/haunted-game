/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/10/17
** Description: A class named Player that represents a player in a text based
game. It allows them to make moves on the game board and stores items in the
pouch of the player.
*******************************************************************************/

//preprocessor directives
#include <iostream>
#include <cstdlib>
#include <limits>

#include "Player.hpp"
#include "inputValidation.hpp"

using namespace std;

/*******************************************************************************
Constructor which initializes member variables
*******************************************************************************/

//initialize member variables
Player::Player()
{
  //player starting position in Main Hall
  xPos = 8;
  yPos = 3;

  numMoves = 0;
  hitPoints = 100;
  isAlive = true;
  hasFlashlight = false;
  hasKey = false;
  hasRope = false;
}

/*******************************************************************************
Returns value of xPos member variable
*******************************************************************************/

int Player::getXPos()
{
  return xPos;
}

/*******************************************************************************
Returns value of yPos member variable
*******************************************************************************/

int Player::getYPos()
{
  return yPos;
}

/*******************************************************************************
Set function for bool member variable hasFlashlight
*******************************************************************************/

void Player::setHasFlashlight(bool flashlight)
{
  hasFlashlight = flashlight;
}

/*******************************************************************************
Set function for bool member variable has key
*******************************************************************************/

void Player::setHasKey(bool key)
{
  hasKey = key;
}

/*******************************************************************************
Get function for member variable numMoves
*******************************************************************************/

int Player::getNumMoves()
{
  return numMoves;
}

/*******************************************************************************
Get function for member variable hasKey
*******************************************************************************/

bool Player::getHasKey()
{
  return hasKey;
}

/*******************************************************************************
Set function for member variable
*******************************************************************************/

void Player::setHasRope(bool rope)
{
  hasRope = rope;
}

/*******************************************************************************
Set function for isAlive member variable
*******************************************************************************/

void Player::setIsAlive(bool life)
{
  isAlive = life;
}

/*******************************************************************************
Get function for member variable hasRope
*******************************************************************************/

bool Player::getHasRope()
{
  return hasRope;
}

/*******************************************************************************
Set function for member variable hitPoints
*******************************************************************************/

void Player::setHitPoints(int p)
{
  hitPoints = p;
}

/*******************************************************************************
Rolls a die with numSides, returns a random number between 1 and numSides
*******************************************************************************/

int Player::rollDie(int numSides)
{
  return rand() % numSides + 1;
}

/*******************************************************************************
Get function for member variable isAlive
*******************************************************************************/

bool Player::getIsAlive()
{
  return isAlive;
}

/*******************************************************************************
Get function for member variable hasFlashlight
*******************************************************************************/

bool Player::getHasFlashlight()
{
  return hasFlashlight;
}

/*******************************************************************************
Allows the player to make a move on the gameboard. numMoves increments with each
call to the function. If numMoves == maxSteps the player dies and the reaper
gets the player.
*******************************************************************************/

void Player::makeMove(int x, int y)
{
  xPos = x;
  yPos = y;

  numMoves++;

  if (numMoves == 200)
  {
    isAlive = false;
    displayImage("reaper.txt");
  }
}

/*******************************************************************************
Adds a string to the vector of items by allocating memory for a string pointer
and adding it to the vector.
*******************************************************************************/

void Player::addItem(string s)
{
  string* i = new string(s);
  items.push_back(i);
}

/*******************************************************************************
Displays the player's inventory of items
*******************************************************************************/

void Player::displayItems()
{
  cout << "*******************************************" << endl;
  cout << " Player Inventory" << endl;
  cout << "*******************************************" << endl;
  cout << endl;
  if (items.empty())
  {
    cout << "You have no items in your inventory. Try exploring." << endl;
  }

  else
  {
    for (unsigned int i = 0; i < items.size(); i++)
    {
      cout << (i + 1) << ". " << *items[i] << endl;
    }
  }
}

/*******************************************************************************
Monster attacks the player with a dice roll and a picture is displayed
*******************************************************************************/

int Player::attack()
{
  //only attack if player is still alive
  if (getIsAlive())
  {
    displayImage("monsters.txt");
    return rollDie(5);
  }

  return 0;
}

/*******************************************************************************
A function that allows the player to defend against monsters if their pouch of
items is not empty with different results for each item. It displays the results
of the monster battle to the screen.
*******************************************************************************/

void Player::defense(int attackAmount)
{
  if (attackAmount == 0)
  {
    return;
  }

  char choice = ' ';
  int itemChoice = 0;
  string itemChoiceStr;

  cout << "You have " << hitPoints << " hitpoints remaining." << endl;

  if (items.empty())
  {
    cout << "The monster attacks for " << attackAmount << endl;
    hitPoints -= attackAmount;
    cout << "You have " << hitPoints << " hitpoints remaining." << endl;
  }

  if (!(items.empty()))
  {
    do
    {
      cout << "Would you like to choose an item to defend? (Y/N)" << endl;

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

    int size = items.size();

    if (choice == 'n')
    {
      cout << "The monster attacks for " << attackAmount << endl;
      hitPoints -= attackAmount;
      cout << "You have " << hitPoints << " hitpoints remaining." << endl;
    }

    if (choice == 'y')
    {
      do
      {
        cout << "Choose an item to defend with: " << endl;

        displayItems();

        cout << "Enter the number of the item: " << endl;

        getline(cin, itemChoiceStr);

        if (inputValidation(itemChoiceStr, 1, (size + 1)))
        {
          itemChoice = stoi(itemChoiceStr);
        }

        else
        {
          cout << "Error, invalid input. Try again." << endl;
          cout << "Select one of those choices." << endl;
        }

      } while(!inputValidation(itemChoiceStr, 1, (size + 1)));

      //subtract one to account for vector index starting at 0

      itemChoice = itemChoice - 1;
      //if the item user chooses is a flashlight
      if (*items[itemChoice] == "flashlight")
      {
        cout << "You throw the flashlight at the monster." << endl;

        //50 % chance of flashlight breaking when thrown
        int roll = rollDie(2);

        if (roll == 1)
        {
          //remove flashlight from user inventory
          swap(items[itemChoice], items.back());
          items.pop_back();

          setHasFlashlight(false);

          cout << "It falls to the ground and breaks." << endl;
        }

        if (roll == 2)
        {
          cout << "It bounces off of the monsters head and has no effect." << endl;
        }

        cout << "The monster attacks for " << attackAmount << endl;
        hitPoints -= attackAmount;
      }

      //if user chooses key, no effect
      if (*items[itemChoice] == "key")
      {
        cout << "You throw the key at the monster." << endl;
        cout << "The key has no effect when thrown at the monster." << endl;

        cout << "The monster attacks for " << attackAmount << endl;
        hitPoints -= attackAmount;
      }

      //if user chooses rope, no effect
      if (*items[itemChoice] == "rope")
      {
        cout << "You throw the rope at the monster." << endl;
        cout << "The rope has no effect when thrown at the monster." << endl;

        cout << "The monster attacks for " << attackAmount << endl;
        hitPoints -= attackAmount;
      }

      //if user chooses towel, monster does not attack
      if (*items[itemChoice] == "towel")
      {
        cout << "You place the towel over your head." << endl;
        cout << "The monster thinks you are a ghost and ignores your presence." << endl;
      }

      //if user chooses helmet, helmet becomes armor
      if (*items[itemChoice] == "helmet")
      {
        int armor = 4;

        cout << "You have 4 armor points from the helmet." << endl;
        if ((attackAmount - armor) > 0)
        {
          cout << "The monster attacks for " << attackAmount << endl;

          cout << "You take " << (attackAmount - armor) << " points in damage" << endl;
          hitPoints -= (attackAmount - armor);
        }

        if ((attackAmount - armor) <= 0)
        {
          cout << "Your armor absorbs the attack and you take no damage." << endl;
        }
      }

      //chance of attacking monster first if user rolls a higher or equal value
      //player takes no damage if they attack first
      if (*items[itemChoice] == "knife")
      {
        int roll2 = rollDie(8);

        if (roll2 >= attackAmount)
        {
          cout << "You manage to attack the monster first." << endl;
          cout << "He gets scared and runs off into the distance." << endl;
        }

        else
        {
          cout << "You fail to attack the monster before he attacks you." << endl;
          cout << "The monster attacks for " << attackAmount << endl;
          hitPoints -= attackAmount;
        }
      }

      cout << "You have " << hitPoints << " hitpoints remaining." << endl;
    }
  }

  cout << "Press enter to continue..." << endl;

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (hitPoints <= 0)
  {
    isAlive = false;
  }
}

/*******************************************************************************
Destructor for deallocating memory
*******************************************************************************/

Player::~Player()
{
  for (unsigned int i = 0; i < items.size(); i++)
  {
    delete items[i];
  }
}
