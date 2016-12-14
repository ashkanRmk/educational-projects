//Stu_Mang.h
//Advanced Programming Final Project
//Student Managment System ver.1
//Visit US: www.PersianStudent.ir
//Telegram: @PersianStudent
//Coded By : Ashkan.rmk
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>

using namespace std;

struct MidTerm
{
    int Term_num;                // Number of Term ( 1 - 10 )
    string Mid_Name;            // Name of Each midterm of Student
    string Educate_Year;        // Educated Year of Student (eg: 93-94)
    string Statuse;                // University Name(From - To)   ,  Statuse(Active,DeletedTerm,Off Time)
    short int Num_Statuse;        // 0=Active , 1=Deleted Term , 2=Off Time , 3=Guest From uni , 4=Guest To uni
    int Total_Mid_Units = 0;
    int Course_Num;
    struct Stu_Lesson
    {
        string Course_Name;
        int Unit;
        float Score;
    }Lesson[30];
    int Pass_Mid_Unit = 0;
    float Term_Average = 0;
    bool Failed;                // If Student Failed At midterm = TRUE
};

struct Educate_Year
{                            // Each Educated Year has 3 Midterms
    MidTerm Term[2];        //0=First Midterm   ,  1=Second Midterm  ,  2=Summer Midterm
};
//PersianStudent.ir

class Personal_Info
{
public:
    void Set_Personal_Info();
    string getFname();
    string getLname();
protected:
    string First_Name;
    string Last_Name;
    int National_Code;
    int Certificate_Code;
    string Father_Name;
};

class Student_Info :public Personal_Info
{
public:
    Student_Info()
    {                            //Constructor will initialize Datas
        Current_Year = 0;
        Current_Term = 0;
        Total_Average = 0;
        total_temp = 0;
        total_m = 0;
        Total_Pass_Units_AllMids = 0;
        Total_Units_AllMids = 0;
        Failed_Mids_Num = 0;
        Last_Failed_Mid = 0;
        Total_Guest_To_Num = 0;
        Total_Guest_From_Num = 0;
        Max_Edu = 0;
    }
    string getSection();
    string getMain_Uni();
    float getTotal_avg();
    int getEntry_year();
    string getField();
    string getTrend();
    int getID();
    int getMaxyear();
    Educate_Year getEducate_Year();
    void Set_Student_Info();
    void Show_Student_Info();    //Show General Student Info
    void Set_Midterm();            //Set each Mid term of Student
    bool Write_Student_Info();    //Make Output File with General Student Info (Student_Info.txt)
    bool Write_Midterm_Info();    //Make Output File with Student Midterms Info (MidTerms_Info.txt)
    bool Write_Result_Info();    //Make Output File with Student Result Info in All Midterms (Result_Info.txt)
    bool Write_Specific_Info();    //Make Output File With Accending Sorted Specific Students in By Total Average (Sorted_Students.txt)
    void Show_Student_Detail();    //Show Student Resuts in All Mid terms and All Educated Years
    void setNULL();
protected:
    int Current_Year;            //maximum of cuurrent year depends on student Section (kardani max4,karshenasi max6,arshad max4)
    int Current_Term;            //Shows your Midterm statuse 0=first , 1=second , 2=summer
    Educate_Year *Year;            //Pointer for dynamic array of educate year for each sections
    int ID;
    string Main_Uni;
    string Section_Stu;            //3 Value - Kardani - Karshenasi - Arshad
    string Field;
    string Trend;
    int Entry_Year;
    int Max_Edu;
    //////TOTAL/////////
    float Total_Average;
    float total_temp;
    int total_m;
    int Total_Pass_Units_AllMids;
    int Total_Units_AllMids;
    int Failed_Mids_Num;
    int Last_Failed_Mid;
    int Total_Guest_To_Num;
    int Total_Guest_From_Num;
};
//PersianStudent.ir

void welcome();
void gotoxy(int, int);
void Loading();
bool Add_Student(Student_Info *, int, int);
void Add_Midterm(Student_Info *, int, int);
bool Show_Result_Allmids(Student_Info *, int, int);
bool Delete_Student(Student_Info *, int, int, int);
void Write_Info_File(Student_Info *, int);
void Total_Student(Student_Info *, int, string, int);
void Ranked1_Stu_Total_avg(Student_Info *, int, string, int, string, string, string);
void Ranked1_Stu_Mid_avg(Student_Info *, int, string, int, string, string, string, int, int);
void Sort_Student(Student_Info *, int, string, int, string, string, string);