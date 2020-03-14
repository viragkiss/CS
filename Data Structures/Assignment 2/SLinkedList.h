/*------------------------------------------------------------------------------------------
 Name         : Assignment 2 Part 1
 Author       : Virag Kiss
 Description  : Implement the queueu of a printer using 2 Stacks as Singly Linked Lists
-------------------------------------------------------------------------------------------*/


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

