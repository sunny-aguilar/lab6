/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     LAB6 -
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
            addTail( menu.validateNumber(1 ,999) );
            break;
        case 3:
            // Delete from head
            menu.menuDeleteNodeHead();
            deleteFirstNode();
            break;
        case 4:
            // Delete from tail
            menu.menuDeleteNodeTail();
            deleteLastNode();
            break;
        case 5:
            // Traverse the list reversely
            menu.menuTraverseNodeBackwards();
            traverseBackwards();
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
    if (head == nullptr) {
        head = new Node(val);
    }
    else {
        head = new Node(val, head);
    }

    // traverse the list
    menu.menuTraverseNodeForward();
    traverseForward();
}

/*********************************************************************
** Description:     adds a new node to the tail of the list
*********************************************************************/
void LinkedList::addTail(int val) {
    if (head == nullptr) {
        head = new Node(val);
        head->next = nullptr;
        cout << "value added to tail " << head->val << endl << endl;
    }
    else {
        // create pointer and assign to head of list
        Node *nodePtr = head;

        // loop through nodes until it reaches until next = nullptr
        while (nodePtr->next != nullptr) {
            nodePtr = nodePtr->next;
        }
        // create a node and assign to next
        nodePtr->next = new Node(val);
        cout << "value added to tail " << nodePtr->val;
    }

    // traverse the list
    menu.menuTraverseNodeForward();
    traverseForward();
}

/*********************************************************************
** Description:     deletes the first node in the list
*********************************************************************/
void LinkedList::deleteFirstNode() {
    cout << "deleting first node\n\n";
    Node *nodePtr;
    if (!head) {
        return;
    }
    else {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }

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
void LinkedList::traverseBackwards() {
    cout << "traversing the list in reverse\n\n";
}

/*********************************************************************
** Description:     traverse the list forward
*********************************************************************/
void LinkedList::traverseForward() {
    Node *nodePtr = head;
    while (nodePtr != nullptr) {
        cout << nodePtr->val << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl << endl;
}