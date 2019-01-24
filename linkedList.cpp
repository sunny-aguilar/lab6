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
LinkedList::LinkedList() : showMenu{true}, head{nullptr}, tail{nullptr} {}

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

    menu.menuExit();
}

/*********************************************************************
** Description:     this function gets the user's main menu selection
**                  and completes the operation selected
*********************************************************************/
void LinkedList::menuOption() {
    switch (menu.validateNumber(1,6)) {
        case 1:
            // Add an ew node to the head
            addHead();
            break;
        case 2:
            // Add a new node to the tail
            addTail();
            break;
        case 3:
            // Delete from head
            deleteFirstNode();
            break;
        case 4:
            // Delete from tail
            deleteLastNode();
            break;
        case 5:
            // Traverse the list reversely
            traverseList();
            break;
        case 6:
            // Exit
            showMenu = false;
            break;
        default:
            cout << "Unable to make a selection!\n";
    }
}

/*********************************************************************
** Description:     adds a new node head to the head
*********************************************************************/
void LinkedList::addHead() {
    cout << "adding node to head\n\n";
    if (head == nullptr) {

    }
    else {

    }
}

/*********************************************************************
** Description:     adds a new node head to the tail
*********************************************************************/
void LinkedList::addTail() {
    cout << "adding node to tail\n\n";
}

/*********************************************************************
** Description:     deletes the first node in the list
*********************************************************************/
void LinkedList::deleteFirstNode() {
    cout << "deleting first node\n\n";
}

/*********************************************************************
** Description:     deletes the last node in the list
*********************************************************************/
void LinkedList::deleteLastNode() {
    cout << "deleting last node\n\n";
}

/*********************************************************************
** Description:     traverse the list reversely
*********************************************************************/
void LinkedList::traverseList() {
    cout << "traversing the list in reverse\n\n";
}