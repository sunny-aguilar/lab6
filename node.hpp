/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Node class is the data structure that consists of
**                  of the node. The node only holds one integer
**                  data value and two pointers that can hold nodes.
**                  There is a constructor that builds a node with
**                  a value and with a default argument that can
**                  be used to set the node pointer to null or pass
**                  in a pointer to have the newly created node point
**                  to it. There are setters and getters for the
**                  private data variables as well.
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
