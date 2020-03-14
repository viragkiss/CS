

#ifndef SLinkedList_h
#define SLinkedList_h
#include <iostream>
#include <string>
#include<exception>
using namespace std;


typedef string Elem; // define list element type
class Node
{
	private:
		Elem elem;
		Node* next;
		
	public:
		Node(Elem elem);
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
		const Elem& front() const;  // return first element
		void addFront(const Elem& elem);
		void removeFront();
		void displayElements() const;
};

#endif

