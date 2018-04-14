/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/9/17
** Description: Player.hpp is the Player class specification file.
*******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

#include "displayImage.hpp"

using namespace std;

//declaration of class Player
class Player
{
  //member variables
  private:
    int xPos;
    int yPos;
    int numMoves;
    int hitPoints;
    bool isAlive;
    bool hasFlashlight;
    bool hasKey;
    bool hasRope;
    vector<string*> items;

  //member functions
  public:
    Player();
    int getXPos();
    int getYPos();
    int rollDie(int);
    void setHitPoints(int);
    void setHasFlashlight(bool);
    void setHasKey(bool);
    void setHasRope(bool);
    void setIsAlive(bool);
    bool getHasFlashlight();
    bool getHasKey();
    bool getHasRope();
    bool getIsAlive();
    int getNumMoves();
    void makeMove(int, int);
    void addItem(string);
    void displayItems();
    int attack();
    void defense(int);
    ~Player();
};
#endif
