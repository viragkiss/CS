// ---
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
using namespace std ;
#include "constants.h"
#include "CCourse.hpp"
#include "CStudent.hpp"

CCourse::CCourse(){
	this->name = (char*)"";
	this->code = 0;
}

CCourse::CCourse(char* vname, int vcode)
{
    // --- add constructir definition here
    this->name = new char[strlen(vname)+1];
	strcpy(name, vname);
	this->code = vcode;
	this->capacity = MAXSTCR;
    this->enrolled = new CStudent [MAXSTCR];
    this->nbEnrolled = 0;
}

CCourse::~CCourse()
{
    // --- add destructor definition here
    //delete [] this->enrolled;
    delete [] this->name;
    cout<<"Course destructor called: "<<this->name<<endl;
}

void CCourse::enroll(CStudent* s){
	if (this->nbEnrolled < this->capacity){
		enrolled[this->nbEnrolled] = *s;
		nbEnrolled ++;
		cout<<"Enrolled student: "<<*s<<endl;
	}
	else cout<<"Course is full"<<endl;
}


ostream& operator<<(ostream &o, const CCourse &c){
	o << c.name <<"; "<< c.code <<"; "<< c.nbEnrolled<<endl;
	return o;
}

void CCourse::setNbEnrolled(int i){
	this->nbEnrolled = i;
}

void displayInfo(CCourse &c){
	cout<<c<<endl;
}






