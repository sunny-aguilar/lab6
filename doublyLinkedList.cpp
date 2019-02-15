/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 14, 2019
** Description:     LinkedList class is where the functions are held
**                  that interact with the nodes in the linked-list.
**                  LinkedList owns a menu object to handles the menu
**                  operations. A node pointer is also declared
**                  within the 1class to hold the head and tail of the
**                  nodes. There are a total of 6 required functions
**                  that add nodes to the head or tail, delete the
**                  first or last nodes, traverses the list backwards,
**                  and an internal function that displays the list
**                  after each operation. There is also a function
**                  that displays the value in each node in reverse
**                  and it uses recursion to accomplish that.
**                  EXTRA CREDIT - print head value
**                  EXTRA CREDIT - print tail value
**                  EXTRA CREDIT - creates a list from a text file.
*********************************************************************/

#include "doublyLinkedList.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
DoublyLinkedList::DoublyLinkedList() :
    showMenu{true},
    head{nullptr},
    tail{nullptr} {}

/*********************************************************************
** Description:     destructor that destroys the list by iterating
**                  through each node and destroying it while at the
**                  same time saving the address of the next node in
**                  order to reach the next node
*********************************************************************/
DoublyLinkedList::~DoublyLinkedList() {
    Node *nodePtr = head;
    while (nodePtr != nullptr) {
        Node *garbage = nodePtr;
        nodePtr = nodePtr->getNext();
        delete garbage;
    }
}

/*********************************************************************
** Description:     start the linked list program
*********************************************************************/
void DoublyLinkedList::startSim() {
    programLogic();
}

/*********************************************************************
** Description:     controls the program logic flow
*********************************************************************/
void DoublyLinkedList::programLogic() {

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
void DoublyLinkedList::menuOption() {
    switch ( menu.validateNumber(1,9) ) {
        case 1:
            // Add an ew node to the head
            menu.menuAddNodeHead();
            addHead( menu.validateNumber(0,999) );
            break;
        case 2:
            // Add a new node to the tail
            menu.menuAddNodeTail();
            addTail( menu.validateNumber(0 ,999) );
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
            cout << endl;
            break;
        case 6:
            // Display head node value
            menu.printHeadValue();
            printHead();
            break;
        case 7:
            // Display tail node value
            menu.printTailValue();
            printTail();
            break;
        case 8:
            // Create a linked list from a text file
            menu.textFileList();
            createListFromFile();
            break;
        case 9:
            // Exit
            showMenu = false;
            break;
        default:
            cout << "Unable to make a selection!\n";
    }
}

/*********************************************************************
** Description:     adds a new node to the head of the list and
**                  updates tail pointer to the last node on the list,
**                  if it exist
*********************************************************************/
void DoublyLinkedList::addHead(int val) {
    if (head == nullptr) {
        // set node equal to head
        head = new Node(val);
        // set tail equal to head node
        tail = head;
    }
    else {
        // add new node to head of the list
        head = new Node(val, head);

        // set tail to last node on list
        Node *nodePtr = head->getNext();
        while (nodePtr->getNext() != nullptr) {
            nodePtr = nodePtr->getNext();
        }
        tail = nodePtr;
    }

    // traverse the list
    menu.menuTraverseNodeForward();
    traverseForward();
}

/*********************************************************************
** Description:     adds a new node to the tail of the list and
**                  updates tail pointer to last node on list, if it
**                  exist
*********************************************************************/
void DoublyLinkedList::addTail(int val) {
    if (head == nullptr) {
        head = new Node(val);
        //head->setNext(nullptr);  DELETE THIS, REDUNDANT

        // set tail equal to head node
        tail = head;
    }
    else {
        // create pointer and assign to head of list
        Node *nodePtr = head;

        // loop through nodes until it reaches until next = nullptr
        while (nodePtr->getNext() != nullptr) {
            nodePtr = nodePtr->getNext();
        }
        // create a node, assign to next, and assign prev to old last node
        nodePtr->setNext(new Node(val, nullptr, nodePtr));

        // set tail to last node on list
        nodePtr = head->getNext();
        while (nodePtr->getNext() != nullptr) {
            nodePtr = nodePtr->getNext();
        }
        tail = nodePtr;
    }

    // traverse the list
    menu.menuTraverseNodeForward();
    traverseForward();
}

/*********************************************************************
** Description:     deletes the first node in the list. First it
**                  checks if the node list is empty. If its not, then
**                  it checks to see if there is only one node. If
**                  there is more than one node, this check is also
**                  made. Checking to see how many nodes there exist
**                  is made in order to property delete the first
**                  node.
*********************************************************************/
void DoublyLinkedList::deleteFirstNode() {
    Node *nodePtr;
    if (!head) {
        menu.menuListEmpty();
        return;
    }
    else if (head->getNext() == nullptr) {
        nodePtr = head;
        head = nullptr;
        tail = nullptr;
        delete nodePtr;
    }
    else {
        menu.menuDeleteNodeHead();
        // get head node
        nodePtr = head;
        // set new head to next node
        head = head->getNext();
        // set new head prev pointer to nullptr
        head->setPrev(nullptr);
        // delete first node
        delete nodePtr;
    }

    // traverse the list
    menu.menuTraverseNodeForward();
    traverseForward();
}

/*********************************************************************
** Description:     deletes the last node in the list and updates
**                  tail pointer to last node on list, if it exist.
**                  First the list is checked to see if there are any
**                  any nodes in it.
*********************************************************************/
void DoublyLinkedList::deleteLastNode() {
    Node *nodePtr, *prev;
    nodePtr = prev = head;

    if (!head) {
        menu.menuListEmpty();
        return;
    }
    else if (nodePtr->getNext() == nullptr) {
        nodePtr = head;
        head = nullptr;
        tail = nullptr;
        delete nodePtr;
    }
    else {
        menu.menuDeleteNodeTail();
        nodePtr = head;
        while (nodePtr->getNext() != nullptr) {
            prev = nodePtr;
            nodePtr = nodePtr->getNext();
        }
        tail = prev;
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
void DoublyLinkedList::traverseBackwards(Node *pHead) {
    Node *nodePtr = pHead;

    if (!nodePtr) {
        cout << "The list is empty!\n";
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
void DoublyLinkedList::traverseForward() {
    Node *nodePtr = head;
    while (nodePtr != nullptr) {
        cout << nodePtr->getVal()  << " ";
        nodePtr = nodePtr->getNext();
    }
    cout << endl << endl;
}

/*********************************************************************
** Description:     EXTRA CREDIT - prints the value of the head node
*********************************************************************/
void DoublyLinkedList::printHead() {
    Node *nodePtr = head;
    if (!nodePtr) {
        cout << "there is no node in the head\n";
    }
    if (nodePtr) {
        cout << "Head value is " << nodePtr->getVal() << endl;
    }
}

/*********************************************************************
** Description:     EXTRA CREDIT - prints the value of the tail node
*********************************************************************/
void DoublyLinkedList::printTail() {
    Node *nodePtr = head;
    if (!nodePtr) {
        cout << "there is no node in the tail\n";
    }
    else {
        cout << "Tail value is " << tail->getVal() << endl;
    }
}

/*********************************************************************
** Description:     clears the node list
*********************************************************************/
void DoublyLinkedList::clearList() {
    Node *nodePtr = head;
    while (nodePtr != nullptr) {
        Node *garbage = nodePtr;
        nodePtr = nodePtr->getNext();
        delete garbage;
    }
    head = nullptr;
}

/*********************************************************************
** Description:     EXTRA CREDIT - creates a list from a text file.
**                  File name is node_list.txt. If a node list already
**                  exist, I programmed it so that you cannot create
**                  another one (cannot add to it). Otherwise, if no
**                  node list exist yet, then a user is allowed to
**                  create one from a text file.
*********************************************************************/
void DoublyLinkedList::createListFromFile() {
    int overwrite = 0;

    // warn user that prior node list will be over-written
    if (head != nullptr) {
        cout << "A node list already exists!\n";
        cout << "This operation will overwrite your \n";
        cout << "list with values from node_list.txt \n";

        do {
            cout << "1. Overwrite list\n";
            cout << "2. Back to main menu\n";
            cout << ">> ";
            overwrite = menu.validateNumber(1,2);
        } while (overwrite != 1 && overwrite != 2);
        if (overwrite == 2) { return; }
    }

    // inform user a node list is being created
    cout << "A node list is being created from a file.\n";

    // clear prior node list
    clearList();

    // create a node list from a text file
    string fileName;                            // holds input file name
    ifstream inFile;                            // create input file object
    string input;

    // prompt user to enter file name
    cout << "Enter the text file name (i.e., node_list.txt)\n";
    cout << ">> ";

    // loop - ask user for file name if incorrect
    do {
        cin >> fileName;                        // node_list.txt
        inFile.open(fileName);                  // input file data from node_list.txt
        if (inFile.fail())
            cout << "File not found! "          // request file name if not found
                 << "Enter a file name:\n";
    } while (inFile.fail());                    // if file not found, repeat loop

    // confirm input file opened
    cout << "Input file successfully opened\n";

    // get each value until end of file is reached
    while (!inFile.eof()) {
        // get a paragraph
        getline(inFile, input);

        // convert string to int
        int val = std::atoi(input.c_str());
        // add each value to the end of the list
        addTail(val);
    }
}
