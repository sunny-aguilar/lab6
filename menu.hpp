/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Menu class holds the the main menu and user
**                  prompts for the program.
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    void menuStart();
    void menuAddNodeHead();
    void menuAddNodeTail();
    void menuDeleteNodeHead();
    void menuDeleteNodeTail();
    void menuListEmpty();
    void menuTraverseNodeBackwards();
    void menuTraverseNodeForward();
    void menuExit();
    int validateNumber(int min, int max);
private:
};

#endif //LAB6_MENU_HPP
