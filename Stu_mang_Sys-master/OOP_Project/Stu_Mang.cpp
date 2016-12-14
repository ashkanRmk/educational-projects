//Stu_Mang.cpp
//Advanced Programming Final Project
//Student Managment System ver.1
//Visit US: www.PersianStudent.ir
//Telegram: @PersianStudent
//Coded By : Ashkan.rmk

#include"Stu_Mang.h"

string Personal_Info::getFname()
{
    return First_Name;
}
string Personal_Info::getLname()
{
    return Last_Name;
}
void Personal_Info::Set_Personal_Info()
{
    cout << "\n\n\t\t\t** Please Enter Personal Info **\n";
    cout << "\n\t\tFirst Name:";
    cin >> First_Name;
    cout << "\n\t\tLast Name:";
    cin >> Last_Name;
    cout << "\n\t\tNational Code:";
    cin >> National_Code;
    cout << "\n\t\tCertification Code:";
    cin >> Certificate_Code;
    cout << "\n\t\tFather's Name:";
    cin >> Father_Name;
    cout << "\n\n************************************************\n";
}
string Student_Info::getSection()
{
    return Section_Stu;
}
string Student_Info::getMain_Uni()
{
    return Main_Uni;
}
float Student_Info::getTotal_avg()
{
    return Total_Average;
}
int Student_Info::getEntry_year()
{
    return Entry_Year;
}
string Student_Info::getField()
{
    return Field;
}
string Student_Info::getTrend()
{
    return Trend;
}
int Student_Info::getID()
{
    return ID;
}
int Student_Info::getMaxyear()
{
    return Max_Edu;
}
Educate_Year Student_Info::getEducate_Year()
{
    return *Year;
}
//PersianStudent.ir

void Student_Info::Set_Student_Info()
{
    cout << "\n\n\t\t\t** Please Enter Student Info **\n";
    cout << "\n\t\tStudent ID Number:";
    cin >> ID;
    cout << "\n\t\tMain University:";
    cin >> Main_Uni;
    cout << "\n\t\tWhat is Student Section?(Enter 1-3)";
    cout << "\n\n\t\t\t1) Kardani\n\t\t\t2) Karshenasi\n\t\t\t3) Arshad";
    cout << "\n\t\t\t\t\t-> ";
    int d;
    cin >> d;
    while (d < 1 || d > 3)
    {
        cout << "\n\t\tYou input Invalid Value ( 1 - 3 )\n\t\tTry Again:";
        cin >> d;
    }
    switch (d)
    {
    case 1:
        Section_Stu = "Kardani";
        Max_Edu = 4;
        Year = new Educate_Year[Max_Edu];        //Maximum of Kardani Duration Years = 4
        break;
    case 2:
        Section_Stu = "Karshenasi";
        Max_Edu = 6;
        Year = new Educate_Year[Max_Edu];        //Maximum of Karshenasi Duration Years = 6
        break;
    case 3:
        Section_Stu = "Arshad";
        Max_Edu = 4;
        Year = new Educate_Year[Max_Edu];        //Maximum of Arshad Duration Years = 4
        break;
    }
    cout << "\n\t\tField Of Study:";
    cin >> Field;
    cout << "\n\t\tTrend:";
    cin >> Trend;
    cout << "\n\t\tEntry Year:";
    cin >> Entry_Year;
    cout << "\n\n************************************************\n";
}
//PersianStudent.ir

void Student_Info::Show_Student_Info()
{
    cout << "\n\n\t\t\t** Personal Info **\n";
    cout << "\n\t\tFirst Name:";
    cout << First_Name;
    cout << "\n\n\t\tLast Name:";
    cout << Last_Name;
    cout << "\n\n\t\tNational Code:";
    cout << National_Code;
    cout << "\n\n\t\tCertification Code:";
    cout << Certificate_Code;
    cout << "\n\n\t\tFather's Name:";
    cout << Father_Name;
    cout << "\n\n\t\tStudent ID Number:";
    cout << ID;
    cout << "\n\n\t\tMain University:";
    cout << Main_Uni;
    cout << "\n\n\t\tStudent Section:";
    cout << Section_Stu;
    cout << "\n\n\t\tTrend:";
    cout << Trend;
    cout << "\n\n\t\tEntry Year:";
    cout << Entry_Year;
    cout << "\n\n************************************************\n";
}

void Student_Info::Set_Midterm()
{
    float Total_Score = 0;        //This Var. use for Calculating the Average of Midterm
    cout << "\n\n\t\t\t** Please Enter MidTerm Info **\n";
    cout << "\n\t\tWhich MidTerm are you ( 1 - 3 )?";
    cout << "\n\n\t\t\t1) First Midterm\n\t\t\t2) Second Midterm\n\t\t\t3) Summer Midterm";
    cout << "\n\t\t\t\t\t-> ";
    int g;
    cin >> g;
    while (g < 1 || g > 3)
    {
        cout << "\n\t\tYou input Invalid Value ( 1 - 3 )\n\t\tTry Again:";
        cin >> g;
    }
    switch (g)
    {
    case 1:
        Current_Term = 0;
        Year[Current_Year].Term[Current_Term].Mid_Name = "First MidTerm";
        break;
    case 2:
        Current_Term = 1;
        Year[Current_Year].Term[Current_Term].Mid_Name = "Second MidTerm";
        break;
    case 3:
        Current_Term = 2;
        Year[Current_Year].Term[Current_Term].Mid_Name = "Summer MidTerm";
        break;
    }
    cout << "\n\t\tEducation Year (Example: 93-94):";
    cin >> Year[Current_Year].Term[Current_Term].Educate_Year;
    cout << "\n\t\tTerm Number ( 1 - 10 ):";
    cin >> Year[Current_Year].Term[Current_Term].Term_num;
    while (Year[Current_Year].Term[Current_Term].Term_num < 1 || Year[Current_Year].Term[Current_Term].Term_num > 10)
    {
        cout << "\n\t\tYou Input invalid Value ( 1 - 10 )\n\t\tTry Again:";
        cin >> Year[Current_Year].Term[Current_Term].Term_num;
    }
    cout << "\n\t\tWhat is Student Statuse ( 1 - 4 ):";
    cout << "\n\n\t\t\t1) Active\n\t\t\t2) Deleted Term\n\t\t\t3) Off Time\n\t\t\t4) Guest";
    cout << "\n\t\t\t\t\t-> ";
    int a;
    cin >> a;
    while (a < 1 || a > 4)
    {
        cout << "\n\t\tYou input Invalid Value ( 1 - 4 )\n\t\tTry Again:";
        cin >> a;
    }
    //PersianStudent.ir

    switch (a)
    {
    case 1:
        Year[Current_Year].Term[Current_Term].Statuse = "Active";
        Year[Current_Year].Term[Current_Term].Num_Statuse = 0;
        break;
    case 2:
        Year[Current_Year].Term[Current_Term].Statuse = "Deleted Term";
        Year[Current_Year].Term[Current_Term].Num_Statuse = 1;
        break;
    case 3:
        Year[Current_Year].Term[Current_Term].Statuse = "Off Time";
        Year[Current_Year].Term[Current_Term].Num_Statuse = 2;
    case 4:
        cout << "\n\t\t\t1) Guest From a University\n\t\t\t2) Guest To a Univerity";
        cout << "\n\t\t\t\t\t-> ";
        int b;
        cin >> b;
        while (b < 1 || b > 2)
        {
            cout << "\n\t\tYou input Invalid Value ( 1 - 2 )\n\t\tTry Again:";
            cin >> b;
        }
        switch (b)
        {
        case 1:
            cout << "\n\t\tEnter University Name (From):";
            cin >> Year[Current_Year].Term[Current_Term].Statuse;
            Total_Guest_From_Num++;
            Year[Current_Year].Term[Current_Term].Num_Statuse = 3;
            break;
        case 2:
            cout << "\n\t\tEnter University Name (To):";
            cin >> Year[Current_Year].Term[Current_Term].Statuse;
            Total_Guest_To_Num++;
            Year[Current_Year].Term[Current_Term].Num_Statuse = 4;
            break;
        }
        break;
    }
    //PersianStudent.ir

    cout << "\n\t\tCourse Number:";
    cin >> Year[Current_Year].Term[Current_Term].Course_Num;
    cout << "\n\n\t\t\t** Enter Courses Info **";
    for (int i = 0; i < Year[Current_Year].Term[Current_Term].Course_Num; i++)
    {
        cout << "\n\n\t\t\t" << i + 1 << "th Course\n";
        cout << "\n\t\tCourse Name:";
        cin >> Year[Current_Year].Term[Current_Term].Lesson[i].Course_Name;
        cout << "\n\t\tCourse Unit (1-3): ";
        cin >> Year[Current_Year].Term[Current_Term].Lesson[i].Unit;
        while (Year[Current_Year].Term[Current_Term].Lesson[i].Unit > 3 || Year[Current_Year].Term[Current_Term].Lesson[i].Unit < 1)
        {
            cout << "\n\t\tYou Must Enter a Number 1 to 3 !!\n\t\tTry Again: ";
            cin >> Year[Current_Year].Term[Current_Term].Lesson[i].Unit;
        }
        cout << "\n\t\tCourse Score:";
        cin >> Year[Current_Year].Term[Current_Term].Lesson[i].Score;
        if (Year[Current_Year].Term[Current_Term].Lesson[i].Score > 10)
        {
            cout << "\n\t\t* This Course has been PASSED!";
            Year[Current_Year].Term[Current_Term].Pass_Mid_Unit += Year[Current_Year].Term[Current_Term].Lesson[i].Unit;
        }
        else
        {
            cout << "\n\t\t* This Course has been FAILED!";
        }
        Year[Current_Year].Term[Current_Term].Total_Mid_Units += Year[Current_Year].Term[Current_Term].Lesson[i].Unit;
        Total_Score += Year[Current_Year].Term[Current_Term].Lesson[i].Score * Year[Current_Year].Term[Current_Term].Lesson[i].Unit;
        cout << "\n\n****************************************************\n";
    }
    Year[Current_Year].Term[Current_Term].Term_Average = Total_Score / Year[Current_Year].Term[Current_Term].Total_Mid_Units;
    if (Year[Current_Year].Term[Current_Term].Term_Average < 10)
    {
        Year[Current_Year].Term[Current_Term].Failed = true;
        Failed_Mids_Num++;
        Last_Failed_Mid = Year[Current_Year].Term[Current_Term].Term_num;
        cout << "\n\n\t\tYou FAILED This MidTerm whith Average:" << Year[Current_Year].Term[Current_Term].Term_Average << endl;
    }
    else
    {
        Year[Current_Year].Term[Current_Term].Failed = false;
        cout << "\n\n\t\tYou PASSED This MidTerm whith Average:" << Year[Current_Year].Term[Current_Term].Term_Average << endl;
    }
    total_m++;
    total_temp += Year[Current_Year].Term[Current_Term].Term_Average;
    Total_Average = total_temp / total_m;
    Total_Units_AllMids += Year[Current_Year].Term[Current_Term].Total_Mid_Units;
    Total_Pass_Units_AllMids += Year[Current_Year].Term[Current_Term].Pass_Mid_Unit;

    if (Current_Term == 2)
    {
        Current_Year++;            //After each 3 Midterms Current Year will ADD 1
    }                            //It Means Student Finished ONE Educated Year
}

bool Student_Info::Write_Student_Info()
{
    fstream output;
    output.open("Student_Info.txt", ios::app);        //open last file and write continue...
    if (!output)
        return false;
    output << "\n\t\t\t* Student Info *\n";
    output << "First Name: " << First_Name << "     " << "Last Name: " << Last_Name << "\n" << "Student ID: " << ID << "\n"
        << "Main University: " << Main_Uni << "\n" << "Section: " << Section_Stu << "\n" << "Field Of Stuudy: " << Field << "     "
        << "Trend: " << Trend << "\n" << "Certification Code: " << Certificate_Code << "\n" << "National Code: " << National_Code << "\n"
        << "Entry Year: " << Entry_Year << "\n" << "Father's Name: " << Father_Name << "\n";
    output << "----------------------------------------\n";
    output.close();
    return true;
}
//PersianStudent.ir

bool Student_Info::Write_Midterm_Info()
{
    fstream output;
    output.open("MidTerms_Info.txt", ios::app);        //open last file and write continue...
    if (!output)
        return false;
    output << "\n************************************************\n"
        << First_Name << "     " << Last_Name << "\n" << ID;
    output << "\n\t\t\t* Midterm Info *\n";
    output << "Term Number:" << Year[Current_Year].Term[Current_Term].Term_num
        << "\nMid Term:";
    switch (Current_Term)
    {
    case 0:
        output << "First MidTerm";
        break;
    case 1:
        output << "Second MidTerm";
        break;
    case 2:
        output << "Summer MidTerm";
        break;
    }
    output << "\nEducated Year:" << Year[Current_Year].Term[Current_Term].Educate_Year
        << "\nStatuse Of Student:";
    switch (Year[Current_Year].Term[Current_Term].Num_Statuse)
    {
    case 0:
        output << Year[Current_Year].Term[Current_Term].Statuse;
        break;
    case 1:
        output << Year[Current_Year].Term[Current_Term].Statuse;
        break;
    case 2:
        output << Year[Current_Year].Term[Current_Term].Statuse;
        break;
    case 3:
        output << "Guest From " << Year[Current_Year].Term[Current_Term].Statuse;
        break;
    case 4:
        output << "Guest To " << Year[Current_Year].Term[Current_Term].Statuse;
        break;
    }
    output << "\nTotal Units in Midterm:" << Year[Current_Year].Term[Current_Term].Total_Mid_Units
        << "\nTotal Courses in Midterm:" << Year[Current_Year].Term[Current_Term].Course_Num
        << "\nTotal PASSED Units:" << Year[Current_Year].Term[Current_Term].Pass_Mid_Unit
        << "\nAverage Of Midterm:" << Year[Current_Year].Term[Current_Term].Term_Average
        << "\nStatuse Of Midterm:";
    if (Year[Current_Year].Term[Current_Term].Failed)
    {
        output << "FAILED!";
    }
    else if (!Year[Current_Year].Term[Current_Term].Failed)
    {
        output << "PASSED!";
    }
    output << "\n\n----------------------------------------\n";
    output.close();
    return true;
}
//PersianStudent.ir

bool Student_Info::Write_Result_Info()
{
    fstream output;
    output.open("Result_Info.txt", ios::app);
    if (!output)
        return false;
    output << "\n\t\t\t* Student Info *\n";
    output << "First Name: " << First_Name << "     " << "Last Name: " << Last_Name << "\n" << "Student ID: " << ID << "\n"
        << "Main University: " << Main_Uni << "\n" << "Section: " << Section_Stu << "\n" << "Field Of Stuudy: " << Field << "     "
        << "Trend: " << Trend << "\n" << "Certification Code: " << Certificate_Code << "\n" << "National Code: " << National_Code << "\n"
        << "Entry Year: " << Entry_Year << "\n" << "Father's Name: " << Father_Name << "\n";
    output << "----------------------------------------\n";
    output << "\n\t* Student Result Info in < " << total_m << " > MidTerms *\n";
    output << "Total Units in All Midterms: " << Total_Units_AllMids
        << "\nTotal PASSED Units in All Midterms: " << Total_Pass_Units_AllMids
        << "\nTotal Average: " << Total_Average
        << "\nNumber Of FAILED Midterms: " << Failed_Mids_Num
        << "\nLast Failed Midterm: " << Last_Failed_Mid
        << "\n   <Guest Satuse>\nNumber Of Guesting FROM University: " << Total_Guest_From_Num
        << "\nNumber Of Guesting TO University: " << Total_Guest_To_Num;
    output << "\n----------------------------------------\n";
    output.close();
    return true;
}

bool Student_Info::Write_Specific_Info()
{
    fstream output;
    output.open("Sorted_Students.txt", ios::app);        //open last file and write continue...
    if (!output)
        return false;
    output << "\n\t\t\t* Student Info *\n";
    output << "First Name: " << First_Name << "     " << "Last Name: " << Last_Name << "\n" << "Student ID: " << ID << "\n"
        << "Main University: " << Main_Uni << "\n" << "Section: " << Section_Stu << "\n" << "Field Of Stuudy: " << Field << "     "
        << "Trend: " << Trend << "\n" << "Certification Code: " << Certificate_Code << "\n" << "National Code: " << National_Code << "\n"
        << "Entry Year: " << Entry_Year << "\n" << "Father's Name: " << Father_Name << "\n"
        << "Total Average: " << Total_Average;
    output << "\n----------------------------------------\n";
    output.close();
    return true;
}
//PersianStudent.ir

void Student_Info::Show_Student_Detail()
{
    Show_Student_Info();
    cout << "\n\n\t\t\t** Educating Info **\n";
    cout << "\n\t\tTotal Average in All Mids:" << Total_Average
        << "\n\t\tTotal Units in All Mids:" << Total_Units_AllMids
        << "\n\t\tTotal Units PASSED all Mids:" << Total_Pass_Units_AllMids
        << "\n\t\tNumber Of Failed Midterms:" << Failed_Mids_Num
        << "\n\t\tNumber Of Last Term that Failed:" << Last_Failed_Mid
        << "\n\t\tNumber Of Guesting TO a university:" << Total_Guest_To_Num
        << "\n\t\tNumber Of Guesting FROM a university:" << Total_Guest_From_Num;
    cout << "\n\n************************************************\n";
}

void Student_Info::setNULL()
{
    First_Name = " ";
    Last_Name = " ";
    National_Code = 0;
    Certificate_Code = 0;
    Father_Name = " ";
    ID = 0;
    Main_Uni = " ";
    Section_Stu = " ";
    Field = " ";
    Trend = " ";
    Entry_Year = 0;
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
}

void welcome()
{
    system("cls");
    int z;
    system("color 04");
    Sleep(500);
    cout << "\t%%      %%      ";
    cout << "\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
    cout << "\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
    cout << "\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
    cout << "\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
    cout << "\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
    Sleep(600);
    cout << "\n\n\t\t\t        $$$$$$$$  $$$$$        ";
    cout << "\n\t\t\t           $$     $   $      ";
    cout << "\n\t\t\t           $$     $$$$$    ";
    Sleep(700);
    system("color 02");
    cout << "\n\n\n\t\t  (********  STUDENTS MANAGEMENT SYSTEM  *******)";
    cout << "\n\n\t\t       BY:";
    cout << "\n\n\t\t\t  Ashkan Rahmani";
    cout << " \n\n\n\t\t     press any number and 'ENTER' to continue: ";
    system("color 07");
    cin >> z;
}

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}
//PersianStudent.ir

void Loading()
{
    gotoxy(20, 7);
    cout << "====================================";
    gotoxy(20, 13);
    cout << "====================================";
    gotoxy(32, 9);
    cout << "LOADING...";
    gotoxy(35, 11);
    Sleep(200);
    cout << "* ";
    Sleep(200);
    system("color 06");
    cout << "* ";
    Sleep(200);
    system("color 07");
    cout << "* ";
    gotoxy(53, 5);
    cout << ":) My ID <93422138>";
    gotoxy(41, 11);
    Sleep(200);
    system("color 08");
    cout << "* ";

    gotoxy(35, 11);
    Sleep(200);
    cout << "  ";
    Sleep(200);
    system("color 06");
    cout << "  ";
    Sleep(200);
    system("color 07");
    cout << "  ";
    Sleep(200);
    system("color 08");
    cout << "  ";

    gotoxy(35, 11);
    Sleep(200);
    cout << "* ";
    Sleep(200);
    system("color 06");
    cout << "* ";
    Sleep(200);
    system("color 07");
    cout << "* ";
    Sleep(200);
    system("color 08");
    cout << "* ";

    gotoxy(35, 11);
    Sleep(200);
    cout << "  ";
    Sleep(200);
    system("color 06");
    cout << "  ";
    Sleep(200);
    system("color 07");
    cout << "  ";
    Sleep(200);
    system("color 08");
    cout << "  ";

    gotoxy(35, 11);
    Sleep(200);
    cout << "* ";
    Sleep(200);
    system("color 06");
    cout << "* ";
    Sleep(200);
    system("color 07");
    cout << "* ";
    Sleep(200);
    system("color 08");
    cout << "* ";

    gotoxy(35, 11);
    Sleep(200);
    cout << "  ";
    Sleep(200);
    system("color 06");
    cout << "  ";
    Sleep(200);
    system("color 07");
    cout << "  ";
    Sleep(200);
    system("color 08");
    cout << "  ";

    gotoxy(35, 11);
    Sleep(200);
    cout << "* ";
    Sleep(200);
    system("color 06");
    cout << "* ";
    Sleep(200);
    system("color 08");
    cout << "* ";
    Sleep(200);
    system("color 07");
    cout << "* ";
}

bool Add_Student(Student_Info * student, int len, int c)
{
    if (c < len)
    {
        student[c].Set_Personal_Info();
        system("pause");
        system("cls");
        student[c].Set_Student_Info();
        student[c].Write_Student_Info();
        system("pause");
        system("cls");
        return true;
    }
    return false;
}
//PersianStudent.ir

void Add_Midterm(Student_Info * student, int c, int id)
{
    remove("Result_Info.txt");
    for (int i = 0; i < c; i++)
    {
        if (student[i].getID() == id)
        {
            system("cls");
            if (student[i].getSection() == "Kardani")
            {
                cout << "\n\tYour Student Section is:" << student[i].getSection() << endl;
                cout << "\t* You can Set Maximum 12 Midterms For this Student."
                    << "\n\t* These Midterms are Calculated For Maximum 4 Educated Years.";
                student[i].Set_Midterm();
                student[i].Write_Midterm_Info();
            }
            if (student[i].getSection() == "Karshenasi")
            {
                cout << "\n\tYour Student Section is:" << student[i].getSection() << endl;
                cout << "\t* You can Set Maximum 18 Midterms For this Student."
                    << "\n\t* These Midterms are Calculated For Maximum 6 Educated Years.";
                student[i].Set_Midterm();
                student[i].Write_Midterm_Info();
            }
            if (student[i].getSection() == "Arshad")
            {
                cout << "\n\tYour Student Section is:" << student[i].getSection() << endl;
                cout << "\t* You can Set Maximum 12 Midterms For this Student."
                    << "\n\t* These Midterms are Calculated For Maximum 4 Educated Years.";
                student[i].Set_Midterm();
                student[i].Write_Midterm_Info();
            }
        }
        student[i].Write_Result_Info();
    }
}

bool Show_Result_Allmids(Student_Info * student, int c, int id)
{
    for (int i = 0; i < c; i++)
    {
        if (student[i].getID() == id)
        {
            system("cls");
            student[i].Show_Student_Detail();
            return true;
        }
    }
    return false;
}

bool Delete_Student(Student_Info * student, int len, int id, int c)
{
    if (c > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (student[i].getID() == id)
            {
                student[i].setNULL();
                Student_Info * temp = NULL;
                *temp = student[i];
                student[i] = student[c - 1];
                student[c - 1] = *temp;
                return true;
            }
        }
    }
    return false;
}
//PersianStudent.ir

void Write_Info_File(Student_Info * student, int c)
{
    remove("Student_Info.txt");
    for (int i = 0; i <= c; i++)
    {
        student[i].Write_Student_Info();
    }
}

void Total_Student(Student_Info * student, int c, string mainuni, int year)
{
    int total_stu = 0;
    for (int i = 0; i < c; i++)
    {
        if (student[i].getMain_Uni() == mainuni && student[i].getEntry_year() == year)
        {
            total_stu++;
        }
    }
    cout << "\n\n\t\tTotal Students in " << mainuni << " University\n\n\t\tand Enter in year: " << year << " is: ";
    cout << "\n\n\t\t\t\t\t --> " << total_stu << "\n\n\n";
}

void Ranked1_Stu_Total_avg(Student_Info * student, int c, string mainuni, int year, string section, string trend, string field)
{
    bool CON = false;
    int MAX = 0;
    for (int i = 0; i < c; i++)
    {
        if (student[i].getEntry_year() == year && student[i].getMain_Uni() == mainuni && student[i].getSection() == section
            && student[i].getTrend() == trend && student[i].getField() == field)
        {
            CON = true;
            MAX = i;
            break;
        }
    }
    if (CON)
    {
        for (int i = 0; i < c; i++)
        {
            if (student[i].getEntry_year() == year && student[i].getMain_Uni() == mainuni && student[i].getSection() == section
                && student[i].getTrend() == trend && student[i].getField() == field)
            {
                if (student[i].getTotal_avg() > student[MAX].getTotal_avg())
                {
                    MAX = i;
                }
            }
        }
        cout << "\n\n\t\tThe RANKED 1 Student is:\n\t\t" << student[MAX].getFname() << "   " << student[MAX].getLname() << "\n\t\t"
            << "Total Average: " << student[MAX].getTotal_avg() << "\n\n\n";
    }
    else
    {
        cout << "\n\n\t\tThere isn't any Ranked 1 Student whith those specific Info\n\n\n";
    }
}

void Ranked1_Stu_Mid_avg(Student_Info * student, int c, string mainuni, int year, string section, string trend, string field, int mid, int y)
{
    bool CON = false;
    int MAX = 0;
    Educate_Year *temp_Year = NULL;
    Educate_Year *temp_Year1 = NULL;
    for (int i = 0; i < c; i++)
    {
        if (student[i].getEntry_year() == year && student[i].getMain_Uni() == mainuni && student[i].getSection() == section
            && student[i].getTrend() == trend && student[i].getField() == field)
        {
            CON = true;
            MAX = i;
            break;
        }
    }
    if (CON)
    {
        for (int i = 0; i < c; i++)
        {
            if (student[i].getEntry_year() == year && student[i].getMain_Uni() == mainuni && student[i].getSection() == section
                && student[i].getTrend() == trend && student[i].getField() == field)
            {
                *temp_Year = student[i].getEducate_Year();
                *temp_Year1 = student[MAX].getEducate_Year();
                if (temp_Year[y - 1].Term[mid].Term_Average > temp_Year1[y - 1].Term[mid].Term_Average)
                {
                    MAX = i;
                }
            }
        }
        cout << "\n\n\t\tThe RANKED 1 Student is:\n\t\t" << student[MAX].getFname() << "   " << student[MAX].getLname() << "\n\t\t"
            << "Average in " << mid + 1 << "th MidTerm: " << temp_Year1[y - 1].Term[mid].Term_Average << "\n\n\n";
    }
    else
    {
        cout << "\n\n\t\tThere isn't any Ranked 1 Student whith those specific Info\n\n\n";
    }

}

void Sort_Student(Student_Info * student, int c, string mainuni, int year, string section, string trend, string field)
{
    int stu_num = 0;
    int number = 0;
    Student_Info * temp_stu = new Student_Info[c];
    Student_Info *temp = NULL;
    bool CON = false;
    for (int i = 0; i < c; i++)
    {
        if (student[i].getEntry_year() == year && student[i].getMain_Uni() == mainuni && student[i].getSection() == section
            && student[i].getTrend() == trend && student[i].getField() == field)
        {
            temp_stu[number] = student[i];
            number++;
            stu_num++;
            CON = true;
        }
    }
    if (CON)
    {
        for (int i = 0; i < stu_num; i++)
        {
            for (int j = 0; j < (stu_num - i - 1); j++)
            {
                if (temp_stu[j].getTotal_avg() > temp_stu[j + 1].getTotal_avg())
                {
                    *temp = temp_stu[j];
                    temp_stu[j] = temp_stu[j + 1];
                    temp_stu[j + 1] = *temp;
                }
            }
        }
        cout << "\n\n\t ** Accending Sort Of Students with Specific Info By Total Average **\n\n";
        for (int i = 0; i < stu_num; i++)
        {
            temp_stu[i].Show_Student_Info();
            cout << "\n\t\tWith Total Average: " << temp_stu[i].getTotal_avg() << "\n-----------------------------------\n\n";
        }
        remove("Sorted_Students.txt");
        for (int i = 0; i < stu_num; i++)
        {
            temp_stu[i].Write_Specific_Info();
        }
    }
    else
    {
        cout << "\n\n\t\tThere isn't any Student whith those specific Info\n\n\n";
    }
} 