// part2Driver.cpp

#include<iostream>
#include<exception>
#include<string>
#include<time.h>
using namespace std;
#include "DLCircList.h"

int main()
{

	cout<<endl;
	srand((unsigned int)time(0));
	int n, m;
	
	m = 4;
	MyDoublyLinkedList myList(m);

	myList.addBack("A");
	myList.addBack("B");
	myList.addBack("C");
	myList.addBack("D");

	cout<< "Here are the starting members: ";
	myList.displayAll(); cout<<endl;

	for (int i=1; i < m+1; i++){

		cout<< "#---------------------- Day "<< i << " ----------------------#" << endl;

		n = rand()% 11;
		while (n == 0){
			n = rand()% 11;
		}
		cout<< "Random N is: "<<n<<endl;

		myList.moveAround(n);
		cout<< "Members left: ";
		myList.displayAll(); cout<<endl;

	}

	cout<< "#====================== Program finished ======================#" << endl;
	return EXIT_SUCCESS;
}

