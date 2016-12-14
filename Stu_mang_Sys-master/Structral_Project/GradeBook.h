//GradeBook.h
//Student Managment System V 1.0
//Advanced Programming (Midterm_Project)
//PersianStudent.ir

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct student
{
    string firstName;
    string lastName;
    int ID;
    int courseNumber;
    struct MyStruct
    {
        int unit;
        string nameOfCourse;
        float score;
    }lesson[20];
    float average;
};

//PersianStudent.ir
struct Node
{
    Node *Next;
    student Data;
    Node()
    {
        Next = NULL;
    }
    Node(student x)
    {
        Next = NULL;
        Data = x;
    }
};

struct list
{
    Node *first;
    list()
    {
        first = NULL;
    }
    bool addStuInfo();
    bool makeFile();
    bool makeFile1();
    bool deleteStuInfo(int);
    bool calStuAverage(int);
    bool findStu(int);
    bool showStuInfo_LinkedList();
    bool showStuInfo_FILE();
};
//PersianStudent.ir
void welcome(); 