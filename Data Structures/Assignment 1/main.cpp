#include <iostream>
#include <cstdlib>
//#include <time.h>
#include <ctime>
#include "CStudent.hpp"
#include "CCourse.hpp"
#include "CDept.hpp"

using namespace std;

// test the cstudent class
void TestStudent()
{
    //srand((unsigned int)time(0));
    srand(time(NULL));
    //array student
    CStudent ss[] = {CStudent((char*)"Mark", 677), CStudent((char*)"Lili", 123), CStudent((char*)"Bela", 567), CStudent((char*)"Anna", 345),
    CStudent((char*)"Bogi", 876), CStudent((char*)"Alia", 321), CStudent((char*)"Isaiah", 908), CStudent((char*)"Jakub", 908)};
    //array course
    CCourse cc[] = {CCourse((char*)"Discrete maths", 123), CCourse((char*)"Data Structures", 124), CCourse((char*)"Algorithms", 126),
    CCourse((char*)"CSO", 238), CCourse((char*)"Machine Learning", 567)};


    /*CStudent s1 ((char*)"Mark", 677);
    CStudent s2 ((char*)"Lili", 123);
    CStudent s3 ((char*)"Bela", 567);
    CStudent s4 ((char*)"Anna", 345);
    CStudent s5 ((char*)"Bogi", 876);
    CStudent s6 ((char*)"Alia", 321);
    CStudent s7 ((char*)"Isaiah", 908);
    CStudent s8 ((char*)"Jakub", 908);
    //---------------------------------------------
    CCourse c1((char*)"Discrete maths", 123);
    CCourse c2((char*)"Data Structures", 124);
    CCourse c3((char*)"Algorithms", 126);
    CCourse c4((char*)"CSO", 238);
    CCourse c5((char*)"Machine Learning", 567);
    cout<<endl;*/
    
    ss[0].displayInfo();
    
    cout<<endl;

    /*ss[0].enroll(&cc[0]);
    ss[0].enroll(&cc[1]);
    ss[0].enroll(&cc[2]);
    ss[0].enroll(&cc[3]);
    ss[0].enroll(&cc[4]);*/

    cc[0].displayInfo();

    /*c1.enroll(&ss[0]);
    c1.enroll(&ss[2]);
    c1.enroll(&s3);
    c1.enroll(&s4);
    c1.enroll(&s5);
    c1.enroll(&s6);
    c1.enroll(&s7);
    c1.enroll(&s8);

    ss[0].displayInfo();
    ss[2].displayInfo();
    ss[3].displayInfo();
    c1.displayInfo();

    //test setCourseGrades()
    int* scores;
    scores = new int[NBEXAMS];

    for (int i=0; i<MAXCRST; i++){
        for (int j=0; j<NBEXAMS; j++){
           scores[j] = rand() % 101;
        }
        s1.setCourseGrades(i, scores);  //pass array to course and set course grades
        cout<<"i is "<<i<<endl;
    }
    
    ss[0].displayInfo();

    cout<<"Here I'm displaying the courses of 2 students. Student 1: "<<endl;
    cout<<endl;
    ss[0].displayCourses();
    cout<<"Student 2: "<<endl;
    ss[3].displayCourses();
    cout<<endl;
    c1.displayInfo();


    //cd Desktop/"Data Structures_Ass1".   //////*/
}

// test the cstudent class
void TestCourse()
{
    /*CCourse c2((char*)"Data Structures", 124);
    CCourse c3((char*)"Algorithms", 126);
    CCourse c4((char*)"CSO", 238);
    CCourse c5((char*)"Visual Art", 567);*/
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

