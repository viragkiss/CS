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
     // --- add constructir definition here

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
    // --- add destructor definition here
	for(int i=0; i<maxCourses; i++){
		delete [] this->grades[i];
	}
	delete [] this->grades;

	delete [] this->courses;
    delete [] this->name;
    cout<<"Student destructor called: "<<this->name<<endl;
}

ostream& operator<<(ostream &o, const CStudent &s){
	o << "Student information: "<< s.name <<"; "<< s.id <<"; "<< s.nbCourses<<endl;
	return o;
}

void CStudent::printGrades(){

	for (int i=0; i<this->maxCourses; i++){
		for (int j=0; j<this->maxExams; j++) {
			cout<<setw(3)<<this->grades[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool CStudent::enroll(CCourse* c){

	if ((this->nbCourses < this->maxCourses) && ((this->isEnrolled(c)) == -1) ) {
			this->courses[this->nbCourses] = c;  //enroll student in course
			this->nbCourses ++;
			cout<<this->name<<" enrolled in course: "<<*c<<endl;
			return true;
	}
	else if (this->nbCourses == this->maxCourses) cout<<this->name<<" schedule is full"<<endl;
	else if (this->isEnrolled(c)) cout<<this->name << " is already enroled in course " << c->name<<endl;
	return false;
}

int CStudent::isEnrolled(CCourse* c){
	for (int i=0; i < this->nbCourses; i++){
		if (this->courses[i] == c){
			return i;
		}
	}
	return -1;  // return false
}

void CStudent::setCourseGrades(int courseIndex, int* scores){
	//scores has nbExams elements
	for (int i=0; i<this->maxExams; i++){
		this->setExamGrade(courseIndex, i, scores[i]);
	}

	/*cout<<"these scores have been added to grades: "<<endl;
	for (int i=0; i<this->maxExams; i++){
		cout<<scores[i]<<", ";
	}*/
}

int* CStudent::calcAverages(){
	int* arrayOfTotals ;
	int total;
	arrayOfTotals = new int [this->nbCourses];
	cout<<"Totals for courses:"<<endl;

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

void CStudent::setExamGrade(int courseIndex, int examIndex, int score){
	this->grades[courseIndex][examIndex] = score;
	//cout<<"this score was added to exam grades: "<<score<<endl;
}

void CStudent::displayInfo(){
	cout<<*this<<endl;
	//this->printGrades();
}

void CStudent::displayCourses(){
	for (int i=0; i<this->nbCourses; i++){
		(this->courses[i])->displayInfo();
	}
}











