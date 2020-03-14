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
	public:
		LinkedStack();
		//int size() const;
		bool empty() const;
		const Elem& top() const; //throw(StackEmpty);
		void push(const Elem& e);
		Elem& pop(); //throw(StackEmpty);
		void showStack();

    private:
    	LinkedList L;
    	Elem tmp;
    	//int n;
};
/*class StackEmpty : public RuntimeException {
	public:
		StackEmpty(const string& err): RuntimeException(err) {}
};*/

class StackQueue
{
	private:
		LinkedStack In, Out;
		string tmp;
	public:
		StackQueue();
		void input(string *stringArray, int arraySize);
		void output(int arraySize);
		void displayJobs();
};

#endif

