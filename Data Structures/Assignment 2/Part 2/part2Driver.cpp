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
	
	m = 4; // number of members in the mission
	DLCirclist myList(m);

	myList.addBack("A");  // add members front to back
	myList.addBack("B");
	myList.addBack("C");
	myList.addBack("D");

	cout<< "Here are the starting members: ";
	myList.showList(); cout<<endl;

	for (int i=1; i < m+1; i++){  // display results for every day until no one is left

		cout<< "#---------------------- Day "<< i << " ----------------------#" << endl;

		n = rand()% 11;
		while (n == 0){
			n = rand()% 11;
		}
		cout<< "Random N is: "<<n<<endl;

		myList.moveAround(n);
		cout<< "Members left: ";
		myList.showList(); cout<<endl;

	}

	cout<< "#====================== Program finished ======================#" << endl;
	return EXIT_SUCCESS;
}

