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
    this->createDefaultGrades();
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
    if ((nbStudents != 0) && (index < this->nbStudents)) {
        cout<<"got student "<< (this->students[index])->name <<endl;
        return this->students[index];
    }
    else{
        cout<<"Department "<<this->name<<" has no student at index "<< index <<"."<<endl;
        return NULL;
    }
}

CCourse* CDept::getCourse(int index)
{
    // -- do it here --
    if ((nbCourses != 0) && (index < this->nbCourses)){
        cout<<"got course "<< (this->courses[index])->name <<endl;
        return this->courses[index];
    }
    else{
        cout<<"Department "<<this->name<<" has no course at index "<< index <<"."<<endl;
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
        CStudent* tmps;
        tmps = (this->students[i]); //create temporary variable for a given student

        while(tmps ->nbCourses < MAXCRST){
            randIndex = rand() % nbCourses;

            CCourse* tmpc;
            tmpc = (this->courses[randIndex]);

            this->enroll(tmps, tmpc);
            cout<<"----------------done-----------------------------------"<<endl;
        }
    }
}

void CDept::createDefaultGrades()
{
    srand((unsigned int)time(0));
    int* grades;
    grades = new int [NBEXAMS];
    for (int i=0; i < nbStudents; i++){
        CStudent* tmps;
        tmps = this->students[i];
        
        for (int k=0; k< tmps->nbCourses; k++){
            for (int j=0; j< NBEXAMS; j++){
                grades[j] = rand() % 101;
            }
            
            tmps->setCourseGrades(k, grades);
        }
        cout<<"Default grades set for student "<< tmps->name<<endl;
        tmps->printGrades();
        cout<<"----------------------------------------------------------"<<endl;
    }
}

bool CDept::addStudent(CStudent* s) {

    if (this->nbStudents < MAXNBST){
        this->students[this->nbStudents] = s;
        this->nbStudents ++;
        cout<<"New student: "<< *s;
        cout<<"Number of students in "<< this->name <<" department is now"<< this->nbStudents<<endl;
        return true;
    }
    else {
        cout<<"Department "<<this->name<<" is full."<<endl;
        return false;
    }
}

bool CDept::addCourse(CCourse* c) {

    if (this->nbCourses < MAXNBCR){
        this->courses[this->nbCourses] = c;
        this->nbCourses ++;
        cout<<"New course: "<< *c;
        cout<<"Number of courses in "<<this->name<<" department is now "<<this->nbCourses<<"."<<endl;
        return true;
    }
    else {
        cout<<"Department "<<this->name<<" is full."<<endl;
        return false;
    }
}

bool CDept::enroll(CStudent* ps, CCourse* pc) {
    // -- do it here --
    return (ps->enroll(pc), pc->enroll(ps));
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

void CDept::enterStudentGrades(CStudent* ps, CCourse* pc, int* grades) {
    //get index of course
    int courseIndex;
    //catch null pointers first to avoid segmentation fault
    if ((pc == NULL) || (ps == NULL)) {
        cout<<"Student/course doesn't exist."<<endl;
    }
    else if ( ps->isEnrolled(pc) != -1) {
        courseIndex = ps->isEnrolled(pc);
        ps->setCourseGrades(courseIndex, grades);
    }
    else cout<<"Student is not enrolled in course."<<endl;
}

//----------------- 3 extra functions --------------------

CCourse** CDept::findCourses(CStudent* s){
    s->displayCourses();
    return s->courses;
}
void CDept::findBestStudent(CCourse* c){
    c->findBestStudent();
}

CStudent* CDept::ThreeCoursesHighest(){
    
}













