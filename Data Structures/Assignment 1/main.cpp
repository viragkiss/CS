#include <iostream>
#include <cstdlib>
//#include <ctime>
#include "CStudent.hpp"
#include "CCourse.hpp"
#include "CDept.hpp"

using namespace std;

// test the cstudent class
void TestStudent()
{
    /*char *n;
   n = new char [100];
   strcpy(n, "Jozsef");
   CStudent s1 (n, 897);*/
    
    //char n[20];
    //CStudent s1 (n, 789);
    //char n[100] = "Jozsef";
    
    CStudent s1 ((char*)"Jozsef", 789);
    CStudent s2((char*) "A", 123);
    /*CStudent s3((char*) "B", 234);
    CStudent s4((char*) "C", 678);
    CStudent s5((char*) "D", 125);
    CStudent s6((char*) "E", 890);
    CStudent s7((char*) "F", 778);*/
    //---------------------------------------------
    CCourse c1((char*)"Discrete maths", 123);
    CCourse c2((char*)"Data Structures", 124);
    CCourse c3((char*)"Algorithms", 126);
    CCourse c4((char*)"CSO", 238);
    CCourse c5((char*)"Visual Art", 567);
    //s1.setNbCourses(5);
    //s2.setNbCourses(3);
    cout<<endl;
    displayInfo(s1);
    cout<<endl;

    //CCourse* pt;
    //pt = &c1;
    //CStudent* ppt; ppt = &s1

    s1.enroll(&c1);
    s1.enroll(&c2);
    s1.enroll(&c3);
    s1.enroll(&c4);
    s1.enroll(&c5);

    //c1.enroll(&s1);

    displayInfo(s1);

}

// test the cstudent class
void TestCourse()
{
    CCourse c1((char*)"Computer Science", 46578);
    CCourse c2((char*)"Visual Art", 265836);
    //c1.setNbEnrolled(10);
    //c2.setNbEnrolled(20);

    cout<<endl;
    displayInfo(c1);
    displayInfo(c2);
    cout<<endl;
}

// main fucntion to test the depart functionnalities
int main(int argc, const char * argv[])
{
    // Test the CStudent class
    TestStudent() ;
    
    // Test the CCourse class
    TestCourse() ;
    
    // Create one dept with some default courses and students
    // Then display all the students and all the courses
        //---- do it here ----
    
    // Display the courses taken by a student with index 2
        //---- do it here ----
    
    // Find the best student in a particular course
    // Dispaly the student info and his/her Total average score
        //---- do it here ----
    
    // Create one dept with some default courses and students
        //---- do it here ----
    
    // Find the courses taken by a prticular student
        //---- do it here ----
    
    // Create a new course and it to the department offering
        //---- do it here ----
    
    // Register 2 students in a newly created course
        //---- do it here ----
    
    // Display the updated list of all courses offered
        //---- do it here ----
    
    // Register 2 students in a newly created course
        //---- do it here ----
    
    // Enter the grades of these 2 students in the new course
        //---- do it here ----
    
    cout << "\n---- I am done ---- Au revoir ----\n\n";
    return 0;
}

