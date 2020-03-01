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
    cout<<endl;
    cout<<"----------------- Run TestStudent() -------------------------"<<endl;
    cout<<endl;

    srand((unsigned int)time(0));

    int studentArrayLen = 8;
    int courseArrayLen = 5;
    //mock student array
    CStudent ss[] = {CStudent((char*)"Mark", 677), CStudent((char*)"Lili", 123), CStudent((char*)"Bela", 567), CStudent((char*)"Anna", 345),
    CStudent((char*)"Bogi", 876), CStudent((char*)"Alia", 321), CStudent((char*)"Isaiah", 908), CStudent((char*)"Jakub", 908)};
    //mock course array
    CCourse cc[] = {CCourse((char*)"Discrete maths", 123), CCourse((char*)"Data Structures", 124), CCourse((char*)"Algorithms", 126),
    CCourse((char*)"CSO", 238), CCourse((char*)"Machine Learning", 567)};
    
    //test enroll() for 2 students
    for (int i=0; i < courseArrayLen; i++){
        if ((ss[0].enroll(&cc[i])) == false){
            cout<<"Schedule is full. Can't enroll in more courses."<<endl;
        }
        else ss[0].enroll(&cc[i]);
    } cout<<endl;

    for (int i=0; i < courseArrayLen; i++){
        if ((ss[2].enroll(&cc[i])) == false){
            cout<<"Schedule is full. Can't enroll in more courses."<<endl;
        }
        else ss[2].enroll(&cc[i]);
    } cout<<endl;    
    cout<<"----------------------------------------------------------"<<endl;

    //test grades methods and display/print methods for 2 students
    int* scores;
    scores = new int[NBEXAMS];
    int numCourses1 = ss[0].getNbCourses();
    int numCourses2 = ss[2].getNbCourses();

    for (int i=0; i<numCourses1; i++){
        for (int j=0; j<NBEXAMS; j++){
           scores[j] = rand() % 101;
        }
        ss[0].setCourseGrades(i, scores);
    }

    for (int i=0; i<numCourses2; i++){
        for (int j=0; j<NBEXAMS; j++){
           scores[j] = rand() % 101;
        }
        ss[2].setCourseGrades(i, scores);
    }
    
    ss[0].displayInfo();  ss[0].printGrades();  cout<<endl;
    ss[2].displayInfo();  ss[2].printGrades();  cout<<endl;
    cout<<"----------------------------------------------------------"<<endl;


    // test displayCourses() for 2 students
    cout<<"Here I'm displaying the courses of 2 students."<<endl;
    cout<<"Student 1:"<<endl;
    cout<<endl;
    ss[0].displayCourses();
    cout<<"Student 2: "<<endl;
    ss[2].displayCourses();
    cout<<"----------------------------------------------------------"<<endl;

    
    // test averages for 2 students
    ss[0].calcAverages();
    ss[2].calcAverages();
    int i1, i2;
    i1 = ss[0].calcAverage(&cc[0]);
    i2 = ss[2].calcAverage(&cc[0]);
    cout<<"Averages: "<<i1 <<", "<< i2 <<endl;
    cout<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    // test isEnrolled() for 1 student
    int is1 = ss[0].isEnrolled(&cc[2]);
    cout<<is1<<endl;
    int is2 = ss[0].isEnrolled(&cc[4]);
    cout<<is2<<endl;
    cout<<"----------------------------------------------------------"<<endl;
}

// test the cstudent class
void TestCourse()
{
    cout<<endl;
    cout<<"----------------- Run TestCourse() -------------------------"<<endl;
    cout<<endl;

    int studentArrayLen = 8;
    int courseArrayLen = 5;
    //mock student array
    CStudent ss[] = {CStudent((char*)"Mark", 677), CStudent((char*)"Lili", 123), CStudent((char*)"Bela", 567), CStudent((char*)"Anna", 345),
    CStudent((char*)"Bogi", 876), CStudent((char*)"Alia", 321), CStudent((char*)"Isaiah", 908), CStudent((char*)"Jakub", 908)};
    //mock course array
    CCourse cc[] = {CCourse((char*)"Discrete maths", 123), CCourse((char*)"Data Structures", 124), CCourse((char*)"Algorithms", 126),
    CCourse((char*)"CSO", 238), CCourse((char*)"Machine Learning", 567)};

    // test enroll functions
    for (int i=0; i < studentArrayLen; i++){
        cc[0].enroll(&ss[i]);
    }

    int in1 = cc[0].isEnrolled(&ss[1]);
    cout<<in1<<endl;
    int in2 = cc[0].isEnrolled(&ss[7]);
    cout<<in2<<endl;

    int enr = cc[0].getNbEnrolled();
    cout<<"Number of students enrolled in course: "<< enr <<endl;


    cout<<"----------------------------------------------------------"<<endl;

    // test display functions
    cc[0].displayStudents();
    cc[0].displayInfo();
    cout<<"----------------------------------------------------------"<<endl;

    // test getStudent()
    cc[0].getStudent(3);
    cc[0].getStudent(7);
    cout<<"----------------------------------------------------------"<<endl;

    // test findBestStudent()
    cc[0].findBestStudent();

    cout<<"----------------------------------------------------------"<<endl;

    // test averages function
    int* averagesArray;
    averagesArray = new int [enr];
    averagesArray = cc[0].calcAverages();
    for (int i=0; i < enr; i++){
        cout<<averagesArray[i]<<", ";
    }
    cout<<endl;
    cout<<"----------------------------------------------------------"<<endl;


}

// main fucntion to test the depart functionnalities
int main(int argc, const char * argv[])
{

    srand((unsigned int)time(0));
    // Test the CStudent class
    TestStudent() ;
    
    // Test the CCourse class
    TestCourse() ;

    cout<<endl;
    cout<<"----------------- Run Main() -------------------------"<<endl;
    cout<<endl;
    
    // Create one dept with some default courses and students
    CDept dept = CDept((char*)"BA Computer Science");

    cout<<"----------------------------------------------------------"<<endl;
    // Then display all the students and all the courses

    dept.displayStudents();
    dept.displayCourses();

    cout<<"----------------------------------------------------------"<<endl;
    

    // Display the courses taken by a student with index 2
    (dept.getStudent(2))->displayCourses();

    cout<<"----------------------------------------------------------"<<endl;
    
    // Find the best student in a particular course
    CStudent* bestStudent;
    CCourse* course;
    course = dept.getCourse(0);
    bestStudent = dept.findBestStudent(course);
    
    // Dispaly the student info and his/her Total average score
    if (bestStudent != NULL){
        
        bestStudent->displayInfo();
        int* bestStudentAverages;
        bestStudentAverages = bestStudent->calcAverages();

        int nbCourses = bestStudent->getNbCourses();
        int total = 0;
        for (int i=0; i < nbCourses; i++){
            total = total + bestStudentAverages[i];
        }

        total = total / nbCourses;
        cout<<"Best student average score is: "<< total << endl;
    }
    else cout<<"No best student, course is empty."<<endl;
    
    cout<<"----------------------------------------------------------"<<endl;

    // Create one dept with some default courses and students
    CDept dept2((char*) "MA Computer Science");

    cout<<"----------------------------------------------------------"<<endl;
    
    // Find the courses taken by a particular student
    CStudent* student;
    student = dept2.getStudent(2);
    dept.findCourses(student);

    cout<<"----------------------------------------------------------"<<endl;
    
    // Create a new course and it to the department offering
    CCourse c3((char*)"Data Structures", 356);
    CCourse* ptr;
    ptr = &c3;
    dept.addCourse(ptr);
    dept.displayCourses();

    cout<<"----------------------------------------------------------"<<endl;
    
    // Register 2 students in a newly created course
    for(int i=0; i<2 ; i++){
        CStudent* tmpss;
        tmpss = dept.getStudent(i);
        dept.enroll(tmpss, ptr);
        tmpss->displayInfo();
    }
    
    cout<<"----------------------------------------------------------"<<endl;
    
    // Display the updated list of all courses offered
    dept.displayCourses();

    cout<<"----------------------------------------------------------"<<endl;

    // Enter the grades of these 2 students in the new course
    int* grades;
    grades = new int [NBEXAMS];
    
    for(int i=0; i<2 ; i++){
        CStudent* tmpss;
        tmpss = dept.getStudent(i);
        cout<<endl;

        for (int j=0; j < NBEXAMS; j++){
            grades[j] = rand() % 101;
        }
        dept.enterStudentGrades(tmpss, ptr, grades);
        tmpss->printGrades();
        cout<<endl;
    }

    cout<<"----------------------------------------------------------"<<endl;


    cout << "\n---- I am done ---- Au revoir ----\n\n";
    return 0;
}

