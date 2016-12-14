//Store.h
//Store Managment System v 1.0
//Advanced Programming (Midterm_Project)
//PersianStudent.ir

#include<iostream>
#include<string>

using namespace std;

struct Item
{
    string itemName;
    int codeItem;
    double Price;
};

struct Node
{
    Node *Next;
    Item Data;
    Node()
    {
        Next = NULL;
    }
    Node(Item x)
    {
        Data = x;
        Next = NULL;
    }
};
//PersianStudent.ir

class Store
{
private:
    int itemExist;
    string branchName;
    int itemPurchase;
    double currentBudget;
    double Profit;
    Node *first_Item;
    Node *first_Purchase;
public:
    Store()
    {
        first_Item = NULL;
        first_Purchase = NULL;
        currentBudget = 5000;
        Profit = 0;
    }
    bool addItemExist();
    bool addItemPurchase(int);
    Item getItemData();
    void setBranchName(string temp)
    {
        branchName = temp;
    }
    string getBranchName()
    {
        return branchName;
    }
    int getItemPurchase()
    {
        return itemPurchase;
    }
    int getItemExist()
    {
        return itemExist;
    }
    double getCurrentBudget()
    {
        return currentBudget;
    }
    double getProfit()
    {
        return Profit;
    }
};
//PersianStudent.ir
void welcome(); 