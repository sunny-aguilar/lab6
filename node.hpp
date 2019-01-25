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
    Node(int val, Node *node = nullptr);
    void setNext();
    Node *getNext();
    void setVal(int val);
    int getVal();
    Node *next;
    Node *prev;
    int val;
private:
//    Node *next;

};

#endif //LAB6_NODE_HPP
