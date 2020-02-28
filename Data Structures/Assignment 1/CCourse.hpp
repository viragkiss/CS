#ifndef CCourse_hpp
#define CCourse_hpp
#include <iostream>
#include <cstdlib>
using namespace std ;
#include <stdio.h>
#include "CStudent.hpp"

class CStudent;

class CCourse {
private:
    // --- add attributes here
    char* name;
    int code;
    int capacity;
    CStudent** enrolled;
    int nbEnrolled;
  
public:
    // --- add constr, distructor, memory management methods here
    CCourse();
    CCourse(char* vname, int vcode) ;
    ~CCourse() ;
    friend ostream& operator<<(ostream &o, const CCourse &c);
    bool enroll(CStudent* s);  //if the course is not full, the function adds this pointer to the array of students enrolled, and increases the attribute nbEnrolled
 	friend class CStudent;

public:
    // --- add getters and setters here
    void displayInfo();

    void getStudent(int id);   // receive an index ind, verify that 0<=ind<NbEnrolled, the returns the student located at this index, or NULL
    void findBestStudent();  // find the student with the highest average score among all the students
							//registered in the course. The caller should get best average score and the index where the
							//best student is located in the array of enrolled students    
public:
    // --- add othe methods here
    void displayStudents();  //traverse the array of enrolled students and calls CStudent::displayInfo() to displays the information of each student
    int* calcAverages(); //calculate the average grade for each of the students enrolled in the course, returns the averages as an array
    int findCourseIndex(CStudent* s);
    
} ;
#endif
