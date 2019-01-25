/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     LinkedList class is where the functions are held
**                  that interact with the nodes in the linked-list.
**                  LinkedList owns a menu object to handles the menu
**                  operations.
**                  d
**                  d
**                  d
**                  d
*********************************************************************/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "menu.hpp"
#include "node.hpp"

class LinkedList {
public:
    LinkedList();
    void startSim();
    void programLogic();
    void menuOption();
    void addHead(int val);
    void addTail(int val);
    void deleteFirstNode();
    void deleteLastNode();
    void traverseBackwards(Node *phead);
    void traverseForward();

private:
    Menu menu;
    bool showMenu;
    Node *head;
    Node *tail;
};

#endif //LAB6_LINKEDLIST_HPP
