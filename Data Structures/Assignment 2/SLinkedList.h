//SLinkedList.h

#ifndef SLinkedList_h
#define SLinkedList_h
#include <iostream>
#include <string>
#include<exception>
using namespace std ;

class Node
{
	private:
		string elem;
		Node* next;
		
	public:
		Node(string elem);
		friend class LinkedList;

};

class LinkedList
{
	private:
		Node* head;

	public:
		LinkedList ();
		~LinkedList ();
		bool empty() const;
		const string& front() const;
		void addFront(const string& elem);
		void removeFront();
		void displayElements() const;
};

#endif