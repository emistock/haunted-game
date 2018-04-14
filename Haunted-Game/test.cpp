#include <iostream>
using namespace std;

int main()
{
  numRows = 11;
  numCols = 7;

  char** gameBoard = new char*[numRows];

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
    gameBoard[0][j] = '_';
  }

  for (int j = 0; j < numCols; j++)
  {
    gameBoard[numRows - 1][j] = '_';
  }

  for (int i = 0; i < numRows; i++)
  {
    gameBoard[i][0] = '|';
  }

  for (int i = 0; i < numRows; i++)
  {
    gameBoard[i][numCols - 1] = '|';
  }

  //create special item tile;
  gameBoard[2][5] = '*';

  //create doors
  //door to kitchen
  gameBoard[0][numCols / 2] = 'D';

  //door to bedroom
  gameBoard[numRows / 2][0] = 'D';

  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numCols; j++)
    {
      cout << gameBoard[i][j];
    }

    cout << endl;
  }

  return 0;
}
