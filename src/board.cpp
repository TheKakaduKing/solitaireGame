#include "hdr/board.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// Initializer list for Board
// need columns and rows when creating the object
Board::Board(int rows, int columns): 
  rows_(rows),
  columns_(columns),
  board_(rows, std::vector<int>(columns,2)){}

 
void Board::initBoard(){
  constexpr int columnDistance(5);
  constexpr int rowDistance(5);
  constexpr int columnDistanceHalf(columnDistance/2);
  constexpr int rowDistanceHalf(rowDistance/2);
  int columnBoundLeft(0), columnBoundRight(0);
  int rowBoundUp(0), rowBoundDown(0);
  int centerR(0), centerC(0);

  if (rowDistance % 2 == 0) {
    rowBoundUp = (rows_/2) - rowDistanceHalf;
    rowBoundDown = (rows_/2) + rowDistanceHalf - 1;
    centerR = columns_/2;
  }
  else {
    rowBoundUp = (rows_/2) - rowDistanceHalf;
    rowBoundDown = (rows_/2) + rowDistanceHalf;
    centerR = columns_/2;
  }
  if (columnDistance % 2 == 0) {
    columnBoundLeft = (columns_/2) - columnDistanceHalf;
    columnBoundRight = (columns_/2) + columnDistanceHalf - 1;
    centerC = columns_/2;
  }
  else {
    columnBoundLeft = (columns_/2) - columnDistanceHalf;
    columnBoundRight = (columns_/2) + columnDistanceHalf;
    centerC = columns_/2;
  }

  // 0=not invalid state 1=not part of the board 2=pin available 3=no pin available
  // board is initialized with 2. Cut out the corners with 1
  for (int i = 0; i < rows_; i++) {
    if (i >= rowBoundUp && i <= rowBoundDown) {
      continue; 
    }
    for (int j = 0; j < columns_; j++) {
      if (j >= columnBoundLeft && j <= columnBoundRight) {
        continue; 
      }
      else {
        board_[i][j] = 1;
      } 
    }
  }

  // set center
  board_[centerR][centerC] = 3;
  // ________________________________________________________________
  // DEBUG TO VIEW THE BOARD
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
     std::cout << board_[i][j]; 
    }
    std::cout << std::endl;
  }
}

  















