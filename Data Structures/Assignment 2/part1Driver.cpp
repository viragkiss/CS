/*------------------------------------------------------------------------------------------
 Name         : Assignment 2 Part 1
 Author       : Virag Kiss
 Description  : Implement the queueu of a printer using 2 Stacks as Singly Linked Lists
-------------------------------------------------------------------------------------------*/


#include <iostream>
#include <string>
#include<exception>
#include <stdio.h>
using namespace std ;
#include "SLinkedList.h"
#include "StackQueue.h"

int main() {


	StackQueue Queue_1, Queue_2;
	Queue_1 = StackQueue();  int size_1 = 4;  string listOfJobs_1 [] = {"ABC", "DEF", "GHI", "LJK"};
	Queue_2 = StackQueue();  int size_2 = 0;  string listOfJobs_2 [] = {};


	cout<< "-----------------------------------------------------------"<< endl;
	cout<< "Testing Stack 1:" <<endl;;
	cout<< "Input Stack:" <<endl;
	Queue_1.input(listOfJobs_1, size_1);

	cout<< "Output Stack:" <<endl;
	Queue_1.output(size_1);
	Queue_1.displayJobs();

	cout<< "-----------------------------------------------------------"<< endl;

	cout<< "Testing Stack 2:" <<endl;;
	cout<< "Input Stack:" <<endl;
	Queue_2.input(listOfJobs_2, size_2);

	cout<< "Output Stack:" <<endl;
	Queue_2.output(size_2);
	Queue_2.displayJobs();

	cout<< "-----------------------------------------------------------"<< endl;

	
	cout<< "==================== Program finished ====================="<< endl;
	return EXIT_SUCCESS;
}

