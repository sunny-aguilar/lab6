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
    void addHead();
    void addTail();
    void deleteFirstNode();
    void deleteLastNode();
    void traverseList();

private:
    Node node;
    Menu menu;
    bool showMenu;
    Node *head;
    Node *tail;
};

#endif //LAB6_LINKEDLIST_HPP
