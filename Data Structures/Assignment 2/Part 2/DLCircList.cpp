// DLCircList.cpp

#include<iostream>
#include<exception>
#include<string>
#include<time.h>
using namespace std;
#include "DLCircList.h"

DLCirclist::DLCirclist (int n)
{
	this->head = new Node();
	this->tail = new Node();
	this->head->next = tail;
	this->head->prev = tail;
	this->tail->prev = head;  // link head to tail for circular list
	this->tail->next = head;

	this->listOfEaten = new Elem [n];  
	this->nEaten = 0;
	this->eaten = "";
}

DLCirclist::~DLCirclist ()
{
	while(!empty())
		removeBack();
}

bool DLCirclist::empty() const
{
	return this->head->next == tail;
}

void DLCirclist::add(Node *ptr, const Elem& elem)
{
	Node *tmp = new Node(elem);
	tmp->next = ptr;
	tmp->prev = ptr->prev;
	ptr->prev->next = tmp;
	ptr->prev=tmp;
}

void DLCirclist::addBack(const Elem& elem)
{
	add(this->tail, elem);
}

Elem DLCirclist::remove(Node* cur)  // return the name of a member and remove it
{
	if(!empty())
	{
		Node *tmp = cur->next;
		cur->prev->next = tmp;
		tmp->prev = cur->prev;
		this->eaten = cur->elem;
		delete cur;
		return this->eaten;
	}
	else throw runtime_error("List is Empty");
}

void DLCirclist::removeBack()
{
	remove(this->tail->prev);
}

Node* DLCirclist::traverseForth(int n)  // move clockwise if N is even
{
	Node *cur = this->head->next;

	for (int i=0; i < n; i++){
		cur = cur->next;
		while ((cur == this->head)||(cur == this->tail)){
			cur = cur->next;
		}
	}
	return cur;
}

Node* DLCirclist::traverseBack(int n)  // move anti-clockwise if N is odd
{
	Node *cur = this->head->next;
	for (int i=0; i < n; i++){
		cur = cur->prev;
		while ((cur == this->head)||(cur == this->tail)){
			cur = cur->prev;
		}
	}
	return cur;
}

void DLCirclist::moveAround(int n)
{
	Node* tmp;
	if(!empty())
	{
		if (n % 2 == 0) {
			tmp = traverseForth(n);
		}
		else if (n % 2 != 0){
			tmp = traverseBack(n);
		}
		this->eaten = remove(tmp);  // store name of eaten member in a variable
		this->listOfEaten[nEaten] = this->eaten; // add eaten member name to list of eaten members and increase count
		this->nEaten++;
	}
	else throw runtime_error("List is Empty");
}

void DLCirclist::showList() const
{
	Node *cur = this->head->next;
	
	if (cur->next == this->head) {  // let user know if no one is left
		cout<< "No one is left.";
	}

	//cout<<"Head -> ";  // for debugging
	while(cur->next != this->head)
	{
		cout<<cur->elem<<" ";
		cur=cur->next;
	}
	//cout<<" Tail "<<endl;
	cout<<endl;

	cout<< "Eaten: ";  // display eaten member's names
	for (int i=0; i < this->nEaten; i++){
		cout<< this->listOfEaten[i] << " ";
	}
	cout<<endl;
}

