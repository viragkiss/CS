#ifndef CStudent_hpp
#define CStudent_hpp
#include <iostream>
#include <cstdlib>
using namespace std ;
#include <string>
#include <stdio.h>
#include "CCourse.hpp"

 class CCourse;

 class CStudent {
 private:
     // --- add attributes here
 	char* name;
 	int id;
 	int maxCourses;
 	int maxExams;
 	int nbCourses;
 	CCourse** courses;
 	int **grades;
 
 public: //Memory management methods
     // --- constr, desctructor add Memory management methods here
     CStudent();
     CStudent(char* vname, int vid) ;
     ~CStudent() ;
     friend ostream& operator<<(ostream &o, const CStudent &s);
     friend class CCourse;
     bool enroll(CCourse* c);  // receive a pointer to a course, adds this pointer to the array of courses, and increases the attribute nbCourses
     
 public:
     // --- add getters and setters here
 	void displayInfo();
     
 public:
     // --- add grades methods here
 	void setCourseGrades(int courseIndex, int* scores);  // receive a course index (0<=ci<NbCourses) and an array of scores to be used to set the 
    //rades of course ci
 	void setExamGrade(int courseIndex, int examIndex, int score);  // receive a course index (ci), an exam index (0<=ei<NBEXAM),
    //and a score to be stored as the grade of exam ei in the course ci.

 public:
     // --- add other methods here
    void printGrades();
    void displayCourses();  //traverse the array of courses and displays the information of each course
    						//(code, name, capacity, and number of students enrolled) by calling the method CCourse::displayInfo()
    int* calcAverages(); //calculate the average grade for each of the courses taken by the student, returns the averages as an array
 
} ;

#endif
