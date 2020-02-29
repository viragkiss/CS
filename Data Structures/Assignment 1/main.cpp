#include <iostream>
#include <cstdlib>
#include <time.h>
#include "CStudent.hpp"
#include "CCourse.hpp"
#include "CDept.hpp"

using namespace std;

// test the cstudent class
void TestStudent()
{
    srand((unsigned int)time(0));

    //mock student array
    CStudent ss[] = {CStudent((char*)"Mark", 677), CStudent((char*)"Lili", 123), CStudent((char*)"Bela", 567), CStudent((char*)"Anna", 345),
    CStudent((char*)"Bogi", 876), CStudent((char*)"Alia", 321), CStudent((char*)"Isaiah", 908), CStudent((char*)"Jakub", 908)};
    //mock course array
    CCourse cc[] = {CCourse((char*)"Discrete maths", 123), CCourse((char*)"Data Structures", 124), CCourse((char*)"Algorithms", 126),
    CCourse((char*)"CSO", 238), CCourse((char*)"Machine Learning", 567)};
    
    ss[0].displayInfo();
    
    cout<<endl;

    ss[0].enroll(&cc[0]); //fix up - enroll student in course and course in student
    ss[0].enroll(&cc[1]);
    ss[0].enroll(&cc[2]);
    ss[0].enroll(&cc[3]);
    ss[0].enroll(&cc[4]);

    cc[0].displayInfo();

    cc[0].enroll(&ss[0]);
    cc[0].enroll(&ss[1]);
    cc[0].enroll(&ss[2]);
    cc[0].enroll(&ss[3]);
    cc[0].enroll(&ss[4]);
    cc[0].enroll(&ss[5]);
    cc[0].enroll(&ss[6]);
    cc[0].enroll(&ss[7]);

    ss[0].displayInfo();
    ss[2].displayInfo();
    ss[3].displayInfo();
    cc[0].displayInfo();

    //test setCourseGrades()
    int* scores;
    scores = new int[NBEXAMS];

    for (int i=0; i<MAXCRST; i++){
        for (int j=0; j<NBEXAMS; j++){
           scores[j] = rand() % 101;
        }
        ss[0].setCourseGrades(i, scores);  //pass array to course and set course grades
        cout<<"i is "<<i<<endl;
    }
    
    ss[0].displayInfo();

    cout<<"Here I'm displaying the courses of 2 students. Student 1: "<<endl;
    cout<<endl;
    ss[0].displayCourses();
    cout<<"Student 2: "<<endl;
    ss[3].displayCourses();
    cout<<endl;
    cc[0].displayInfo();

    ss[0].calcAverages();
    ss[3].calcAverages();

    cc[0].calcAverages();
    cc[2].calcAverages();
    

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
    srand((unsigned int)time(0));
    // Test the CStudent class
    TestStudent() ;
    
    // Test the CCourse class
    TestCourse() ;
    
    // Create one dept with some default courses and students
    // Then display all the students and all the courses
        //---- do it here ----
    CDept dept = CDept((char*)"Computer Science");
    dept.getCourse(1);
    dept.getStudent(2);

    dept.displayStudents();
    dept.displayCourses();

    CStudent* s1 = dept.getStudent(10);
    CCourse* c1 = dept.getCourse(10);
    
    int* grades;
    grades = new int [NBEXAMS];
    for (int i=0; i<NBEXAMS; i++){
        grades[i] = rand() % 101;
    }

    dept.enterStudentGrades(s1, c1, grades);
    
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
        CCourse c3((char*)"Data Structures", 356);
        CCourse* ptr;
        ptr = &c3;
        dept.addCourse(ptr);
        dept.displayCourses();
    
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

