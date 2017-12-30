#ifndef EXAM1_MENU_H
#define EXAM1_MENU_H

#include "Display.h"

/*
 * runs a menu for the game.
 */
class Menu {
public:
    /*
     * constructor.
     * rowSize - number of rows in the game board.
     * colSize - number of columns in the game board.
     */
    Menu(const int &rowSize,const int &colSize, Display * display);

private:
    // runs the menu
    void runMenu()const;
    // runs the game in chosen mode
    void runGame(const int &mode)const;
    //dimensions for the board of the game
    const int rowNumber;
    const int colNumber;
    Display* display;
};
#endif //EXAM1_MENU_H
