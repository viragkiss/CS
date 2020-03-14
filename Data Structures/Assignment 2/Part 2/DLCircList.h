/*------------------------------------------------------------------------------
 Name         : Assignment 2 Part 2
 Author       : Virag Kiss
 Description  : Implement and solve the Missionaries and Cannibals Problem
 				using a Doubly Linked Circular List
--------------------------------------------------------------------------------*/


#ifndef DLCircList_h
#define DLCircList_h

#include<iostream>
#include<exception>
#include<string>
using namespace std;

typedef string Elem; // define list element type once
class Node
{
	private:
		Elem elem;
		Node* next;
		Node* prev;
		friend class DLCirclist;
		
	public:
		Node(): next(NULL), prev(NULL)
		{}
		Node(Elem elem) : elem(elem)
		{}
};


class DLCirclist
{
	private:
		Node* head;
		Node* tail;
		Elem eaten;  // temporary string to store eaten member
		Elem* listOfEaten;  // list of eaten members used for display after each day
		int nEaten;  // number of eaten members

	public:
		DLCirclist (int n);
		~DLCirclist ();
		bool empty() const;
		void add(Node *ptr, const Elem& elem);  // populate DL list
		void addBack(const Elem & elem);  // populate DL list
		Elem remove(Node* cur); // remove eaten members and return their names
		void removeBack();  // used to clear all members
		void moveAround(int n);  
		Node* traverseForth(int n);  // traverse forth is N is even
		Node* traverseBack(int n);  // traverse back (anti-clockwise) if N is odd
		void showList() const;  // display remaining members
};

#endif

