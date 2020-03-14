//SLinkedList.cpp

#include <iostream>
#include <string>
#include<exception>
using namespace std ;
#include "SLinkedList.h"


Node::Node(string elem)
{
	this->elem = elem;
}

LinkedList::LinkedList ()
{
	this->head = NULL;
}
LinkedList::~LinkedList () // destructor to clean up all nodes
{
	while(!empty())
		removeFront();
	this->head = NULL;
}
bool LinkedList::empty() const // is list empty?
{
	return this->head == NULL;
}

const string& LinkedList::front() const // get front element
{
	if(!empty())
		return this->head->elem;
	else
		throw out_of_range("List is Empty");
}

void LinkedList::addFront(const string& elem) // add to front of list
{
	Node *tmp = this->head;
	this->head = new Node(elem);
	this->head->next = tmp;
}
void LinkedList::removeFront() // remove front item list
{
	if(!empty())
	{
		Node *tmp = this->head;
		this->head = this->head->next;
		delete tmp;
	}
	else
		throw out_of_range("List is Empty");
}

void LinkedList::displayElements() const
{
	Node *ptr=head;
	cout<<"Head->";

	while(ptr!=NULL)
	{
		cout<< ptr->elem <<"->";
		ptr=ptr->next;
	}
	cout<<"Null"<<endl;
}

