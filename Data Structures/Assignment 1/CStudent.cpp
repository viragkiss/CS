#include <iostream>
#include <cstdlib>
//#include <ctime>
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
	//srand(time(NULL));

	this->name = new char[strlen(vname)+1];
	strcpy(name, vname);
	this->id = vid;
	this->maxCourses = MAXCRST;
	this->maxExams = NBEXAMS;
	this->nbCourses = 0;

	this->courses = new CCourse* [MAXCRST];

	/*for (int i=0; i<MAXCRST; i++){
		courses[i] = new CCourse* [MAXCRST];
	}*/


	//this->courses = new CCourse [maxCourses];
	
	////create grades array
	this->grades = new int* [this->maxCourses];
	for (int i=0; i<this->maxCourses; i++){
		this->grades[i] = new int [this->maxExams];
	}
	////populate grades array
	for (int i=0; i<this->maxCourses; i++){
		for (int j=0; j<this->maxExams; j++) {
			this->grades[i][j] = 0;
		}
	}
}

CStudent::~CStudent()
{
    // --- add destructor definition here
	/*for (int i=0 ; i<this->maxCourses ; i++) {
		delete [] this->grades [i];
	}
	delete [] this->grades ;
	//delete [] this->courses;*/
    delete [] this->name;
    
    cout<<"Student destructor called: "<<this->name<<endl;
}
///////  print student data /////////////////
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

void CStudent::enroll(CCourse* c){

	if (this->nbCourses < this->maxCourses){
		if (c->nbEnrolled < MAXSTCR){
			courses[this->nbCourses] = c;  //enroll student in course
			nbCourses ++;
			c->enrolled[c->nbEnrolled] = this;  //add course to student schedule
			c->nbEnrolled ++;

			cout<<"Enrolled in course: "<<*c<<endl;
		}
		else cout<<"Course is full"<<endl;
	}
	else cout<<"Student schedule is full"<<endl;

	cout<<"-----------------------------------------------------------"<<endl;
	for (int i=0; i<nbCourses; i++){
		(courses[i])->displayInfo();
	}
	cout<<"-----------------------------------------------------------"<<endl;
}

void CStudent::setCourseGrades(int courseIndex, int* scores){
	//scores has nbExams elements
	for (int i=0; i<NBEXAMS; i++){
		this->setExamGrade(courseIndex, i, scores[i]);
	}

	cout<<"these scores have been added to grades: "<<endl;
	for (int i=0; i<NBEXAMS; i++){
		cout<<scores[i]<<", ";
	}
}

int CStudent::calcAverages(int* scores){
	int total= 0;
	for (int i=0; i<NBEXAMS; i++){
		total = total + scores[i];
	} cout<<"Total is: "<<total<<endl;
	int average = total/NBEXAMS;
	return average;
}

void CStudent::setExamGrade(int courseIndex, int examIndex, int score){
	this->grades[courseIndex][examIndex] = score;
	//cout<<"this score was added to exam grades: "<<score<<endl;
}

void CStudent::displayInfo(){
	cout<<*this<<endl;
	this->printGrades();
}

void CStudent::displayCourses(){
	for (int i=0; i<nbCourses; i++){
		(courses[i])->displayInfo();
	}
}











