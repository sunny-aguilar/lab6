/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 14, 2019
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

#include "node.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Node::Node() : val{0}, next{nullptr}, prev{nullptr} {}

/*********************************************************************
** Description:     two-arg default constructor sets initial value, &
**                  initializes next and prior node pointers
*********************************************************************/
Node::Node(int val, Node *next, Node *prev) : val{val}, next{next}, prev{prev} {}

/*********************************************************************
** Description:     sets next pointer
*********************************************************************/
void Node::setNext(Node *next) {
    this->next = next;
}

/*********************************************************************
** Description:     returns next pointer
*********************************************************************/
Node *Node::getNext() {
    return next;
}

/*********************************************************************
** Description:     sets prev pointer
*********************************************************************/
void Node::setPrev(Node *prev) {
    this->prev = prev;
}

/*********************************************************************
** Description:     returns prev pointer
*********************************************************************/
Node *Node::getPrev() {
    return prev;
}

/*********************************************************************
** Description:     sets int value in node
*********************************************************************/
void Node::setVal(int val) {
    this->val = val;
}

/*********************************************************************
** Description:     returns integer value in node
*********************************************************************/
int Node::getVal() {
    return val;
}