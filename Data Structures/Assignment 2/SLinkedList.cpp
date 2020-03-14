/*------------------------------------------------------------------------------------------
 Name         : Assignment 2 Part 1
 Author       : Virag Kiss
 Description  : Implement the queueu of a printer using 2 Stacks as Singly Linked Lists
-------------------------------------------------------------------------------------------*/


#include <iostream>
#include <string>
#include<exception>
using namespace std ;
#include "SLinkedList.h"


Node::Node(Elem elem)
{
	this->elem = elem;
}

//------------------------------------------------------------------

LinkedList::LinkedList ()
{
	this->head = NULL;
}

LinkedList::~LinkedList ()
{
	while(!empty())
		removeFront();
	this->head = NULL;
}

bool LinkedList::empty() const
{
	return this->head == NULL;
}

const Elem& LinkedList::front() const
{
	if(!empty())
		return this->head->elem;
	else
		throw out_of_range("List is Empty");
}

void LinkedList::addFront(const Elem& elem)
{
	Node *tmp = this->head;
	this->head = new Node(elem);
	this->head->next = tmp;
}

void LinkedList::removeFront()
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
	Node *ptr = this->head;
	cout<< "Head -> ";

	while(ptr != NULL)
	{
		cout<< ptr->elem <<" -> ";
		ptr = ptr->next;
	}
	cout<< "Null" <<endl;
}

