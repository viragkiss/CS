//StackQueue.cpp

#include <iostream>
#include <string>
#include<exception>
using namespace std ;
#include "StackQueue.h"
#include "SLinkedList.h"
//#include "SLinkedList.cpp"


LinkedStack::LinkedStack() //: L()
{
	L = LinkedList();
}

/*int LinkedStack::size() const
{ 
	return n;
}*/

bool LinkedStack::empty() const
{ 
	//return n == 0;
	return L.empty();
}

const Elem& LinkedStack::top() const //throw(StackEmpty)
{ 
	//if (empty()) throw StackEmpty("Top of empty stack");
	return L.front();
}

void LinkedStack::push(const Elem& e)
{
	//++n;
	L.addFront(e);
}

Elem& LinkedStack::pop()//throw(StackEmpty)
{
	//if (empty()) throw StackEmpty("Pop from empty stack");
	//--n;
	tmp = L.front();
	L.removeFront();
	return tmp;
}

void LinkedStack::showStack()
{
	L.displayElements();
}
//--------------------------------------------------------------------------

// queue class

StackQueue::StackQueue()
{
	In = LinkedStack();
	Out = LinkedStack();
}

void StackQueue::input(string *stringArray, int arraySize)
{
	if (arraySize != 0) {
		for (int i=0; i < arraySize; i++) {
			In.push(stringArray[i]);
		}
		In.showStack();
	}
	else cout<< "There are currently no jobs." << endl;
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



