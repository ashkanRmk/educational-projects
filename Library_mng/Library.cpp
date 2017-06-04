#include<iostream>
#include<string>
#include<fstream>
#include <conio.h>
using namespace std;

struct Books_info
{
	int id;
	string name;
}Book_info[100];

struct Writers_info
{
	int id;
	string name;
	string family;
}Writer_info[100];

int Book_counter = 0;
int Writer_counter = 0;

void Add_Book()
{
	if (Book_counter < 100)
	{
		cout << "\nEnter Book ID: ";
		cin >> Book_info[Book_counter].id;
		cout << "\nEnter Book Name: ";
		cin >> Book_info[Book_counter].name;
		Book_counter++;
	}
	else
	{
		cout << "Maximum Number of Books is 100";
	}
}

void Add_Writer()
{
	if (Writer_counter < 100)
	{
		cout << "\nEnter Writer ID: ";
		cin >> Writer_info[Writer_counter].id;
		cout << "\nEnter Writer Name: ";
		cin >> Writer_info[Writer_counter].name;
		cout << "\nEnter Writer Family: ";
		cin >> Writer_info[Writer_counter].family;
		Writer_counter++;
	}
	else
	{
		cout << "Maximum Number of Writer is 100";
	}
}

void Delete_Book()
{
	cout << "\nEnter ID of Book you want to delete: ";
	int id;
	bool ch = false;
	cin >> id;
	for (int i = 0; i < Book_counter; i++)
	{
		if (Book_info[i].id == id)
		{
			for (int j = i; j < Book_counter; j++)
			{
				Book_info[j].id = Book_info[j + 1].id;
				Book_info[j].name = Book_info[j + 1].name;
			}
			Book_counter--;
			ch = true;
		}
	}
	if (!ch)
	{
		cout << "\n\n\t\tBook not Found!";
		_getch();
	}
}

void Delete_Writer()
{
	cout << "\nEnter ID of Writer you want to delete: ";
	int id;
	bool ch = false;
	cin >> id;
	for (int i = 0; i < Writer_counter; i++)
	{
		if (Writer_info[i].id == id)
		{
			for (int j = i; j < Writer_counter; j++)
			{
				Writer_info[j].id = Writer_info[j + 1].id;
				Writer_info[j].name = Writer_info[j + 1].name;
				Writer_info[j].family = Writer_info[j + 1].family;
			}
			Writer_counter--;
			ch = true;
		}
	}
	if (!ch)
	{
		cout << "\n\n\t\tWriter not Found!";
		_getch();
	}
}

void Update_Book_info()
{
	cout << "\nEnter ID of Book you want to UPDATE: ";
	int id;
	bool ch = false;
	cin >> id;
	for (int i = 0; i < Book_counter; i++)
	{
		if (Book_info[i].id == id)
		{
			cout << "\nEnter NEW Book ID: ";
			cin >> Book_info[i].id;
			cout << "\nEnter NEW Book Name: ";
			cin >> Book_info[i].name;
			ch = true;
		}
	}
	if (!ch)
	{
		cout << "\n\n\t\tBook not Found!";
		_getch();
	}
}

void Update_Writer_info()
{
	cout << "\nEnter ID of Writer you want to UPDATE: ";
	int id;
	bool ch = false;
	cin >> id;
	for (int i = 0; i < Writer_counter; i++)
	{
		if (Writer_info[i].id == id)
		{
			cout << "\nEnter NEW Writer ID: ";
			cin >> Writer_info[i].id;
			cout << "\nEnter NEW Writer Name: ";
			cin >> Writer_info[i].name;
			cout << "\nEnter NEW Writer Family: ";
			cin >> Writer_info[i].family;
			ch = true;
		}
	}
	if (!ch)
	{
		cout << "\n\n\t\tWriter not Found!";
		_getch();
	}
}

void Find_Book_ID()
{
	cout << "\nEnter ID of Book you want to FIND: ";
	int id;
	bool ch = false;
	cin >> id;
	for (int i = 0; i < Book_counter; i++)
	{
		if (Book_info[i].id == id)
		{
			cout << Book_info[i].id <<endl;
			cout << Book_info[i].name;
			_getch();
			ch = true;
		}
	}
	if (!ch)
	{
		cout << "\n\n\t\tBook not Found!";
		_getch();
	}

}

void Find_Book_NAME()
{
	cout << "\nEnter name of Book you want to FIND: ";
	string name;
	bool ch = false;
	cin >> name;
	for (int i = 0; i < Book_counter; i++)
	{
		if (Book_info[i].name == name)
		{
			cout << Book_info[i].id << endl;
			cout << Book_info[i].name;
			_getch();
			ch = true;
		}
	}
	if (!ch)
	{
		cout << "\n\n\t\tBook not Found!";
		_getch();
	}

}

void Find_Writer_NAME()
{
	cout << "\nEnter name of Writer you want to FIND: ";
	string name;
	bool ch = false;
	cin >> name;
	for (int i = 0; i < Writer_counter; i++)
	{
		if (Writer_info[i].name == name)
		{
			cout << Writer_info[i].id << endl;
			cout << Writer_info[i].name << endl;
			cout << Writer_info[i].family;
			_getch();
			ch = true;
		}
	}
	if (!ch)
	{
		cout << "\n\n\t\tBook not Found!";
		_getch();
	}

}

void Find_Writer_ID()
{
	cout << "\nEnter ID of Writer you want to FIND: ";
	int id;
	bool ch = false;
	cin >> id;
	for (int i = 0; i < Writer_counter; i++)
	{
		if (Writer_info[i].id == id)
		{
			cout << Writer_info[i].id << endl;
			cout << Writer_info[i].name << endl;
			cout << Writer_info[i].family;
			_getch();
			ch = true;
		}
	}
	if (!ch)
	{
		cout << "\n\n\t\tBook not Found!";
		_getch();
	}

}


void Print_Books()
{
	for (int i = 0; i < Book_counter; i++)
	{
		cout << Book_info[i].id << "   " << Book_info[i].name << endl;
	}
	_getch();
}

void Print_Writer()
{
	for (int i = 0; i < Writer_counter; i++)
	{
		cout << Writer_info[i].id << "   " << Writer_info[i].name << "  " << Writer_info[i].family <<endl;
	}
	_getch();
}

void Save_Book_info()
{
	fstream output;
	output.open("Books_info.txt", ios::out);
	if (!output)
	{
		cerr << "File can not open." << endl;
		exit(1);
	}
	for (int i = 0; i < Book_counter; i++)
	{
		output << Book_info[i].id << "   " << Book_info[i].name << endl;
	}
	cout << "\n\tBooks Info Saved!";
	_getch();
}

void Save_Writer_info()
{
	fstream output;
	output.open("Writers_info.txt", ios::out);
	if (!output)
	{
		cerr << "File can not open." << endl;
		exit(1);
	}
	for (int i = 0; i < Writer_counter; i++)
	{
		output << Writer_info[i].id << "   " << Writer_info[i].name << "  " << Writer_info[i].family << endl;
	}
	cout << "\n\tWriterss Info Saved!";
	_getch();
}

int main()
{
	ifstream inputFile("info_list.txt", ios::in | ios::beg);
	if (!inputFile)	
	{
		cerr << "some thing wrong during opening file!" << endl;
		_getche();
		exit(1);
	}

	while (!inputFile.eof())
	{
		inputFile >> Book_info[Book_counter].id >> Book_info[Book_counter].name >>
			Writer_info[Writer_counter].name >> Writer_info[Writer_counter].family >> Writer_info[Writer_counter].id;
		Writer_counter++;
		Book_counter++;
	}

	while (true)
	{
		cout << "\n\t\t*******  MAIN MENU  ********\n\n";
		cout << "\tEnter the Following Number for each action:\n\n";
		cout << "\t1) Add New Book \n"
			<< "\t2) Add New Writer\n"
			<< "\t3) Delete Book using ID\n"
			<< "\t4) Delete Writer using ID\n"
			<< "\t5) Update Book info\n"
			<< "\t6) Update Writer info\n"
			<< "\t7) Find Book by ID\n"
			<< "\t8) Find Book by Name\n"
			<< "\t9) Find Writer by ID\n"
			<< "\t10) Find Writer by Name\n"
			<< "\t11) Print Books Info\n"
			<< "\t12) Print Writers Info\n"
			<< "\t13) Save Books Info in File\n"
			<< "\t14) Save Writers Info in File\n"
			<< "\t15) Exit\n";
		cout << "\n\t-> ";
		int x;
		cin >> x;

		switch (x)
		{
		case 1:
			system("cls");
			Add_Book();
			system("cls");
			break;
		case 2:
			system("cls");
			Add_Writer();
			system("cls");
			break;
		case 3:
			system("cls");
			Delete_Book();
			system("cls");
			break;
		case 4:
			system("cls");
			Delete_Writer();
			system("cls");
			break;
		case 5:
			system("cls");
			Update_Book_info();
			system("cls");
			break;
		case 6:
			system("cls");
			Update_Writer_info();
			system("cls");
			break;
		case 7:
			system("cls");
			Find_Book_ID();
			system("cls");
			break;
		case 8:
			system("cls");
			Find_Book_NAME();
			system("cls");
			break;
		case 9:
			system("cls");
			Find_Writer_ID();
			system("cls");
			break;
		case 10:
			system("cls");
			Find_Writer_NAME();
			system("cls");
			break;
		case 11:
			system("cls");
			Print_Books();
			system("cls");
			break;
		case 12:
			system("cls");
			Print_Writer();
			system("cls");
			break;
		case 13:
			system("cls");
			Save_Book_info();
			system("cls");
			break;
		case 14:
			system("cls");
			Save_Writer_info();
			system("cls");
			break;
		case 15:
			exit(1);
			break;
		}
	}
	return 0;
}
