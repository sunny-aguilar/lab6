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
    switch ( menu.validateNumber(1,6) ) {
        case 1:
            // Add an ew node to the head
            menu.menuAddNodeHead();
            addHead( menu.validateNumber(1,999) );
            break;
        case 2:
            // Add a new node to the tail
            menu.menuAddNodeTail();
            addTail( menu.validateNumber(1,999) );
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
** Description:     adds a new node to the head of the list
*********************************************************************/
void LinkedList::addHead(int val) {
    Node *nodePtr, *previousNodePtr;

    if (head == nullptr || head->val >= val) {
        head = new Node(val, head);
        tail = head; // tail must point to head if only one node
        cout << "value added to head" << head->val << endl << endl;
    }
}

/*********************************************************************
** Description:     adds a new node to the tail of the list
*********************************************************************/
void LinkedList::addTail(int val) {
    if (head == nullptr) {
        head = new Node(val);
        tail = head; // tail must point to head if only one node
        cout << "value added to tail" << head->val << endl << endl;
    }
    else {
        // create pointer and assign to head of list
        Node *nodePtr = head;

        // loop through nodes until it reaches until next = nullptr
        while (nodePtr->getNext() != nullptr) {
            nodePtr = nodePtr->next;
        }
        // create a node and assign to next
        nodePtr->next = new Node(val);
        cout << "Value " << nodePtr->val;
    }
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
    Node *nodePtr = tail;
    while (nodePtr) {
        cout << nodePtr->val << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl << endl;
}