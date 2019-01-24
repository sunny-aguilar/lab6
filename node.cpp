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
Node::Node(int val, Node *next = nullptr) :
    val{val},
    next{next},
    prev{prev} {
}

/*********************************************************************
** Description:     sets next pointer
*********************************************************************/
void Node::setNext(Node &addNode) {
//    next = addNode;
}

/*********************************************************************
** Description:     returns next pointer
*********************************************************************/
Node *Node::getNext() {
    return next;
}