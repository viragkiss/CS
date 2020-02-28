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
    //this->enrolled = new CStudent [MAXSTCR];
    this->nbEnrolled = 0;

    this->enrolled = new CStudent* [this->capacity];

    /*CStudent** this->enrolled [MAXCRST];

	for (int i=0; i<MAXCRST; i++){
		this->enrolled[i] = new CStudent* [MAXCRST];
	}*/
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
		if (s->nbCourses < MAXCRST){
			this->enrolled[this->nbEnrolled] = s;  //enroll student in course
			this->nbEnrolled ++;
			s->courses[s->nbCourses] = this;   //add course to student schedule
			s->nbCourses ++;

			cout<<"Enrolled student: "<<*s;
			cout<<"Available spaces: "<<(this->capacity - this->nbEnrolled)<<endl;
		}
		else cout<<"Student schedule is full"<<endl;
	}
	else cout<<"Course is full"<<endl;
}


ostream& operator<<(ostream &o, const CCourse &c){
	o << "Course information: "<< c.name <<"; "<< c.code <<"; "<< c.nbEnrolled<<endl;
	return o;
}

void CCourse::setNbEnrolled(int i){
	this->nbEnrolled = i;
}

void CCourse::displayInfo(){
	cout<<*this<<endl;
}

void CCourse::displayStudents(){
	for (int i=0; i<this->nbEnrolled; i++){
		(this->enrolled[i])->displayInfo();
	}
}






