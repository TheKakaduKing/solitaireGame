#pragma once


class Render{
  // public accessible variables
  public:
    // Constructor
    Render();
    // variables
    bool exitGame_;

    // functions
    // functions are declarated outside of class to keep it readable
    int renderMainMenu() const;
    void renderGame() const;
    void renderOptions();
    void renderLeaderboard() const;
    int getRows() const{return rows_;};
    int getColumns() const{return columns_;};

  private:
    int rows_;
    int columns_;
    

};
