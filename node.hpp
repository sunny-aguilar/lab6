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

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

class Node {
public:
    Node();
    void addHead();
    void addTail();
    void deleteFirstNode();
    void deleteLastNode();
    void traverseList();
private:
    int val;
    Node *next;
    Node *prev;
};

#endif //LAB6_NODE_HPP
