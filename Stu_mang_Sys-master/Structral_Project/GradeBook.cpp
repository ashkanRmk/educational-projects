//GradeBook.cpp
//Student Managment System V 1.0
//Advanced Programming (Midterm_Project)

#include"GradeBook.h"

bool list::addStuInfo()
{
    student x;
    cout << "\n\t\tEnter Student First Name:";
    cin >> x.firstName;
    cout << "\n\t\tEnter Student Last Name:";
    cin >> x.lastName;
    cout << "\n\t\tEnter Student ID:";
    cin >> x.ID;
    cout << "\n\t\tEnter Student Course Number:";
    cin >> x.courseNumber;
    cout << "\n\t\t**************************\n";
    for (int i = 0; i < x.courseNumber; i++)
    {
        cout << "\t\tEnter the Name of Course:";
        cin >> x.lesson[i].nameOfCourse;
        cout << "\n\t\tEnter the Unit of Course:";
        cin >> x.lesson[i].unit;
        cout << "\n\t\tEnter the Score of Course:";
        cin >> x.lesson[i].score;
        cout << "\n\t\t**************************\n";
    }
    //PersianStudent.ir
    x.average = 0;
    Node *temp = new Node(x);
    if (!temp)
        return false;
    if (!first)
    {
        first = temp;
        return true;
    }
    temp->Next = first;
    first = temp;
    return true;
}

bool list::makeFile()
{
    Node *temp = first;
    fstream StuInfo;
    StuInfo.open("Student.txt", ios::app);        //open last file and write continue...
    if (!StuInfo)
        return false;
    StuInfo << temp->Data.firstName << "       " << temp->Data.lastName
        << "    " << temp->Data.ID << "     " << temp->Data.average << "\n";
    StuInfo.close();
    return true;
}

//PersianStudent.ir
bool list::makeFile1()
{
    Node *temp = first;
    ofstream StuInfo("Student.txt", ios::out);        //make new file and save data
    if (!StuInfo)
        return false;
    StuInfo << "     ***** STUDENT INFO *****\n\n" << "First Name" << "  "
        << "Last Name" << "  " << " ID" << "     " << "Average" << endl;
    StuInfo << temp->Data.firstName << "       " << temp->Data.lastName
        << "    " << temp->Data.ID << "     " << temp->Data.average << "\n";
    StuInfo.close();
    return true;
}

bool list::deleteStuInfo(int code)
{
    if (!first)                                        //if there isn't any NODE
        return false;
    if (!first->Next)
    {
        if (first->Data.ID == code)                    //if there is just ONE Node and same CODE
        {
            delete first;
            first = NULL;
            ofstream StuInfo("Student.txt", ios::out);        //make new file and save data
            if (!StuInfo)
                return false;
            StuInfo << "     ***** STUDENT INFO *****\n\n" << "First Name" << "  "
                << "Last Name" << "  " << " ID" << "     " << "Average" << endl;
            StuInfo.close();
            return true;
        }
        return false;                                //if there isn't Node with entered CODE
    }
    Node *cur = first;
    while (cur->Next)
    {
        if (cur->Data.ID == code)                    //if Node is in the middle of list
        {
            Node *save = cur;
            Node *temp = save->Next;
            cur = temp;
            delete save;
            Node *head = first;
            ofstream StuInfo("Student.txt", ios::out);        //make new file and save data
            if (!StuInfo)
                return false;
            //PersianStudent.ir
            StuInfo << "     ***** STUDENT INFO *****\n\n" << "First Name" << "  "
                << "Last Name" << "  " << " ID" << "     " << "Average" << endl;
            while (head)
            {
                StuInfo << head->Data.firstName << "       " << head->Data.lastName
                    << "    " << head->Data.ID << "     " << head->Data.average << "\n";
                head = head->Next;
            }
            StuInfo.close();
            return true;
        }
        cur = cur->Next;
    }
    while (cur->Next->Next)
    {
        if (cur->Next->Data.ID == code)                //if Node is the last one
        {
            Node *temp = cur->Next;
            cur->Next = NULL;
            delete temp;
            Node *head = first;
            ofstream StuInfo("Student.txt", ios::out);        //make new file and save data
            if (!StuInfo)
                return false;
            StuInfo << "     ***** STUDENT INFO *****\n\n" << "First Name" << "  "
                << "Last Name" << "  " << " ID" << "     " << "Average" << endl;
            while (head)
            {
                StuInfo << head->Data.firstName << "       " << head->Data.lastName
                    << "    " << head->Data.ID << "     " << head->Data.average << "\n";
                head = head->Next;
            }
            StuInfo.close();
            return true;
        }
        cur = cur->Next;
    }
    return false;                                    //if there isn't Node with entered CODE
}

bool list::calStuAverage(int code)
{
    Node *temp = first;
    int totalUnit = 0;
    float total = 0;
    while (temp)
    {
        if (temp->Data.ID == code)
        {
            for (int i = 0; i < temp->Data.courseNumber; i++)
            {
                total += temp->Data.lesson[i].score * temp->Data.lesson[i].unit;
                totalUnit += temp->Data.lesson[i].unit;
            }
            temp->Data.average = total / totalUnit;
            cout << "\n\t\tYour Student AVERAGE with ID " << code << " is:  "
                << temp->Data.average;
            Node *cur = first;
            ofstream StuInfo("Student.txt", ios::out);        //make new file and save data
            if (!StuInfo)
                return false;
            //PersianStudent.ir
            StuInfo << "     ***** STUDENT INFO *****\n\n" << "First Name" << "  "
                << "Last Name" << "  " << " ID" << "     " << "Average" << endl;
            while (cur)
            {
                StuInfo << cur->Data.firstName << "       " << cur->Data.lastName
                    << "    " << cur->Data.ID << "     " << cur->Data.average << "\n";
                cur = cur->Next;
            }
            StuInfo.close();
            return true;
        }
        temp = temp->Next;
    }
    return false;
}

bool list::findStu(int code)
{
    Node *temp = first;
    while (temp)
    {
        if (temp->Data.ID == code)
        {
            cout << "\n\t\t****** STUDENT INFO *******\n";
            cout << "\n\t\t" << temp->Data.firstName << " " << temp->Data.lastName
                << "\n\t\tID: " << temp->Data.ID << "\n\t\tAverage: " << temp->Data.average
                << "\n\n\t\t\t*  " << temp->Data.courseNumber << "  COURSES  *\n";
            for (int i = 0; i < temp->Data.courseNumber; i++)
            {
                cout << "\t\tCourse Name: " << temp->Data.lesson[i].nameOfCourse
                    << "\n\t\t Unit: " << temp->Data.lesson[i].unit
                    << "\n\t\t Score: " << temp->Data.lesson[i].score << endl << endl;
            }
            return true;
        }
        temp = temp->Next;
    }
    return false;
}

bool list::showStuInfo_FILE()
{
    fstream StuInfo;
    StuInfo.open("Student.txt", ios::in);
    if (!StuInfo)
        return false;
    char c;
    StuInfo.seekg(0, ios::beg);
    while (!StuInfo.eof())
    {
        StuInfo.get(c);
        if (!StuInfo.eof())
            cout << c;
    }
    StuInfo.clear();
    cout << endl;
    return true;
}

//PersianStudent.ir
bool list::showStuInfo_LinkedList()
{
    if (!first)
        return false;
    Node *temp = first;
    cout << "\n\t\t****** STUDENT INFO *******\n";
    while (temp)
    {
        cout << "\n\t\t" << temp->Data.firstName << " " << temp->Data.lastName
            << "\n\t\tID: " << temp->Data.ID << "\n\t\tAverage: " << temp->Data.average << endl << endl;
        temp = temp->Next;
    }
    return true;
}

void welcome()
{
    system("cls");
    int z;
    cout << "\t%%      %%      ";
    cout << "\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
    cout << "\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
    cout << "\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
    cout << "\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
    cout << "\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
    cout << "\n\n\t\t\t        $$$$$$$$  $$$$$        ";
    cout << "\n\t\t\t           $$     $   $      ";
    cout << "\n\t\t\t           $$     $$$$$    ";

    cout << "\n\n\n\t\t  (********  STUDENTS MANAGEMENT SYSTEM  *******)";
    cout << "\n\n\t\t       BY:";
    cout << "\n\n\t\t\t  Ashkan.rmk";
    cout << " \n\n\n\t\t     press any number and 'ENTER' to continue: ";
    cin >> z;
} 
