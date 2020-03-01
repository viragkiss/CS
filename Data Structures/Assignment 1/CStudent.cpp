#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "constants.h"
#include "CStudent.hpp"
#include "CCourse.hpp"

using namespace std;

CStudent::CStudent(){
	this->name = (char*)"";
	this->id = 0;
}

CStudent::CStudent(char* vname, int vid)
{

	this->name = new char[strlen(vname)+1];
	strcpy(name, vname);
	this->id = vid;
	this->maxCourses = MAXCRST;
	this->maxExams = NBEXAMS;
	this->nbCourses = 0;
	this->courses = new CCourse* [this->maxCourses];
	
	////create grades array
	this->grades = new int* [this->maxCourses];
	for (int i=0; i<this->maxExams; i++){
		this->grades[i] = new int [this->maxExams];
	}
	////populate grades array with values of 0 at first
	for (int i=0; i<this->maxCourses; i++){
		for (int j=0; j<this->maxExams; j++) {
			this->grades[i][j] = 0;
		}
	}
}

CStudent::~CStudent()
{
	for(int i=0; i<maxCourses; i++){
		delete [] this->grades[i];
	}
	delete [] this->grades;
	delete [] this->courses;
    delete [] this->name;
    cout<<"Student destructor called: "<<this->name<<endl;
}

ostream& operator<<(ostream &o, const CStudent &s)
{
	o << "Student information: "<< s.name <<"; "<< s.id <<"; "<< s.nbCourses<<endl;
	return o;
}

int CStudent::getNbCourses()
{
	return this->nbCourses;
}

void CStudent::setCourseGrades(int courseIndex, int* scores)
{
	for (int i=0; i<this->maxExams; i++){
		this->setExamGrade(courseIndex, i, scores[i]);
	}
}

void CStudent::setExamGrade(int courseIndex, int examIndex, int score)
{
	this->grades[courseIndex][examIndex] = score;
}

void CStudent::printGrades()
{
	for (int i=0; i<this->maxCourses; i++){
		for (int j=0; j<this->maxExams; j++) {
			cout<<setw(3)<<this->grades[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool CStudent::enroll(CCourse* c)
{
	if ((this->nbCourses < this->maxCourses) && ((this->isEnrolled(c)) == -1) ) {
		this->courses[this->nbCourses] = c;
		this->nbCourses ++;
		return true;
	}
	return false;
}

int CStudent::isEnrolled(CCourse* c)
{
	for (int i=0; i < this->nbCourses; i++){
		if (this->courses[i] == c){
			return i;
		}
	}
	return -1;
}

void CStudent::displayInfo()
{
	cout<<*this<<endl;
}

void CStudent::displayCourses()
{
	for (int i=0; i<this->nbCourses; i++){
		(this->courses[i])->displayInfo();
	}
}

int* CStudent::calcAverages()
{
	int* arrayOfTotals ;
	int total;
	arrayOfTotals = new int [this->nbCourses];
	cout<<"Totals for courses for :"<< this-> name <<endl;

	for (int i=0; i<this->nbCourses; i++){
		total = 0;
		for (int j=0; j<this->maxExams; j++){
			total = total + this->grades[i][j];
		}
		arrayOfTotals[i] = total/this->maxExams;
		cout<<arrayOfTotals[i]<<", ";

	} cout<<endl;

	return arrayOfTotals;
}

int CStudent::calcAverage(CCourse* c)
{
    int index=0;
    int total = 0;
    int average = 0;
    for (int i=0; i<this->nbCourses; i++){
        if (courses[i] == c){
            index = i;
        }
    }
    for (int j=0; j<NBEXAMS; j++){
        total = total + grades[index][j];
    }
    average = total/NBEXAMS;
    return average;
}












