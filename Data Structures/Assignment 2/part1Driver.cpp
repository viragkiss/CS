//part1Driver.cpp

#include <iostream>
#include <string>
#include<exception>
#include <stdio.h>
using namespace std ;
#include "SLinkedList.h"
#include "StackQueue.h"

int main() {


	StackQueue Q, QQ;
	Q = StackQueue(); QQ = StackQueue();
	int size = 4;
	string listOfJobs[] = {"ABC", "DEF", "GHI", "LJK"};
	string listtt[] = {};

	cout<< "-----------------------------------------------------------"<< endl;
	cout << "Testing Input Stack:" << endl;
	Q.input(listOfJobs, size);
	cout << "Testing Output Stack:" << endl;
	Q.output(size);
	Q.displayJobs();
	cout<< "-----------------------------------------------------------"<< endl;

	cout << "Testing Input Stack:" << endl;
	QQ.input(listtt, 0);
	cout << "Testing Output Stack:" << endl;
	QQ.output(0);
	QQ.displayJobs();
	cout<< "-----------------------------------------------------------"<< endl;

	return EXIT_SUCCESS;
}