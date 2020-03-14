// DLCircList.cpp

#include<iostream>
#include<exception>
#include<string>
#include<time.h>
using namespace std;
#include "DLCircList.h"

MyDoublyLinkedList::MyDoublyLinkedList (int n)
{
	this->head = new Node();
	this->tail = new Node();
	this->head->next = tail;
	this->head->prev = tail;
	this->tail->prev = head;
	this->tail->next = head;

	listOfEaten = new string [n];
	nEaten = 0;
}

MyDoublyLinkedList::~MyDoublyLinkedList ()
{
	while(!empty())
		removeBack();
}

bool MyDoublyLinkedList::empty() const
{
	return this->head->next == tail;
}

void MyDoublyLinkedList::add(Node *ptr, const string& elem)
{
	Node *tmp = new Node(elem);
	tmp->next = ptr;
	tmp->prev = ptr->prev;
	ptr->prev->next = tmp;
	ptr->prev=tmp;
}

void MyDoublyLinkedList::addBack(const string& elem)
{
	add(this->tail, elem);
}

string MyDoublyLinkedList::remove(Node* cur)
{
	if(!empty())
	{
		Node *tmp = cur->next;
		cur->prev->next = tmp;
		tmp->prev = cur->prev;
		eaten = cur->elem;
		delete cur;
		return eaten;
	}
	else throw runtime_error("List is Empty");
}

Node* MyDoublyLinkedList::traverseForth(int n)
{
	Node *cur = head->next;

	for (int i=0; i < n; i++){
		cur = cur->next;
		while ((cur == head)||(cur == tail)){
			cur = cur->next;
		}
	}
	/*eaten = remove(cur);
	listOfEaten[nEaten] = eaten;
	nEaten++;*/
	return cur;
}

Node* MyDoublyLinkedList::traverseBack(int n)
{
	Node *cur = head->next;
	for (int i=0; i < n; i++){
		cur = cur->prev;
		while ((cur == head)||(cur == tail)){
			cur = cur->prev;
		}
	}
	return cur;
	//eaten = remove(cur);
	//listOfEaten[nEaten] = eaten;
	//nEaten++;
}

void MyDoublyLinkedList::moveAround(int n)
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
		eaten = remove(tmp);
		listOfEaten[nEaten] = eaten;
		nEaten++;
	}
	else throw runtime_error("List is Empty");
}

void MyDoublyLinkedList::removeBack()
{
	remove(tail->prev);
}

void MyDoublyLinkedList::displayAll() const
{
	Node *cur=head->next;
	
	if (cur->next == head) {
		cout<< "No one is left.";
	}

	//cout<<"Head -> ";
	while(cur->next!=head)
	{
		cout<<cur->elem<<" ";
		cur=cur->next;
	}
	//cout<<" Tail "<<endl;
	cout<<endl;

	cout<< "Eaten: ";
	for (int i=0; i < nEaten; i++){
		cout<< listOfEaten[i] << " ";
	}
	cout<<endl;
}

