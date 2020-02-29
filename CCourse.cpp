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
    this->nbEnrolled = 0;
    this->enrolled = new CStudent* [this->capacity];
}

CCourse::~CCourse()
{
    // --- add destructor definition here
    delete this->enrolled;
    delete [] this->name;
    cout<<"Course destructor called: "<<this->name<<endl;
}

bool CCourse::enroll(CStudent* s){
	// first, check if the course is full or the student is already enrolled
	if ((this->nbEnrolled < this->capacity) && !(this->isEnrolled(s)) ){

			this->enrolled[this->nbEnrolled] = s;  //enroll student in course
			this->nbEnrolled ++;

			cout<<"Enrolled student: "<<*s;
			return true;
	}
	// if not enrolled, display reasons accordingly
	else if (this->nbEnrolled == this->capacity) cout<< this->name <<" course is full" <<endl;
	else if (this->isEnrolled(s)) cout<< *s->name << " is already enroled in course " << this->name <<endl;
	return false;
}

bool CCourse::isEnrolled(CStudent* s){
	for (int i=0; i < this->nbEnrolled; i++){
		if (this->enrolled[i] == s){
			return true;
		}
	}
	return false;
}


ostream& operator<<(ostream &o, const CCourse &c){
	o << "Course information: "<< c.name <<"; "<< c.code <<"; "<< c.nbEnrolled<<endl;
	return o;
}

void CCourse::displayInfo(){
	cout<<*this<<endl;
}

void CCourse::displayStudents(){
	for (int i=0; i<this->nbEnrolled; i++){
		(this->enrolled[i])->displayInfo();
	}
}

int* CCourse::calcAverages(){
	int *arrayOfTotals, *tmpArray ;
	int total, index;
	arrayOfTotals = new int [this->nbEnrolled];
	tmpArray = new int [NBEXAMS];
	//cout<<"Totals for courses:"<<endl;

	for (int i=0; i<this->nbEnrolled; i++){
		total = 0;
		index = findCourseIndex((this->enrolled[i]));
		
		if (index != -1){
			//cout<<"Index found "<<index<<"   Student "<<(this->enrolled[i])->name<<"   Course "<<this->name<<endl;
			tmpArray = (this->enrolled[i])->grades[index];
			
			for (int j=0; j<NBEXAMS; j++){
				total = total + tmpArray[j];
				//cout<<"TMP "<<tmpArray[j];
			}
			cout<<endl;
			arrayOfTotals[i] = total/NBEXAMS;
		}
		else cout<<"Course not found: "<<this->name<<endl;
	}
	cout<<"Totals for course: "<<this->name<<endl;
	for (int a=0; a<this->nbEnrolled; a++){
		cout<<arrayOfTotals[a]<<", ";
	}
	cout<<endl;
	cout<<endl;

	return arrayOfTotals;
}

int CCourse::findCourseIndex (CStudent* s){

	int enr = s->nbCourses;
				
	for (int j=0; j<enr; j++){

		if (s->courses[j] == this){

			return j;
		} 
	}
	cout<<"Course not found "<< this->name <<endl;
	return -1;
}





