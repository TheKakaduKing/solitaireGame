#include "hdr/render.hpp"
#include "hdr/board.hpp"
#include <iostream>
#include <iterator>
#include <ostream>
int a = 5, b = 4;
int foo(int a, int b){
  return a + b;
}



// Continue at turn class or update board or how can we print the board and input turns
int main(){
  // int menuOption(0); 
  //
  Render game;
  // Board board(10,10);
  // board.initBoard();

  do {
    switch (game.renderMainMenu()) {
      case 0:{game.exitGame_ = true; break;}
      // case 1:{game.renderNewGame(); break;}
      case 2:{game.renderOptions(); break;}
      // case 0:{game.t_exitGame = true;}
      default:{game.exitGame_ = true; break;}
    }

  }while (!game.exitGame_);
}
