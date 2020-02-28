#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"
#include "CDept.hpp"
#include "CCourse.hpp"
#include "CStudent.hpp"

CDept::CDept(char* vname) {
    // -- do it here --
    this->name = new char[strlen(vname)+1];
    strcpy(name, vname);
    this->students = new CStudent* [MAXNBST];
    this->courses = new CCourse* [MAXNBCR];
    this->nbStudents = 0;
    this->nbCourses = 0;

    this->createStudents();
    this->createCourses();
    this->enrollStudentsInCourses();
}

CDept::~CDept() {
    // -- do it here --
    delete [] this->students;
    delete [] this->courses;
    delete [] this->name;
}

CStudent* CDept::getStudent(int index)
{
    // -- do it here --
    if(nbStudents != 0){
        return this->students[index];
    }
    else{
        cout<<"Department "<<this->name<<" has no students."<<endl;
        return NULL;
    }
}

CCourse* CDept::getCourse(int index)
{
    // -- do it here --
    if(nbCourses != 0){
        return this->courses[index];
    }
    else{
        cout<<"Department "<<this->name<<" has no courses."<<endl;
        return NULL;
    }
}

void CDept::createStudents() {
    char* stNames[] = {(char*)"Bill", (char*)"Alex", (char*)"Bob", (char*)"Ana", (char*)"Lilya",
        (char*)"Julie", (char*)"Chris", (char*)"Stef", (char*)"Max", (char*)"Ray"} ;
    int stCodes[]   = {105, 115, 125, 135, 145, 155, 165, 175, 185, 195} ;
    
    // Let's create 5 students,
    nbStudents= 5 ;
    for(int st= 0; st<nbStudents; st++) students[st] = new CStudent(stNames[st], stCodes[st]) ;
}

void CDept::createCourses() {
    char* crNames[] = {(char*)"CSO", (char*)"OS", (char*)"DB", (char*)"D. Math", (char*)"Software Eng",
        (char*)"Logic", (char*)"AI", (char*)"Algo", (char*)"NLP", (char*)"Prog 1"} ;
    int crCodes[]   = {106, 116, 126, 206, 216, 226, 306, 316, 326, 406} ;
    
    // Let's create 5 courses,
    nbCourses= 5 ;
    for(int cr= 0; cr<nbCourses; cr++) courses[cr] = new CCourse(crNames[cr], crCodes[cr]) ;
}

void CDept::enrollStudentsInCourses()
{
    // -- do it here --
    srand((unsigned int)time(0));
    int randIndex;

    for (int i=0; i<this->nbStudents; i++){
        for(int j=0; j<MAXCRST+1; j++){
            randIndex = rand() % nbCourses;
            this->students[i]->enroll(this->courses[randIndex]);
        }
    }
}

void CDept::createDefaultGrades()
{
    // Use current time as seed for random generator
    srand((unsigned int)time(0));
    
    // -- do it here --

}

bool CDept::addStudent() {
    // -- do it here --
    CStudent s((char*)"Mark", 205);
    if (this->nbStudents < MAXNBST){
        this->students[this->nbStudents] = &s;
        return true;
    }
    else {
        cout<<"Department "<<this->name<<" is full."<<endl;
        return false;
    }
}

bool CDept::addCourse() {
    // -- do it here --
    CCourse c((char*)"Data Structures", 356);
    if (this->nbCourses < MAXNBCR){
        this->courses[this->nbCourses] = &c;
        return true;
    }
    else {
        cout<<"Department "<<this->name<<" is full."<<endl;
        return false;
    }
}

bool CDept::enroll(CStudent* ps, CCourse* pc) {
    // -- do it here --

    return true ; //or return false
}

void CDept::displayStudents() {
    // -- do it here --
    cout<<"Here are the students in the Department: "<<this->name<<endl;
    for (int i=0; i<this->nbStudents; i++){
        (this->students[i])->displayInfo();
    }
    cout<<"----------------------------------------------------"<<endl;
}

void CDept::displayCourses() {
    // -- do it here --
    cout<<"Here are the courses in the Department: "<<this->name<<endl;
    for (int i=0; i<this->nbCourses; i++){
        (this->courses[i])->displayInfo();
    }
    cout<<"----------------------------------------------------"<<endl;
}
