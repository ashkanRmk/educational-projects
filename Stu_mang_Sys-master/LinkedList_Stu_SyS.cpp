#include <iostream>
#include <string>
using namespace std;

//node class
class node
{
	string name;
	string family;
	int id;
	float avg;
	bool sex;	//true = male   false = female
	string birth_place;
	int birth_date;

	node *next;

	friend class linkedlist;
};

//linked list class
class linkedlist
{
public:
	linkedlist(){ first = NULL;  }

	void addelement();//add node to list
	void deleteelement(int);//delet node by value of data
	void showlist();//print all node in list
	void edit_data(int);//search the linked list by value of data
	void Sort_family();
	void Sort_id();
	void Sort_birth_date();
	void Sort_avg();
	void search_family(string);
	void search_fail();
	void search_birth_place(string);
private:
	node *first;//stor first node of link
	node *last;//stor last node of link
};

//add node to list and fill node
void linkedlist::addelement()
{
	string name;
	string family;
	int id;
	float avg;
	bool sex;	//true = male   false = female
	string birth_place;
	int birth_date;

	if (first == NULL)
	{
		//create first node
		node *temp = new node;

		cout << "\nEnter student Name:\n";
		cin >> name;
		temp->name = name;
		cout << "\nEnter student family:\n";
		cin >> family;
		temp->family = family;
		cout << "\nEnter student id:\n";
		cin >> id;
		temp->id = id;
		cout << "\nEnter student birth Place:\n";
		cin >> birth_place;
		temp->birth_place = birth_place;
		cout << "\nEnter student birth Date:\n";
		cin >> birth_date;
		temp->birth_date = birth_date;
		cout << "\nWhat is Student Gender (enter num) : \n1) Male\n2)Female\n";
		int tmp;
		cin >> tmp;
		if (tmp == 1)
			temp->sex = true;
		else
		{
			temp->sex = false;
		}
		cout << "\nEnter student AVERAGE:\n";
		cin >> avg;
		temp->avg = avg;

		temp->next = NULL;
		first = temp;
		last = first;
	}
	else
	{
		//create other node
		node *temp = new node;

		cout << "\nEnter student Name:\n";
		cin >> name;
		temp->name = name;
		cout << "\nEnter student family:\n";
		cin >> family;
		temp->family = family;
		cout << "\nEnter student id:\n";
		cin >> id;
		temp->id = id;
		cout << "\nEnter student birth Place:\n";
		cin >> birth_place;
		temp->birth_place = birth_place;
		cout << "\nEnter student birth Date:\n";
		cin >> birth_date;
		temp->birth_date = birth_date;
		cout << "\nWhat is Student Gender (enter num) : \n1) Male\n2)Female\n";
		int tmp;
		cin >> tmp;
		if (tmp == 1)
			temp->sex = true;
		else
		{
			temp->sex = false;
		}
		cout << "\nEnter student AVERAGE:\n";
		cin >> avg;
		temp->avg = avg;

		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

//delete node
void linkedlist::deleteelement(int data1)
{
	node* temp;
	node* temp1;
	temp1 = temp = first;
	int not_exit_in_list = 0;
	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}
	if (first->id == data1)
	{
		temp = first;
		first = first->next;
		cout << "Your Student With ID= " << data1 << " DELETED!" << endl;
		delete temp;
	}
	else
	{
		while (temp != last)
		{
			temp = temp1->next;
			if (temp->id == data1)
			{
				if (temp == last)
				{
					temp1->next = NULL;
					cout << "Your Student With ID= " << data1 << " DELETED!" << endl;
					delete temp;
					last = temp1;
					not_exit_in_list = 1;
					break;
				}
				else
				{
					temp1->next = temp->next;
					cout << "Your Student With ID= " << data1 << " DELETED!" << endl;
					delete temp;
					not_exit_in_list = 1;
					break;
				}
			}
			temp1 = temp1->next;
		}
		if (not_exit_in_list == 0)
		{
			cout << "Your Student With ID= " << data1 << " NOT Found!" << endl;
		}
	}
}

//show node of linked list
void linkedlist::showlist()
{
	if (first == NULL)
	{
		cout << "list empty" << endl;
	}
	else
	{
		node *temp;
		temp = first;
		while (temp)
		{
			cout << temp->name << " " << temp->family << " " << temp->id << " " << temp->birth_place << " " << temp->birth_date << " " << temp->avg << " ";
			if (temp->sex)
				cout << "Male" << endl;
			else
			{
				cout << "Female" << endl;
			}
			temp = temp->next;
		}
	}
}

//Sort Functions
void linkedlist::Sort_family()
{

	node* cur = first;
	node* forward = cur->next;

	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}

	while (cur)
	{
		while (forward)
		{
			if (cur->family.compare(forward->family) > 0)
			{
				node temp = *cur;

				cur->family = forward->family;
				cur->name = forward->name;
				cur->id = forward->id;
				cur->avg = forward->avg;
				cur->sex = forward->sex;
				cur->birth_date = forward->birth_date;
				cur->birth_place = forward->birth_place;

				forward->family = temp.family;
				forward->name = temp.name;
				forward->id = temp.id;
				forward->avg = temp.avg;
				forward->sex = temp.sex;
				forward->birth_date = temp.birth_date;
				forward->birth_place = temp.birth_place;
			}
			forward = forward->next;
		}
		cur = cur->next;
	}
}
void linkedlist::Sort_id()
{

	node* cur = first;
	node* forward = cur->next;

	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}

	while (cur)
	{
		while (forward)
		{
			if (cur->id > forward->id)
			{
				node temp = *cur;

				cur->family = forward->family;
				cur->name = forward->name;
				cur->id = forward->id;
				cur->avg = forward->avg;
				cur->sex = forward->sex;
				cur->birth_date = forward->birth_date;
				cur->birth_place = forward->birth_place;

				forward->family = temp.family;
				forward->name = temp.name;
				forward->id = temp.id;
				forward->avg = temp.avg;
				forward->sex = temp.sex;
				forward->birth_date = temp.birth_date;
				forward->birth_place = temp.birth_place;
			}
			forward = forward->next;
		}
		cur = cur->next;
	}
}
void linkedlist::Sort_birth_date()
{

	node* cur = first;
	node* forward = cur->next;

	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}

	while (cur)
	{
		while (forward)
		{
			if (cur->birth_date > forward->birth_date)
			{
				node temp = *cur;

				cur->family = forward->family;
				cur->name = forward->name;
				cur->id = forward->id;
				cur->avg = forward->avg;
				cur->sex = forward->sex;
				cur->birth_date = forward->birth_date;
				cur->birth_place = forward->birth_place;

				forward->family = temp.family;
				forward->name = temp.name;
				forward->id = temp.id;
				forward->avg = temp.avg;
				forward->sex = temp.sex;
				forward->birth_date = temp.birth_date;
				forward->birth_place = temp.birth_place;
			}
			forward = forward->next;
		}
		cur = cur->next;
	}
}
void linkedlist::Sort_avg()
{

	node* cur = first;
	node* forward = cur->next;

	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}

	while (cur)
	{
		while (forward)
		{
			if (cur->avg > forward->avg)
			{
				node temp = *cur;

				cur->family = forward->family;
				cur->name = forward->name;
				cur->id = forward->id;
				cur->avg = forward->avg;
				cur->sex = forward->sex;
				cur->birth_date = forward->birth_date;
				cur->birth_place = forward->birth_place;

				forward->family = temp.family;
				forward->name = temp.name;
				forward->id = temp.id;
				forward->avg = temp.avg;
				forward->sex = temp.sex;
				forward->birth_date = temp.birth_date;
				forward->birth_place = temp.birth_place;
			}
			forward = forward->next;
		}
		cur = cur->next;
	}
}

//Edit node
void linkedlist::edit_data(int id1)
{
	node *temp = first;
	bool ch = false;

	string name;
	string family;
	int id;
	float avg;
	bool sex;	//true = male   false = female
	string birth_place;
	int birth_date;

	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}

	while (temp)
	{
		if (temp->id == id1)
		{
			cout << "\nEnter new items:\n\n\n";

			cout << "\nEnter student Name:\n";
			cin >> name;
			temp->name = name;
			cout << "\nEnter student family:\n";
			cin >> family;
			temp->family = family;
			cout << "\nEnter student id:\n";
			cin >> id;
			temp->id = id;
			cout << "\nEnter student birth Place:\n";
			cin >> birth_place;
			temp->birth_place = birth_place;
			cout << "\nEnter student birth Date:\n";
			cin >> birth_date;
			temp->birth_date = birth_date;
			cout << "\nWhat is Student Gender (enter num) : \n1) Male\n2)Female\n";
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				temp->sex = true;
			else
			{
				temp->sex = false;
			}
			cout << "\nEnter student AVERAGE:\n";
			cin >> avg;
			temp->avg = avg;

			ch = true;
		}
		temp = temp->next;
	}
	if (!ch)
	{
		cout << "\nYour student NOT found!\n";
	}
}

//Search Functions
void linkedlist::search_family(string family)
{
	node *temp = first;
	bool ch = false;

	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}

	while (temp)
	{
		if (temp->family.compare(family) == 0)
		{
			cout << temp->name << " " << temp->family << " " << temp->id << " " << temp->birth_place << " " << temp->birth_date << " ";
			if (temp->sex)
				cout << "Male" << endl;
			else
			{
				cout << "Female" << endl;
			}
			ch = true;
		}
		temp = temp->next;
	}
	if (!ch)
	{
		cout << "\nYour student NOT found!\n";
	}
}
void linkedlist::search_birth_place(string place)
{
	node *temp = first;
	bool ch = false;

	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}

	while (temp)
	{
		if (temp->birth_place.compare(place) == 0)
		{
			cout << temp->name << " " << temp->family << " " << temp->id << " " << temp->birth_place << " " << temp->birth_date << " ";
			if (temp->sex)
				cout << "Male" << endl;
			else
			{
				cout << "Female" << endl;
			}
			ch = true;
		}
		temp = temp->next;
	}
	if (!ch)
	{
		cout << "\nYour student NOT found!\n";
	}
}
void linkedlist::search_fail()
{
	node *temp = first;
	int count = 0;

	if (!first)
	{
		cout << "List is Empty\n";
		return;
	}

	while (temp)
	{
		if (temp->avg < 12)
		{
			cout << temp->name << " " << temp->family << " " << temp->id << " " << temp->birth_place << " " << temp->birth_date << " ";
			if (temp->sex)
				cout << "Male" << endl;
			else
			{
				cout << "Female" << endl;
			}
			count++;
		}
		temp = temp->next;
	}
	cout << "\n Number of FAIL Students: " << count << endl;
}

int main()
{
	linkedlist Stu_List;

	int tmp;
	string tmp1;

	while (true)
	{
		cout << "\n\n\t\t*******  MAIN MENU  **********\n\n\n";
		cout << "\tEnter the Following Number for each action:\n\n";
		cout << "\t1) Add New Student\n"
			<< "\t2) Delete Student using ID\n"
			<< "\t3) Show All Students\n"
			<< "\t4) Edit Student using ID\n"
			<< "\t5) Sort Students by ID\n"
			<< "\t6) Sort Students by FAMILY\n"
			<< "\t7) Sort Students by AVERAGE\n"
			<< "\t8) Sort Students by BIRTH DATE\n"
			<< "\t9) Show FAIL Students\n"
			<< "\t10) Search Student by FAMILY\n"
			<< "\t11) Search Student by BIRTH PLACE\n"
			<< "\t12) Exit\n";
		int x;
		cout << "\n\t-> ";
		cin >> x;
		switch (x)
		{
		case 1:
			system("cls");
			Stu_List.addelement();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Enter ID of Student to Delete:" << endl;
			cin >> tmp;
			Stu_List.deleteelement(tmp);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			Stu_List.showlist();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Enter ID of Student to EDIT:" << endl;
			cin >> tmp;
			Stu_List.edit_data(tmp);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			Stu_List.Sort_id();
			Stu_List.showlist();
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			Stu_List.Sort_family();
			Stu_List.showlist();
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			Stu_List.Sort_avg();
			Stu_List.showlist();
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			Stu_List.Sort_birth_date();
			Stu_List.showlist();
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			Stu_List.search_fail();
			system("pause");
			system("cls");
			break;
		case 10:
			system("cls");
			cout << "Enter Family of Student to SHOW:" << endl;
			cin >> tmp1;
			Stu_List.search_family(tmp1);
			system("pause");
			system("cls");
			break;
		case 11:
			system("cls");
			cout << "Enter BIRTH PLACE of Student to SHOW:" << endl;
			cin >> tmp1;
			Stu_List.search_birth_place(tmp1);
			system("pause");
			system("cls");
			break;
		default:
			exit(1);
			break;
		}
	}
	return 0;
}