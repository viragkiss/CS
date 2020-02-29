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
     friend class CDept;
     
 public:
     // --- add getters and setters here
    int getNbCourses();
     
 public:
     // --- add grades methods here
 	void setCourseGrades(int courseIndex, int* scores);  
 	void setExamGrade(int courseIndex, int examIndex, int score);  
    void printGrades();

 public:
     // --- add other methods here
    bool enroll(CCourse* c);
    void displayInfo();
    void displayCourses();
    int* calcAverages();
    int isEnrolled(CCourse* c);
 
} ;

#endif
