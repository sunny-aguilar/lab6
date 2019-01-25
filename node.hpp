/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     LAB6 - this program allows a user to create a
**                  simple linked list. A menu first appears that shows
**                  the user the possible interactions they can have,
**                  from adding nodes to the head or tail of the list
**                  to deleting those nodes and printing the the values
**                  held by each node in reverse. Any time a node is
**                  updated, the program will print the current node
**                  list values. A warning will be shown if no nodes
**                  exist. Recursion is used to print the list in
**                  reverse. After a user is done interacting with the
**                  linked-list, they can quit the program.
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
