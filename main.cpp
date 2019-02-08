/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 14, 2019
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
**                  EXTRA CREDIT - print head value
**                  EXTRA CREDIT - print tail value
**                  EXTRA CREDIT - creates a list from a text file.
*********************************************************************/
#include "linkedList.hpp"
#include <iostream>

int main() {
    LinkedList link;
    link.startSim();
    return 0;
}