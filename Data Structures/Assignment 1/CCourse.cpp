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

void CCourse::calcAverages(){
	int *arrayOfTotals, *tmpArray ;
	int total, index;
	arrayOfTotals = new int [this->nbEnrolled];
	tmpArray = new int [NBEXAMS];
	cout<<"Totals for courses:"<<endl;

	for (int i=0; i<this->nbEnrolled; i++){
		total = 0;
		index = findCourseIndex((this->enrolled[i]));
		
		if (index != -1){
			cout<<"Index found "<<index<<"   Student "<<(this->enrolled[i])->name<<"   Course "<<this->name<<endl;
			tmpArray = (this->enrolled[i])->grades[index];
			
			for (int j=0; j<NBEXAMS; j++){
				total = total + tmpArray[j];
				cout<<"TMP "<<tmpArray[j];
			}
			cout<<endl;
			arrayOfTotals[i] = total/NBEXAMS;
		}
		else cout<<"Course not found: "<<this->name<<endl;
	}
	cout<<endl;
	cout<<"Totals for course "<<this->name<<endl;
	for (int a=0; a<this->nbEnrolled; a++){
		cout<<arrayOfTotals[a]<<", ";
	}
	cout<<endl;

	/*for (int i=0; i<nbEnrolled; i++){
		int enr = (this->enrolled[i])-> nbCourses;
		cout<<"success"<<i<<"number of courses"<<enr<<endl;
		
		for (int j=0; j<enr; j++){
			if ( (this->enrolled[i])-> courses[j] == this){
				cout<<"SUCCESSSSSS"<<j<<endl;
				(this->enrolled[i])-> grades[j]
			}
		}
	}*/
}

int CCourse::findCourseIndex (CStudent* s){

	int enr = s->nbCourses;
				
	for (int j=0; j<enr; j++){

		if (s->courses[j] == this){

			return j;
		} 
	}
	cout<<"Course not found"<<endl;
	return -1;
}





