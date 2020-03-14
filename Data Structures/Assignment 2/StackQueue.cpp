/*------------------------------------------------------------------------------------------
 Name         : Assignment 2 Part 1
 Author       : Virag Kiss
 Description  : Implement the queueu of a printer using 2 Stacks as Singly Linked Lists
-------------------------------------------------------------------------------------------*/


#include <iostream>
#include <string>
#include<exception>
using namespace std ;
#include "StackQueue.h"
#include "SLinkedList.h"


LinkedStack::LinkedStack()
{
	this->L = LinkedList();
}

bool LinkedStack::empty() const
{ 
	return this->L.empty();
}

void LinkedStack::push(const Elem& e)
{
	this->L.addFront(e);
}

Elem& LinkedStack::pop()
{
	this->tmp = L.front();
	this->L.removeFront();
	return this->tmp;
}

void LinkedStack::showStack()
{
	this->L.displayElements();
}
//------------------------------------------------------------------


StackQueue::StackQueue()
{
	this->In = LinkedStack();
	this->Out = LinkedStack();
}

void StackQueue::input(Elem *elemArray, int arraySize)
{
	if (arraySize != 0) {
		for (int i=0; i < arraySize; i++) {
			this->In.push(elemArray[i]);
		}
		this->In.showStack();
	}
	else cout<< "There are currently no jobs." << endl;  // output message if stack is empty
}

void StackQueue::output(int arraySize)
{
	for (int i=0; i < arraySize; i++) {
		this->tmp = this->In.pop();
		this->Out.push(this->tmp);
	}
}

void StackQueue::displayJobs()
{
	if (!this->Out.empty()) {
		this->Out.showStack();
	}
	else cout<< "There are currently no jobs." << endl;
}



