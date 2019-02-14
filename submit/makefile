# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	February 14, 2019
# Description:	Makefile for Lab 6

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += doublyLinkedList.o
OBJECTS += node.o
OBJECTS += menu.o

HPPs = doublyLinkedList.hpp
HPPs += node.hpp
HPPs += menu.hpp

CPPs = main.cpp
CPPs += doublyLinkedList.cpp
CPPs += node.cpp
CPPs += menu.cpp


# Targets needed to bring the executable up to date
Node: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Node $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

doublyLinkedList.o: doublyLinkedList.hpp

node.o: node.hpp

menu.o: menu.hpp


# Clean-up operations
clean:
	rm Node *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Node

zip:
	zip -D Lab6_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
