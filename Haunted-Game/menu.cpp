/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 6/29/17
** Description: A function called menu that provides options to the user by
printing them to the screen and allowing the user to make a choice. The function
then returns their choice as output if the choice is valid.
*******************************************************************************/

//preprocessor directives
#include <iostream>
#include <string>

#include "inputValidation.hpp"
#include "menu.hpp"

using namespace std;

int menu()
{
  string choice;

  //asks the user what they want to do
  cout << "Program Menu" << endl;
  cout << endl;
  cout << "1. Play the game" << endl;
  cout << "2. Exit" << endl;
  cout << endl;

  do
  {
    cout << "Enter your choice: " << endl;

    getline(cin, choice);

    if (inputValidation(choice, 1, 2))
    {
      return stoi(choice);
    }

    //if user does not enter a valid choice, alert user
    else
    {
      cout << "The valid choices are 1 and 2." << endl;
      cout << "Select one of those choices." << endl;
    }

  } while (!inputValidation(choice, 1, 2));

  return 0;
}
