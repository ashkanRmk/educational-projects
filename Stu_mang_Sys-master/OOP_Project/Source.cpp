//Source CODE
//Advanced Programming Final Project
//Student Managment System ver.1
//Visit US: www.PersianStudent.ir
//Telegram: @PersianStudent
//Coded By : Ashkan.rmk

#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include"Stu_Mang.h"
using namespace std;

int main()
{
    welcome();
    system("cls");
    cout << "\n\n\n\n\n\n\t\tPlease Enter MAXIMUM Number of All Students:";
    cout << "\n\n\t\t-> ";
    int num;
    cin >> num;
    Student_Info * Student;
    Student = new Student_Info[num];
    int count = 0;
    system("cls");
    Loading();
    system("cls");
    string an;
    while (true)
    {
        cout << "\n\n\t\t*******  MAIN MENU  **********\t\tTotal Students < " << num << " >\n\n\n";
        cout << "\tEnter the Following Number for each action:\n\n";
        cout << "\t1) Add New Student (Maximum " << num - count << " times)\n"
            << "\t2) Add New MidTerm for Student using ID\n"
            << "\t3) Delete Student using ID\n"
            << "\t4) Show Result of All Midterms using ID\n"
            << "\t5) Delete Saved FILES!\n"
            << "\t6) Total Students in Specific University\n"
            << "\t7) Ranked 1 Student by Total Average\n"
            << "\t8) Ranked 1 Student by Midterm Average\n"
            << "\t9) Sorting Specific Students By Total Average\n"
            << "\t10) Exit\n";
        int x;
        string main;
        int entyear = 0;
        string sec;
        string trnd;
        string fld;
        int trm = 0;
        int edy = 0;
        cout << "\n\t-> ";
        cin >> x;
        switch (x)
        {
        case 1:
            system("cls");
            if (Add_Student(Student, num, count))
            {
                system("cls");
                cout << "\n\n\n\n\t\t\tYour Student has been ADDED!\n\n";
                count++;
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\t\t\tYou Can Add Student For Maximum: " << count << " Times!"
                    << "\n\t\t\tNow You can't Add Student anymore!!!\n\n";
                system("pause");
                system("cls");
            }
            break;
        case 2:
            system("cls");
            int code;
            cout << "\n\n\n\tFor Adding NEW MidTerm\n\tPlease Enter the ID of student:";
            cout << "\n\t\t --> ";
            cin >> code;
            Add_Midterm(Student, count, code);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            int delc;
            cout << "\n\n\n\tFor Deleting \n\tPlease Enter the ID of student:";
            cout << "\n\t\t --> ";
            cin >> delc;
            if (Delete_Student(Student, num, delc, count))
            {
                cout << "\n\n\tYour Student has been Deleted!\n";
                count--;
                Write_Info_File(Student, count);
                system("pause");
                system("cls");
            }
            else
            {
                cout << "\n\n\tThere isn't any student with this ID : " << delc << endl;
                system("pause");
                system("cls");
            }
            break;
        case 4:
            system("cls");
            int cd;
            cout << "\n\n\n\tFor Deatail Result of ALL MidTerm\n\tPlease Enter the ID of student:";
            cout << "\n\t\t --> ";
            cin >> cd;
            if (Show_Result_Allmids(Student, count, cd))
            {
                cout << "\n*************************************************\n\n";
                system("pause");
                system("cls");
            }
            else
            {
                cout << "\n\n\tThere isn't any student with this ID : " << cd << endl;
                system("pause");
                system("cls");
            }
            break;
        case 5:
            system("cls");
            cout << "\n\n\t* Are you sure to remove FILES saved in PC (y/n)";
            cout << "\n\n\t\t --> ";
            cin >> an;
            if (an == "y")
            {
                remove("Student_Info.txt");
                remove("Result_Info.txt");
                remove("MidTerms_Info.txt");
                remove("Sorted_Students.txt");
                cout << "\n\n\tYour FILE has been removed from PC succesfully!\n"
                    << "************************************************************\n\n";
            }
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << "\n\n\n\tFor Get Students Number of Specific University\n\tPlease Enter Info Below:";
            cout << "\n\n\t\t --> ";
            cout << "\n\t\t\t Main University:";
            cin >> main;
            cout << "\n\t\t\t Entry Year:";
            cin >> entyear;
            Total_Student(Student, count, main, entyear);
            system("pause");
            system("cls");
            //PersianStudent.ir

            break;
        case 7:
            system("cls");
            cout << "\n\n\n\tFor Get Ranked 1 Student of Specific University\n\tBy Total Average in All MidTerms\n\tPlease Enter Info Below:";
            cout << "\n\n\t\t --> ";
            cout << "\n\t\t\t Main University:";
            cin >> main;
            cout << "\n\t\t\t Entry Year:";
            cin >> entyear;
            cout << "\n\t\t\t Section:";
            cin >> sec;
            cout << "\n\t\t\t Feild Of Study:";
            cin >> fld;
            cout << "\n\t\t\t Trend:";
            cin >> trnd;
            Ranked1_Stu_Total_avg(Student, count, main, entyear, sec, trnd, fld);
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            int con;
            cout << "\n\n\n\tFor Get Ranked 1 Student of Specific University\n\tBy Average in which MidTerm and Educated Year"
                << "\n\tPlease Enter Info Below:";
            cout << "\n\n\t\t --> ";
            cout << "\n\t\t\t Main University:";
            cin >> main;
            cout << "\n\t\t\t Entry Year:";
            cin >> entyear;
            cout << "\n\t\t\t Section:";
            cin >> sec;
            cout << "\n\t\t\t Feild Of Study:";
            cin >> fld;
            cout << "\n\t\t\t Trend:";
            cin >> trnd;
            cout << "\n\t\tWhich Midterm? (1 - 3)"
                << "\n\n\t\t1) First Midterm"
                << "\n\t\t2) Second Midterm"
                << "\n\t\t3) Summer Midterm";
            cout << "\n\n\t\t --> ";
            cin >> con;
            while (con > 3 || con < 1)
            {
                cout << "\n\t\tYou Must Input between 1 to 3\n\t\tTry Again: ";
                cin >> con;
            }
            switch (con)
            {
            case 1:
                trm = con - 1;
                break;
            case 2:
                trm = con - 1;
                break;
                //PersianStudent.ir

            case 3:
                trm = con - 1;
                break;
            }
            cout << "\n\t\t\t Which Educated Year:";
            cin >> edy;
            Ranked1_Stu_Mid_avg(Student, count, main, entyear, sec, trnd, fld, trm, edy);
            system("pause");
            system("cls");
            break;
        case 9:
            system("cls");
            cout << "\n\n\n\tFor Get Accending Sorted Of Specific Students\n\tBy Total Average in All MidTerms\n\tPlease Enter Info Below:";
            cout << "\n\n\t\t --> ";
            cout << "\n\t\t\t Main University:";
            cin >> main;
            cout << "\n\t\t\t Entry Year:";
            cin >> entyear;
            cout << "\n\t\t\t Section:";
            cin >> sec;
            cout << "\n\t\t\t Feild Of Study:";
            cin >> fld;
            cout << "\n\t\t\t Trend:";
            cin >> trnd;
            Sort_Student(Student, count, main, entyear, sec, trnd, fld);
            system("pause");
            system("cls");
            break;
            //PersianStudent.ir

        default:
            system("cls");
            system("color 04");
            cout << "\t\t\n\n\n\n\n\n\n\n\t\t\t\t*** SEE YOU SOON ***\n" << endl;
            Sleep(300);
            cout << "\t\t\t\t      GOOD BYE\n\n\n\n" << endl << endl << endl;
            system("pause");
            exit(1);
            break;
        }
    }
} 
