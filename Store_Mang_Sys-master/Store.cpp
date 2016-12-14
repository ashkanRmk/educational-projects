//Store.cpp
//Store Managment System v 1.0
//Advanced Programming (Midterm_Project)
//PersianStudent.ir

#include"Store.h"

Item Store::getItemData()
{
    Item s;
    cout << "\n\tEnter Your Item NAME:";
    cin >> s.itemName;
    cout << "\n\tEnter Your Item CODE:";
    cin >> s.codeItem;
    cout << "\n\tEnter Your Item PRICE:";
    cin >> s.Price;
    cout << "------------------------\n";
    return s;
}

bool Store::addItemExist()
{
    Item x = getItemData();
    Node *temp = new Node(x);
    if (!temp)
        return false;
    temp->Next = first_Item;
    first_Item = temp;
    itemExist++;
    currentBudget -= x.Price;
    return true;
}

//PersianStudent.ir
bool Store::addItemPurchase(int c)
{
    Node *temp = first_Item;
    if (!temp)
        return false;
    if (temp->Data.codeItem == c)
    {
        currentBudget += (temp->Data.Price + (temp->Data.Price * 0.2));
        Profit += (temp->Data.Price* 0.2);
        first_Item = temp->Next;
        temp->Next = first_Purchase;
        first_Purchase = temp;
        itemExist--;
        itemPurchase++;
        return true;
    }
    //PersianStudent.ir
    while (temp)
    {
        if (temp->Next->Data.codeItem == c)
        {
            currentBudget += (temp->Next->Data.Price + (temp->Next->Data.Price * 0.2));
            Profit += (temp->Next->Data.Price* 0.2);
            Node *save = temp->Next;
            temp->Next = temp->Next->Next;
            save->Next = first_Purchase;
            first_Purchase = save;
            itemExist--;
            itemPurchase++;
            return true;
        }
        temp = temp->Next;
    }
    return false;
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

    cout << "\n\n\n\t\t  (********  STORE MANAGEMENT SYSTEM  *******)";
    cout << "\n\n\t\t       BY:";
    cout << "\n\n\t\t\t  Ashkan.rmk";
    cout << " \n\n\n\t\t     press any number and 'ENTER' to continue: ";
    cin >> z;
} 