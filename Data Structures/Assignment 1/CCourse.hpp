#ifndef CCourse_hpp
#define CCourse_hpp
#include <iostream>
#include <cstdlib>
using namespace std ;
#include <stdio.h>
#include "CStudent.hpp"

class CStudent;

class CCourse 
{
private:
    char* name;
    int code;
    int capacity;
    CStudent** enrolled;
    int nbEnrolled;
  
public:
    CCourse();
    CCourse(char* vname, int vcode) ;
    ~CCourse() ;
    friend ostream& operator<<(ostream &o, const CCourse &c);
 	friend class CStudent;
    friend class CDept;

public:
    int getNbEnrolled();
    CStudent* getStudent(int id);
    CStudent* findBestStudent();

public:
    bool enroll(CStudent* s);
    int isEnrolled(CStudent* s);
    void displayStudents();
    void displayInfo();
    int* calcAverages();
    int findCourseIndex(CStudent* s);

} ;
#endif



