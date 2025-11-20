#pragma once

#include <vector>
class Board{
  public:
    Board(int rows, int columns); // Cuonstructor

    void initBoard();
    void updateBoard();
    std::vector<std::vector<int>> getBoard() const{return board_;};
    int getRows() const{return rows_;};
    int getColumns() const{return columns_;};

  private:
    std::vector<std::vector<int>> board_;
    const int rows_;
    const int columns_;
};

