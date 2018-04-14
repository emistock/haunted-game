/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/15/17
** Description: A class Game that allows a user to play the game.
*******************************************************************************/

//preprocessor directives
#include <iostream>
#include <limits>

#include "Game.hpp"

using namespace std;

/*******************************************************************************
Constructor that initializes player pointer
*******************************************************************************/
Game::Game()
{
  player = new Player();
}

/*******************************************************************************
Gets user input and returns it
*******************************************************************************/
char Game::getUserInput()
{
  char choice;

  do
  {
    cout << endl;
    cout << "Enter your move:" << endl;

    cin >> choice;

    if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd' ||
        choice == 'i' || choice == 'h' || choice == 'c')
    {
      return choice;
    }

    //if user does not enter a valid choice, alert user
    else
    {
      cout << "Invalid input, please try again." << endl;
    }

  } while (choice != 'w' && choice != 'a' && choice != 's' && choice != 'd' &&
          choice != 'i' && choice != 'h' && choice != 'c');

  return 0;
}

/*******************************************************************************
Plays the game by calling functions from Space derived classes and the class
Player. It creates pointers to 8 Space objects representing linked rooms in the
game and deallocates memory when finished.
*******************************************************************************/
void Game::play()
{
  cout << "\033[2J\033[1;1H";

  cout << "You awaken in a pitch black room. You can’t remember how you got" << endl;
  cout << "here. You hear eerie noises in the distance. You sense that you are not" << endl;
  cout << "alone. The only thing you have is a small pouch tied to your waist." << endl;
  cout << "You look inside, finding nothing. It would be nice if you had more light…" << endl;

  cout << endl;

  cout << "Press enter to continue..." << endl;

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  //initialize rooms
  Space* mainhall = new mainHall(NULL, NULL, NULL, NULL);
  Space* bedroom = new Bedroom(NULL, NULL, mainhall, NULL);
  Space* bath = new Bath(bedroom, NULL, NULL, NULL);
  Space* kitchen = new Kitchen(NULL, mainhall, NULL, NULL);
  Space* living = new Living(NULL, NULL, NULL, kitchen);
  Space* study = new Study(NULL, NULL, kitchen, NULL);
  Space* dining = new Dining(NULL, living, NULL, NULL);
  Space* patio = new Patio(NULL, kitchen, dining, NULL);

  //link rooms
  mainhall->setNorth(kitchen);
  mainhall->setWest(bedroom);
  bedroom->setSouth(bath);
  kitchen->setNorth(patio);
  kitchen->setEast(living);
  kitchen->setWest(study);
  living->setNorth(dining);
  dining->setWest(patio);

  //sets current room to main
  string currentRoom = "main";

  do
  {
    if (currentRoom == "main" && player->getIsAlive())
    {
      //place initial player marker
      mainhall->setPlayerMarker(player->getXPos(), player->getYPos());
      //display map to start
      mainhall->showMap(player->getHasFlashlight());
      do
      {
        choice = getUserInput();
        //ignore last character in buffer
        cin.ignore();

        //player moves up
        if (choice == 'w')
        {
          mainhall->changePos(player, player->getXPos(), player->getYPos(), 'w');
        }

        //player moves down
        if (choice == 's')
        {
          mainhall->changePos(player, player->getXPos(), player->getYPos(), 's');
        }

        //player moves left
        if (choice == 'a')
        {
          mainhall->changePos(player, player->getXPos(), player->getYPos(), 'a');
        }

        if (choice == 'd')
        {
          mainhall->changePos(player, player->getXPos(), player->getYPos(), 'd');
        }

        if (choice == 'i')
        {
          player->displayItems();

          cout << "Press enter to continue..." << endl;

          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          mainhall->showMap(player->getHasFlashlight());
        }

        if (choice == 'c')
        {
          displayImage("gamehints.txt");

          mainhall->showMap(player->getHasFlashlight());
        }

        if (choice == 'h')
        {
          mainhall->showHint();

          cout << "Press enter to continue..." << endl;

          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          mainhall->showMap(player->getHasFlashlight());
        }

      } while(!(mainhall->getGoBedroom()) && !(mainhall->getGoKitchen()) && player->getIsAlive());
    }

    if (currentRoom == "bedroom" && player->getIsAlive())
    {
      bedroom->setPlayerMarker(player->getXPos(), player->getYPos());
      bedroom->showMap(player->getHasFlashlight());

      do
      {
        choice = getUserInput();
        cin.ignore();

        bedroom->setPlayerMarker(player->getXPos(), player->getYPos());
        //player moves up
        if (choice == 'w')
        {
          bedroom->changePos(player, player->getXPos(), player->getYPos(), 'w');
        }

        //player moves down
        if (choice == 's')
        {
          bedroom->changePos(player, player->getXPos(), player->getYPos(), 's');
        }

        //player moves left
        if (choice == 'a')
        {
          bedroom->changePos(player, player->getXPos(), player->getYPos(), 'a');
        }

        if (choice == 'd')
        {
          bedroom->changePos(player, player->getXPos(), player->getYPos(), 'd');
        }

        if (choice == 'i')
        {
          player->displayItems();

          bedroom->showMap(player->getHasFlashlight());
        }

        if (choice == 'c')
        {
          displayImage("gamehints.txt");

          bedroom->showMap(player->getHasFlashlight());
        }

        if (choice == 'h')
        {
          bedroom->showHint();

          bedroom->showMap(player->getHasFlashlight());
        }

      } while(!(bedroom->getGoHall()) && !(bedroom->getGoBath()) && player->getIsAlive());
    }

    if (currentRoom == "bath" && player->getIsAlive())
    {
      bath->setPlayerMarker(player->getXPos(), player->getYPos());
      bath->showMap(player->getHasFlashlight());
      do
      {
        choice = getUserInput();
        cin.ignore();

        bath->setPlayerMarker(player->getXPos(), player->getYPos());
        //player moves up
        if (choice == 'w')
        {
          bath->changePos(player, player->getXPos(), player->getYPos(), 'w');
        }

        //player moves down
        if (choice == 's')
        {
          bath->changePos(player, player->getXPos(), player->getYPos(), 's');
        }

        //player moves left
        if (choice == 'a')
        {
          bath->changePos(player, player->getXPos(), player->getYPos(), 'a');
        }

        if (choice == 'd')
        {
          bath->changePos(player, player->getXPos(), player->getYPos(), 'd');
        }

        if (choice == 'i')
        {
          player->displayItems();

          bath->showMap(player->getHasFlashlight());
        }

        if (choice == 'c')
        {
          displayImage("gamehints.txt");

          bath->showMap(player->getHasFlashlight());
        }

        if (choice == 'h')
        {
          bath->showHint();

          bath->showMap(player->getHasFlashlight());
        }

      } while(!(bath->getGoBedroom()) && player->getIsAlive());
    }

    if (currentRoom == "kitchen" && player->getIsAlive())
    {
      kitchen->setPlayerMarker(player->getXPos(), player->getYPos());
      kitchen->showMap(player->getHasFlashlight());

      do
      {
        choice = getUserInput();
        cin.ignore();

        kitchen->setPlayerMarker(player->getXPos(), player->getYPos());

        //player moves up
        if (choice == 'w')
        {
          kitchen->changePos(player, player->getXPos(), player->getYPos(), 'w');
        }

        //player moves down
        if (choice == 's')
        {
          kitchen->changePos(player, player->getXPos(), player->getYPos(), 's');
        }

        //player moves left
        if (choice == 'a')
        {
          kitchen->changePos(player, player->getXPos(), player->getYPos(), 'a');
        }

        if (choice == 'd')
        {
          kitchen->changePos(player, player->getXPos(), player->getYPos(), 'd');
        }

        if (choice == 'i')
        {

          player->displayItems();

          kitchen->showMap(player->getHasFlashlight());
        }

        if (choice == 'c')
        {

          displayImage("gamehints.txt");

          kitchen->showMap(player->getHasFlashlight());
        }

        if (choice == 'h')
        {
          kitchen->showHint();

          kitchen->showMap(player->getHasFlashlight());
        }

      } while(!(kitchen->getGoHall()) && !(kitchen->getGoLiving()) &&
        !(kitchen->getGoStudy()) && !(kitchen->getGoPatio()) &&
        player->getIsAlive());
    }

    if (currentRoom == "study" && player->getIsAlive())
    {
      study->setPlayerMarker(player->getXPos(), player->getYPos());
      study->showMap(player->getHasFlashlight());

      do
      {
        choice = getUserInput();
        cin.ignore();

        study->setPlayerMarker(player->getXPos(), player->getYPos());

        //player moves up
        if (choice == 'w')
        {
          study->changePos(player, player->getXPos(), player->getYPos(), 'w');
        }

        //player moves down
        if (choice == 's')
        {
          study->changePos(player, player->getXPos(), player->getYPos(), 's');
        }

        //player moves left
        if (choice == 'a')
        {
          study->changePos(player, player->getXPos(), player->getYPos(), 'a');
        }

        if (choice == 'd')
        {
          study->changePos(player, player->getXPos(), player->getYPos(), 'd');
        }

        if (choice == 'i')
        {
          player->displayItems();

          study->showMap(player->getHasFlashlight());
        }

        if (choice == 'c')
        {
          displayImage("gamehints.txt");

          study->showMap(player->getHasFlashlight());
        }

        if (choice == 'h')
        {
          study->showHint();

          study->showMap(player->getHasFlashlight());
        }

      } while(!(study->getGoKitchen()) && player->getIsAlive());
    }

    if (currentRoom == "living" && player->getIsAlive())
    {
      living->setPlayerMarker(player->getXPos(), player->getYPos());
      living->showMap(player->getHasFlashlight());

      do
      {
        choice = getUserInput();
        cin.ignore();

        living->setPlayerMarker(player->getXPos(), player->getYPos());


        //player moves up
        if (choice == 'w')
        {
        living->changePos(player, player->getXPos(), player->getYPos(), 'w');
        }

        //player moves down
        if (choice == 's')
        {
          living->changePos(player, player->getXPos(), player->getYPos(), 's');
        }

        //player moves left
        if (choice == 'a')
        {
          living->changePos(player, player->getXPos(), player->getYPos(), 'a');
        }

        if (choice == 'd')
        {
          living->changePos(player, player->getXPos(), player->getYPos(), 'd');
        }

        if (choice == 'i')
        {
          player->displayItems();

          living->showMap(player->getHasFlashlight());
        }

        if (choice == 'c')
        {
          displayImage("gamehints.txt");

          living->showMap(player->getHasFlashlight());
        }

        if (choice == 'h')
        {
          living->showHint();

          living->showMap(player->getHasFlashlight());
        }

      } while(!(living->getGoDining()) && !(living->getGoKitchen() &&
        player->getIsAlive()));
    }

    if (currentRoom == "dining" && player->getIsAlive())
    {
      dining->setPlayerMarker(player->getXPos(), player->getYPos());
      dining->showMap(player->getHasFlashlight());

      do
      {
        choice = getUserInput();
        cin.ignore();

        dining->setPlayerMarker(player->getXPos(), player->getYPos());

        //player moves up
        if (choice == 'w')
        {
          dining->changePos(player, player->getXPos(), player->getYPos(), 'w');
        }

        //player moves down
        if (choice == 's')
        {
          dining->changePos(player, player->getXPos(), player->getYPos(), 's');
        }

        //player moves left
        if (choice == 'a')
        {
          dining->changePos(player, player->getXPos(), player->getYPos(), 'a');
        }

        if (choice == 'd')
        {
          dining->changePos(player, player->getXPos(), player->getYPos(), 'd');
        }

        if (choice == 'i')
        {
          player->displayItems();
          dining->showMap(player->getHasFlashlight());
        }

        if (choice == 'c')
        {
          displayImage("gamehints.txt");
          dining->showMap(player->getHasFlashlight());
        }

        if (choice == 'h')
        {
          dining->showHint();
          dining->showMap(player->getHasFlashlight());
        }

      } while(!(dining->getGoLiving()) && !(dining->getGoPatio()) &
        player->getIsAlive());
    }

    if (currentRoom == "patio" && player->getIsAlive())
    {
      patio->setPlayerMarker(player->getXPos(), player->getYPos());
      patio->showMap(player->getHasFlashlight());

      do
      {
        choice = getUserInput();
        cin.ignore();

        patio->setPlayerMarker(player->getXPos(), player->getYPos());

        //player moves up
        if (choice == 'w')
        {
          patio->changePos(player, player->getXPos(), player->getYPos(), 'w');
        }

        //player moves down
        if (choice == 's')
        {
          patio->changePos(player, player->getXPos(), player->getYPos(), 's');
        }

        //player moves left
        if (choice == 'a')
        {
          patio->changePos(player, player->getXPos(), player->getYPos(), 'a');
        }

        if (choice == 'd')
        {
          patio->changePos(player, player->getXPos(), player->getYPos(), 'd');
        }

        if (choice == 'i')
        {
          player->displayItems();
          patio->showMap(player->getHasFlashlight());
        }

        if (choice == 'c')
        {
          displayImage("gamehints.txt");
          patio->showMap(player->getHasFlashlight());
        }

        if (choice == 'h')
        {
          patio->showHint();
          patio->showMap(player->getHasFlashlight());
        }

      } while(!(patio->getGoKitchen()) && !(patio->getGoDining()) &&
        !(patio->getExit()) && player->getIsAlive());
    }

    if (kitchen->getGoHall() || bedroom->getGoHall())
    {
      currentRoom = "main";

      //reset room switch
      kitchen->setGoHall(false);
      bedroom->setGoHall(false);
    }

    if (mainhall->getGoBedroom() || bath->getGoBedroom())
    {
      currentRoom = "bedroom";

      //reset room switch
      mainhall->setGoBedroom(false);
      bath->setGoBedroom(false);
    }

    if (mainhall->getGoKitchen() || living->getGoKitchen() ||
        patio->getGoKitchen() || study->getGoKitchen())
    {
      currentRoom = "kitchen";

      //reset room switch
      mainhall->setGoKitchen(false);
      living->setGoKitchen(false);
      patio->setGoKitchen(false);
      study->setGoKitchen(false);
    }

    if (bedroom->getGoBath())
    {
      currentRoom = "bath";

      //reset room switch
      bedroom->setGoBath(false);
    }

    if (kitchen->getGoStudy())
    {
      currentRoom = "study";

      //reset room switch
      kitchen->setGoStudy(false);
    }

    if (kitchen->getGoLiving() || dining->getGoLiving())
    {
      currentRoom = "living";

      //reset room switch
      kitchen->setGoLiving(false);
      dining->setGoLiving(false);
    }

    if (kitchen->getGoPatio() || dining->getGoPatio())
    {
      currentRoom = "patio";

      //reset room switch
      kitchen->setGoPatio(false);
      dining->setGoPatio(false);
    }

    if (patio->getGoDining() || living->getGoDining())
    {
      currentRoom = "dining";

      //reset room switch
      patio->setGoDining(false);
      living->setGoDining(false);
    }

  } while(player->getIsAlive() && !(patio->getExit()));

  //player is dead
  if (!(player->getIsAlive()))
  {
    displayImage("lose.txt");
  }

  //player successfully exits
  if (patio->getExit())
  {
    displayImage("win.txt");
  }

  //deallocate memory
  delete mainhall;
  delete bedroom;
  delete bath;
  delete kitchen;
  delete living;
  delete study;
  delete dining;
  delete patio;

  mainhall = NULL;
  bedroom = NULL;
  bath = NULL;
  kitchen = NULL;
  living = NULL;
  study = NULL;
  dining = NULL;
  patio = NULL;
}

Game::~Game()
{

  //deallocate memory
  delete player;

  player = NULL;
}
