#include "hdr/render.hpp"
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/screen/string.hpp>
#include <string>


// Initializer list for class Render
Render::Render() : columns_(7), rows_(7), exitGame_(false) {}

// member functions for class Render

int Render::renderMainMenu() const{
  using namespace ftxui;
  int selection(0);
  MenuOption option;
  auto screen = ScreenInteractive::Fullscreen();

  option.on_enter = screen.ExitLoopClosure();

  std::vector<std::string> menu_entries = {"Exit","New Game","Options","Leaderboard"};

  auto windowTitle = text("Main menu");
  Component menu = Menu(&menu_entries, &selection, option);
  Component render = Renderer(menu, [&]{
        return window(windowTitle, menu->Render(), DOUBLE);
  });      
  screen.Loop(render);

  // Get the selected menu entry as reutnr value
  switch (selection) {
    case 0:{
             return 0;
           } 
    case 1:{
             return 1;
           } 
    case 2:{
             return 2;
           } 
    case 3:{
             return 3;
           } 
  }      
  return 0;
}

void Render::renderGame() const{
  using namespace ftxui;
  auto screen = ScreenInteractive::Fullscreen();
  
  auto windowTitle = text("Game");
   
  // screen.Loop();
  
}

void Render::renderOptions(){
  using namespace ftxui;
  std::string strColumns(std::to_string(columns_)), strRows(std::to_string(rows_));
  auto screen = ScreenInteractive::Fullscreen();
  ButtonOption buttonBackOption;
  auto windowTitle = text("Options");
  Element textRows = text("rows") | size(WIDTH, EQUAL, 10);
  Element textColumns = text("columns") | size(WIDTH, EQUAL, 10);
  Component inputR = Input(&strRows, "rows") | size(WIDTH, EQUAL, 5) | size(HEIGHT, EQUAL, 1);
  Component inputC = Input(&strColumns, "columns") | size(WIDTH, EQUAL, 5) | size(HEIGHT, EQUAL, 1);
  Component buttonBack = Button({
      .label = "back", 
      .on_click = screen.ExitLoopClosure()})
      | size(WIDTH, EQUAL, 7) 
      | size(HEIGHT, EQUAL, 3);

  Component cont = Container::Vertical({inputR, inputC, buttonBack});

  Component render = Renderer(cont, [&]{
    Element box =
      vbox(hbox({textRows,
      inputR->Render()}),
      hbox({textColumns,
      inputC->Render()}),
      buttonBack->Render());
    return window(windowTitle, box, DOUBLE);
  });      
    
  screen.Loop(render);

  columns_ = std::stoi(strColumns);
  rows_ = std::stoi(strRows);
}


