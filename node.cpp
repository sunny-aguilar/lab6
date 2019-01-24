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
** Description:     adds a new node head to the head
*********************************************************************/
void Node::addHead() {
    cout << "adding node to head";
}

/*********************************************************************
** Description:     adds a new node head to the tail
*********************************************************************/
void Node::addTail() {
    cout << "adding node to tail";
}

/*********************************************************************
** Description:     deletes the first node in the list
*********************************************************************/
void Node::deleteFirstNode() {
    cout << "deleting first node";
}

/*********************************************************************
** Description:     deletes the last node in the list
*********************************************************************/
void Node::deleteLastNode() {
    cout << "deleting last node";
}

/*********************************************************************
** Description:     traverse the list reversely
*********************************************************************/
void Node::traverseList() {
    cout << "traversing the list in reverse";
}