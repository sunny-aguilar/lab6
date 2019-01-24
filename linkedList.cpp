/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     LAB6 -
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
*********************************************************************/

#include "linkedList.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
LinkedList::LinkedList() : showMenu{true} {}

/*********************************************************************
** Description:     start the linked list program
*********************************************************************/
void LinkedList::startSim() {
    programLogic();
}

/*********************************************************************
** Description:     controls the program logic flow
*********************************************************************/
void LinkedList::programLogic() {

    do {
        menu.menuStart();

        menuOption();
    } while (showMenu);

}

/*********************************************************************
** Description:     this function gets the user's main menu selection
**                  and completes the operation selected
*********************************************************************/
void LinkedList::menuOption() {
    switch (menu.validateNumber(1,6)) {
        case 1:
            // Add an ew node to the head

            break;
        case 2:
            // Add a new node to the tail

            break;
        case 3:
            // Delete from head

            break;
        case 4:
            // Delete from tail

            break;
        case 5:
            // Traverse the list reversely

            break;
        case 6:
            // Exit

            break;
        default:
            cout << "Unable to make a selection!\n";
    }
}