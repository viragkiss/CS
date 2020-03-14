// DLCircList.h

#ifndef DLCircList_h
#define DLCircList_h

#include<iostream>
#include<exception>
#include<string>
#include<time.h>
using namespace std;

class Node
{
	private:
		string elem;
		Node* next;
		Node* prev;
		friend class MyDoublyLinkedList;
		
	public:
		Node(): next(NULL), prev(NULL)
		{}
		Node(string elem) : elem(elem)
		{}
};


class MyDoublyLinkedList
{
	private:
		Node* head;
		Node* tail;
		string eaten;
		string* listOfEaten;
		int nEaten;

	public:
		MyDoublyLinkedList (int n);
		~MyDoublyLinkedList ();
		bool empty() const;
		void add(Node *ptr, const string& elem);
		void addBack(const string & elem);
		string remove(Node* cur);
		void removeBack();
		void moveAround(int n);
		Node* traverseForth(int n);
		Node* traverseBack(int n);
		void displayAll() const;
};

#endif

