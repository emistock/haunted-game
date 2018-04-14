/*******************************************************************************
** Author: Emily Stockenbojer
** Date: 8/9/17
** Description: A function called displayImage that takes a text file and
displays it. It is meant for displaying ASCII art to the screen. Code is adapted
from http://www.cplusplus.com/forum/general/58945/.
*******************************************************************************/

//preprocessor directives
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void displayImage(string fileName)
{
  cout << "\033[2J\033[1;1H";

  ifstream inputFile;

  //open file
  inputFile.open(fileName);

  string image;
  //read file
  if (inputFile)
  {
    while (inputFile)
    {
      string readFile;
      getline (inputFile, readFile);
      readFile += "\n";
      image += readFile;
    }

    //display to screen
    cout << image << endl;

    cout << "Press enter to continue..." << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //close file when finished
    inputFile.close();
  }
}
