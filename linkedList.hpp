/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 14, 2019
** Description:     LinkedList class is where the functions are held
**                  that interact with the nodes in the linked-list.
**                  LinkedList owns a menu object to handles the menu
**                  operations. A node pointer is also declared
**                  within the class to hold the head and tail of the
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

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "menu.hpp"
#include "node.hpp"
#include <fstream>
using std::ifstream;

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void startSim();
    void programLogic();
    void menuOption();
    void addHead(int val);
    void addTail(int val);
    void deleteFirstNode();
    void deleteLastNode();
    void traverseBackwards(Node *phead);
    void printHead();
    void printTail();
    void createListFromFile();

private:
    Menu menu;
    bool showMenu;
    Node *head;
    Node *tail;
    void traverseForward();
};

#endif //LAB6_LINKEDLIST_HPP