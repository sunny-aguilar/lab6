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

#include "node.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Node::Node() : val{0}, next{nullptr}, prev{nullptr} {}

/*********************************************************************
** Description:     one-args default constructor sets initial value
*********************************************************************/
Node::Node(int val, Node *node) : val{val}, next{node} {}

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