//StackQueue.h

#ifndef StackQueue_h
#define StackQueue_h
#include <iostream>
#include <string>
#include<exception>
using namespace std ;
#include "SLinkedList.h"


typedef string Elem;
class LinkedStack
{
	private:
    	LinkedList L;
    	Elem tmp;  // variable to store popped element

	public:
		LinkedStack();
		bool empty() const;
		void push(const Elem& e);
		Elem& pop();
		void showStack();
};


class StackQueue
{
	private:
		LinkedStack In, Out;  // input and output stacks
		Elem tmp;  // variable to store popped element

	public:
		StackQueue();
		void input(Elem *elemArray, int arraySize);  // input an array of Elem jobs
		void output(int arraySize);
		void displayJobs();
};

#endif

