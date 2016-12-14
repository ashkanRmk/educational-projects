//Source.cpp
//Store Managment System v 1.0
//Advanced Programming (Midterm_Project)
//PersianStudent.ir
//Coded by: Ashkan.rmk

#include"Store.h"

int main()
{
    welcome();
    system("cls");
    Store Shop1;
    string nam;
    cout << "\n\n\n\t\t*Please Enter your Branch Name:";
    cin >> nam;
    Shop1.setBranchName(nam);
    cout << "\n\t*Your Current Budget is:" << Shop1.getCurrentBudget() << endl << endl;
    system("pause");
    system("cls");
    while (true)
    {
        //PersianStudent.ir
        cout << "\n\n\t\t*******  MAIN MENU  **********\n\n\n";
        cout << "\tEnter the Following Number for each action:\n\n";
        cout << "\t1) Add Item to the Store\n"
            << "\t2) Sale Item using CODE\n"
            << "\t3) Enter Or Change the Branch Name\n"
            << "\t4) Show number of Item Exist and Purchase\n"
            << "\t5) Calculate the Profit of Store\n"
            << "\t6) Calculate the Current Budget\n"
            << "\t7) Exit" << endl;
        int a;
        cout << "\n\t-> ";
        cin >> a;
        switch (a)
        {
        case 1:
            system("cls");
            if (Shop1.addItemExist()) {
                cout << "Your Item has been added!" << endl;
            }
            else {
                cout << "Error has been occured!" << endl;
            }
            cout << "\n\t*Your Current Budget is:" << Shop1.getCurrentBudget() << endl << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            int c;
            cout << "\nPlease Enter the Sold Item CODE:" << endl;
            cout << " --> ";
            cin >> c;
            if (Shop1.addItemPurchase(c))
            {
                cout << "\nYour Item with code :" << c << " has been sold!" << endl;
                cout << "\n\t*Your Current Budget is:" << Shop1.getCurrentBudget() << endl << endl;
            }
            else
            {
                cout << "\nThis item:" << c << "is NOT in you Exist List!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "\n\n\tYour Current Branch name is:" << Shop1.getBranchName() << endl
                << "\n\n\t*Please Enter your New Branch Name: ";
            cin >> nam;
            Shop1.setBranchName(nam);
            cout << "\n\n\t**Your Branch Name has been changed to:" << nam << endl << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            //PersianStudent.ir
            cout << "\n\n\n\t\tNumber OF Item Exist:" << Shop1.getItemExist() << endl << endl
                << "\t\tNumber OF Item Purchased:" << Shop1.getItemPurchase() << endl << endl;
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "\n\n\t\tYour Profit of Store is:" << Shop1.getProfit() << endl << endl;
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << "\n\n\t\tYour Current Budget is:" << Shop1.getCurrentBudget() << endl << endl;
            system("pause");
            system("cls");
            break;
        default:
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\n\t\t\t\t*** SEE YOU SOON ***\n" << endl
                << "\t\t\t\t      GOOD BYE\n\n\n\n" << endl << endl << endl;
            system("pause");
            exit(1);
            break;
        }
    }
    //PersianStudent.ir
    return 0;
} 