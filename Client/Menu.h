//
// Created by maria on 29/11/17.
//

#ifndef EXAM1_MENU_H
#define EXAM1_MENU_H

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
    Menu(const int &rowSize,const int &colSize);
private:
    // runs the menu
    void runMenu();
    // runs the game in chosen mode
    void runGame(const int &mode);
    //dimensions for the board of the game
    int rowNumber;
    int colNumber;
};
#endif //EXAM1_MENU_H
