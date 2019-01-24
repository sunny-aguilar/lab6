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

Node::Node(int val) : val{val}, next{nullptr}, prev{nullptr} {}