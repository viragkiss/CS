//StackQueue.cpp

#include <iostream>
#include <string>
#include<exception>
using namespace std ;
#include "StackQueue.h"
#include "SLinkedList.h"


LinkedStack::LinkedStack()
{
	L = LinkedList();
}

bool LinkedStack::empty() const
{ 
	return L.empty();
}

void LinkedStack::push(const Elem& e)
{
	L.addFront(e);
}

Elem& LinkedStack::pop()
{
	tmp = L.front();
	L.removeFront();
	return tmp;
}

void LinkedStack::showStack()
{
	L.displayElements();
}
//------------------------------------------------------------------


StackQueue::StackQueue()
{
	In = LinkedStack();
	Out = LinkedStack();
}

void StackQueue::input(Elem *elemArray, int arraySize)
{
	if (arraySize != 0) {
		for (int i=0; i < arraySize; i++) {
			In.push(elemArray[i]);
		}
		In.showStack();
	}
	else cout<< "There are currently no jobs." << endl;  // output message if stack is empty
}

void StackQueue::output(int arraySize)
{
	for (int i=0; i < arraySize; i++) {
		tmp = In.pop();
		Out.push(tmp);
	}
}

void StackQueue::displayJobs()
{
	if (!Out.empty()) {
		Out.showStack();
	}
	else cout<< "There are currently no jobs." << endl;
}



