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
            deleteFirstNode();
            break;
        case 4:
            // Delete from tail
            deleteLastNode();
            break;
        case 5:
            // Traverse the list reversely
            menu.menuTraverseNodeBackwards();
            traverseBackwards(head);
            cout << endl << endl;
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
        head->setNext(nullptr);
        cout << "value added to tail " << head->getVal() << endl << endl;
    }
    else {
        // create pointer and assign to head of list
        Node *nodePtr = head;

        // loop through nodes until it reaches until next = nullptr
        while (nodePtr->getNext() != nullptr) {
            nodePtr = nodePtr->getNext();
        }
        // create a node and assign to next
        nodePtr->setNext(new Node(val));
        cout << "value added to tail " << nodePtr->getVal() ;
    }

    // traverse the list
    menu.menuTraverseNodeForward();
    traverseForward();
}

/*********************************************************************
** Description:     deletes the first node in the list
*********************************************************************/
void LinkedList::deleteFirstNode() {
    Node *nodePtr;
    if (!head) {
        menu.menuListEmpty();
        return;
    }
    else {
        menu.menuDeleteNodeHead();
        nodePtr = head;
        head = head->getNext();
        delete nodePtr;
    }

    // traverse the list
    menu.menuTraverseNodeForward();
    traverseForward();
}

/*********************************************************************
** Description:     deletes the last node in the list
*********************************************************************/
void LinkedList::deleteLastNode() {
    Node *nodePtr, *prev;
    nodePtr = prev = head;

    if (!head) {
        menu.menuListEmpty();
        return;
    }
    else if (nodePtr->getNext() == nullptr) {
        nodePtr = head;
        head = nullptr;
        delete nodePtr;
    }
    else {
        menu.menuDeleteNodeTail();
        nodePtr = head;
        while (nodePtr->getNext() != nullptr) {
            prev = nodePtr;
            nodePtr = nodePtr->getNext();
        }
        prev->setNext(nullptr);
        delete nodePtr;
    }

    // traverse the list
    menu.menuTraverseNodeForward();
    traverseForward();
}

/*********************************************************************
** Description:     traverse the list reversely using a recursive
**                  function. Recursion will occur until the base case
**                  is reached; that is when nodePtr->next reaches
**                  nullptr. Base case will print the value starting
**                  with the last value in the linked list.
*********************************************************************/
void LinkedList::traverseBackwards(Node *pHead) {
    Node *nodePtr = pHead;

    if (!nodePtr) {
        cout << "The list is empty!\n\n";
        return;
    }

    if (nodePtr->getNext() != nullptr) {
        traverseBackwards(nodePtr->getNext());
    }
    cout << nodePtr->getVal()  << " ";
}

/*********************************************************************
** Description:     traverse the list forward
*********************************************************************/
void LinkedList::traverseForward() {
    Node *nodePtr = head;
    while (nodePtr != nullptr) {
        cout << nodePtr->getVal()  << " ";
        nodePtr = nodePtr->getNext();
    }
    cout << endl << endl;
}