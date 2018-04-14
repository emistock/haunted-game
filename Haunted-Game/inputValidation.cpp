/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 6/29/17
** Description: A function called inputValidation that checks user input and
displays a warning message if the data type of the input does not match the data
type that the program expects, and returns a false value. If the input data type
is valid, a true value is returned.
*******************************************************************************/

//preprocessor directives
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//validates float numbers
bool inputValidation(string userInput, float low)
{
  //initialize bool variable
  bool isValid = false;

  //check if not any of the user input is digits
  if (!any_of(userInput.begin(), userInput.end(), ::isdigit))
  {
    return isValid;
  }

  //if any of user input is an alphabetic character
  else if (any_of(userInput.begin(), userInput.end(), ::isalpha))
  {
    return isValid;
  }

  //check if user input is empty spaces
  else if (userInput.empty())
  {
    return isValid;
  }

  //check for extra characters
  else if (userInput.find("!") != string::npos && userInput.find("@")
  != string::npos && userInput.find("#") != string::npos && userInput.find("$")
  != string::npos && userInput.find("%") != string::npos && userInput.find("^")
  != string::npos && userInput.find("&") != string::npos && userInput.find("*")
  != string::npos && userInput.find("(") != string::npos && userInput.find(")")
  != string::npos && userInput.find("-") != string::npos && userInput.find("_")
  != string::npos && userInput.find("+") != string::npos && userInput.find("=")
  != string::npos && userInput.find("{") != string::npos && userInput.find("}")
  != string::npos && userInput.find("[") != string::npos && userInput.find("]")
  != string::npos && userInput.find("|") != string::npos && userInput.find("/")
  != string::npos && userInput.find("<") != string::npos && userInput.find(">")
  != string::npos && userInput.find(",") != string::npos && userInput.find("?")
  != string::npos && userInput.find(":") != string::npos && userInput.find(";")
  != string::npos && userInput.find(" ") != string::npos)
  {
    return isValid;
  }

  //check for user input float values by searching for .
  //convert user input from string to float to check if it is greater than a
  //low value
  else if (userInput.find(".") != string::npos)
  {
    if(stof(userInput) >= low)
    {
      isValid = true;
      return isValid;
    }
  }

  else
  {
    return isValid;
  }

  return 0;

}

//validates integer input in a range
bool inputValidation(string userInput, int low, int high)
{
  //initialize bool variable
  bool isValid = false;

  //check for user input double values by searching for .
  if (userInput.find(".") != string::npos)
  {
    return isValid;
  }

  //check if not all user input is a digit
  else if (!all_of(userInput.begin(), userInput.end(), ::isdigit))
  {
    return isValid;
  }

  //check if user input is empty spaces
  else if (userInput.empty())
  {
    return isValid;
  }

  //convert user input from string back to int and test for high and low
  //values
  else if(stoi(userInput) >= low && stoi(userInput) <= high)
  {
    isValid = true;
    return isValid;
  }

  else
  {
    return isValid;
  }

  return 0;
}
