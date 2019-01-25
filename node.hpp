/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Node class is the data structure that consists of
**                  of the node. The node only holds one integer
**                  data value and two pointers that can hold nodes.
**                  f
**                  t
**                  h
**                  u
**                  l
**                  e
**                  r
**                  l
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
    void setNext(Node *nxt);
    Node *getNext();
    void setVal(int val);
    int getVal();

private:
    int val;
    Node *next;
    Node *prev;
};

#endif //LAB6_NODE_HPP
