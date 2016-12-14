//Source.cpp
//Student Managment System V 1.0
//Advanced Programming (Midterm_Project)
//PersianStudent.ir
//Coded by: Ashkan.rmk

#include<iostream>
#include<string>
#include<fstream>
#include"GradeBook.h"

using namespace std;

int main()
{
    welcome();
    system("cls");
    list student;
    while (true)
    {
        cout << "\n\n\t\t*******  MAIN MENU  **********\n\n\n";
        cout << "\tEnter the Following Number for each action:\n\n";
        cout << "\t1) Add Student to list (also save data in a file)\n"
            << "\t2) Delete Student using ID (also delete from file)\n"
            << "\t3) Calculate the Student Average using ID (also save data in a file)\n"
            << "\t4) Show all Students Info\n"
            << "\t5) Find Student using ID\n"
            << "\t6) Remove the FILE saved in PC\n"
            << "\t7) Exit\n";
        int a;
        cout << "\n\t-> ";
        cin >> a;
        string an;
        switch (a)
        {
        case 1:
            system("cls");
            if (student.addStuInfo())
            {
                cout << "\n\n\tWhat do you want to do?\n"
                    << "\t\t1) Make NEW file \n"
                    << "\t\t2) CONTINUE last file ";
                cout << "\n\t\t\t --> ";
                int g;
                cin >> g;
                if (g == 1)
                {
                    student.makeFile1();
                    cout << "\n\n\t* Your Student Info has been ADDED succesfully!\n"
                        << "***********************************************************\n\n\n";
                }
                else
                {
                    if (student.makeFile())
                        cout << "\n\n\t* Your Student Info has been ADDED succesfully!\n"
                        << "***********************************************************\n\n\n";
                    cout << "\n\n\t* There isn't any FILE saved in your PC!\n\n\n";
                }
            }
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            int c;
            cout << "\n\tPlease Enter the ID of student you want to be delete :" << endl;
            cout << "\t\t --> ";
            cin >> c;
            if (student.deleteStuInfo(c))
            {
                cout << "\n\n\t* Your Student Info has been DELETED succesfully!\n"
                    << "***********************************************************\n\n\n";
            }
            else
            {
                cout << "\n\n\t* There isn't any Student with this code " << c << "\n"
                    << "***********************************************************\n\n\n";
            }
            system("pause");
            system("cls");
            break;
            //PersianStudent.ir
        case 3:
            system("cls");
            int d;
            cout << "\n\tPlease Enter the ID of student for Calculating AVERAGE :" << endl;
            cout << "\t\t --> ";
            cin >> d;
            if (student.calStuAverage(d))
            {
                cout << "\n***********************************************************\n\n\n";
            }
            else
            {
                cout << "\n\n\t* There isn't any Student with this ID " << d << "\n"
                    << "***********************************************************\n\n\n";
            }
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            int x;
            cout << "\n\t\tWhat do you want to show:\n"
                << "\t\t1) From Saved FILE\n"
                << "\t\t2) From Database(Linked List)" << endl;
            cout << "\t\t --> ";
            cin >> x;
            if (x == 1)
            {
                if (student.showStuInfo_FILE())
                    cout << endl;
                else
                {
                    cout << "\n\n\t\t* There isn't any File saved in your PC!\n\n";
                }
            }
            else
            {
                if (student.showStuInfo_LinkedList())
                    cout << endl;
                else
                {
                    cout << "\n\n\t\t* There isn't any Linked List!\n\n";
                }
            }
            //PersianStudent.ir
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            int e;
            cout << "\n\tPlease Enter the ID of student for Showing INFO :" << endl;
            cout << "\t\t --> ";
            cin >> e;
            if (student.findStu(e))
            {
                cout << "\n*****************************************************\n";
            }
            else
            {
                cout << "\n\n\t* There isn't any Student with this ID " << e << "\n"
                    << "***********************************************************\n\n\n";
            }
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << "\n\n\t* Are you sure to remove the FILE saved in PC (y/n)";
            cout << "\n\n\t\t --> ";
            cin >> an;
            if (an == "y")
            {
                remove("Student.txt");
                cout << "\n\n\tYour FILE has been removed from PC succesfully!\n"
                    << "************************************************************\n\n";
            }
            system("pause");
            system("cls");
            break;
            //PersianStudent.ir
        default:
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\n\t\t\t\t*** SEE YOU SOON ***\n" << endl
                << "\t\t\t\t      GOOD BYE\n\n\n\n" << endl << endl << endl;
            system("pause");
            exit(1);
            break;
        }
    }
} 