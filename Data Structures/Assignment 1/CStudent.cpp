#include <iostream>
#include <cstdlib>
#include <ctime>
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
	srand(time(NULL));

	this->name = new char[strlen(vname)+1];
	strcpy(name, vname);
	this->id = vid;
	this->courses = new CCourse [maxCourses];
	this->maxCourses = MAXCRST;
	this->maxExams = NBEXAMS;
	this->nbCourses = 0;

	////create course array, populate and print
	/*for (int i=0; i<maxCourses; i++){
		courses[i]=CCourse((char*)"CS", rand()%10);
		cout<<"Courses are: "<<courses[i]<<"; ";
	} cout<<endl;*/
	
	
	////create grades array
	this->grades = new int* [this->maxCourses];
	for (int i=0; i<this->maxCourses; i++){
		this->grades[i] = new int [this->maxExams];
	}
	////populate grades array
	srand(time(NULL));
	for (int i=0; i<this->maxCourses; i++){
		for (int j=0; j<this->maxExams; j++) {
			this->grades[i][j] = rand() % 101;
			//cout<<setw(2)<<this->grades[i][j]<<" ";
		}
		//cout<<endl;
	}

	//cout<<"Student onstructor called: "<<this->name<<", "<<this->id<<endl;
}

CStudent::~CStudent()
{
    // --- add destructor definition here
    ////delete grades array
	for (int i=0 ; i<this->maxCourses ; i++) {
		delete [] this->grades [i];
	}
	delete [] this->grades ;
	//delete [] this->courses;
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
			cout<<setw(2)<<this->grades[i][j]<<" ";
		}
		cout<<endl;
	}
}

void CStudent::setNbCourses(int i){
	this->nbCourses = i;
}

void CStudent::enroll(CCourse* c){

	if (this->nbCourses < this->maxCourses){
		courses[this->nbCourses] = *c;
		nbCourses ++;
		cout<<"Enrolled in course: "<<*c<<endl;
	}
	else cout<<"Course is full"<<endl;
	/*if (this->nbCourses < this->maxCourses){
		for (int i=0, i<this->maxCourses; i++){
			if (courses[i] == NULL) courses[i] = c;
		}
	}
	else cout<<"Course is full"<<endl;*/
}

//////--------------friend functions--------------------------
void displayInfo(CStudent &s){
	cout<<s<<endl;
	s.printGrades();
}











