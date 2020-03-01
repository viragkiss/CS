// ---
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
using namespace std ;
#include "constants.h"
#include "CCourse.hpp"
#include "CStudent.hpp"

CCourse::CCourse()
{
	this->name = (char*)"";
	this->code = 0;
}

CCourse::CCourse(char* vname, int vcode)
{
    this->name = new char[strlen(vname)+1];
	strcpy(name, vname);
	this->code = vcode;
	this->capacity = MAXSTCR;
    this->nbEnrolled = 0;
    this->enrolled = new CStudent* [this->capacity];
}

CCourse::~CCourse()
{
    delete this->enrolled;
    delete [] this->name;
    cout<<"Course destructor called: "<<this->name<<endl;
}

ostream& operator<<(ostream &o, const CCourse &c)
{
	o << "Course information: "<< c.name <<"; "<< c.code <<"; "<< c.nbEnrolled<<endl;
	return o;
}

int CCourse::getNbEnrolled()
{
	return this->nbEnrolled;
}

bool CCourse::enroll(CStudent* s)
{
	// first, check if the course is full or the student is already enrolled
	if ((this->nbEnrolled < this->capacity) && ((this->isEnrolled(s)) == -1 ) ){

			this->enrolled[this->nbEnrolled] = s;
			this->nbEnrolled ++;
			return true;
	}
	return false;
}

int CCourse::isEnrolled(CStudent* s)
{
	for (int i=0; i < this->nbEnrolled; i++){
		if (this->enrolled[i] == s){
			return i;
		}
	}
	return -1;
}

CStudent* CCourse::getStudent(int id)
{
	if (id < 0 || id >= nbEnrolled){
		cout<<"No student assigned with given index. Try again."<<endl;
		return NULL;
	}
	else return enrolled[id];
}

/*CStudent* CCourse::findBestStudent()
{
	int number = 0;
	int index = 0;
	if (this->nbEnrolled != 0){
		for (int i=0; i < nbEnrolled; i++){
			if ((this->calcAverages()[i] > number )){
				this->calcAverages()[i] = number;
				index = i;
			}
		}
		return enrolled[index];
	}
	else return NULL;
}*/

CStudent* CCourse::findBestStudent()
{
    int maxAverage = 0;
    int maxIndex = 0;
    for (int i=0; i<this->nbEnrolled; i++){
        if (enrolled[i]->calcAverage(this) > maxAverage){
            maxAverage = enrolled[i]->calcAverage(this);
        }
    }
    cout<<"The best students index: "<<maxIndex<<endl;
    cout<<"The best students name: "<<enrolled[maxIndex]->name<<endl;
    cout<<"The best students score "<<maxAverage<<endl;
    return enrolled[maxIndex];
}

void CCourse::displayInfo()
{
	cout<<*this<<endl;
}

void CCourse::displayStudents()
{
	for (int i=0; i<this->nbEnrolled; i++){
		(this->enrolled[i])->displayInfo();
	}
}

int* CCourse::calcAverages()
{
	int *arrayOfTotals, *tmpArray ;
	int total, index;
	arrayOfTotals = new int [this->nbEnrolled];
	tmpArray = new int [NBEXAMS];

	for (int i=0; i<this->nbEnrolled; i++){
		total = 0;
		index = findCourseIndex((this->enrolled[i]));
		
		if (index != -1){
			tmpArray = (this->enrolled[i])->grades[index];
			
			for (int j=0; j<NBEXAMS; j++){
				total = total + tmpArray[j];
			}
			arrayOfTotals[i] = total/NBEXAMS;
		}
		else cout<<"Course not found: "<<this->name<<endl;
	}
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





