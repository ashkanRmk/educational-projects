#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
using namespace std;

struct Node {
	string value;
	int count;
	Node *left;
	Node *right;

	Node(string val) {
		value = val;
		left = NULL;
		right = NULL;
		count = 1;
	}

	Node(string val, int counts) {
		value = val;
		left = NULL;
		right = NULL;
		count = counts;
	}
};

vector<string> name_list;
vector<int> count_list;
void menu();

class BST
{
private:

	Node *root;

	void addHelper(Node *root, string val) {
		transform(val.begin(), val.end(), val.begin(), ::tolower);
		if (root->value.compare(val) >= 0) {
			if (!root->left) {
				root->left = new Node(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	void add_by_counthelper(Node *root, int con, string val) {
		if (root->count < con) {
			if (!root->left) {
				root->left = new Node(val, con);
			}
			else {
				add_by_counthelper(root->left, con, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node(val, con);
			}
			else {
				add_by_counthelper(root->right, con, val);
			}
		}
	}

	void add_asFile_helper(Node *root, int con, string val) {
		if (root->value.compare(val) >= 0) {
			if (!root->left) {
				root->left = new Node(val, con);
			}
			else {
				add_asFile_helper(root->left, con, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node(val, con);
			}
			else {
				add_asFile_helper(root->right, con, val);
			}
		}
	}

	void printHelper(Node *root) {
		if (!root) return;
		printHelper(root->left);
		cout << root->value << ' ';
		printHelper(root->right);
	}

	int nodesCountHelper(Node *root) {
		if (!root) return 0;
		else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
	}

	bool deleteValueHelper(Node *parent, Node *current, string value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == NULL || current->right == NULL) {
				Node *temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->root = temp;
				}
			}
			else {
				Node *validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				string temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	void display_in_FILE_helper(Node *curent, int level, ostream &output)
	{
		int i;
		if (curent)
		{
			display_in_FILE_helper(curent->right, level + 1, output);
			output << endl;
			if (curent == root)
			{
				output << "Root->: ";
			}
			else
			{
				for (i = 0; i < level; i++)
				{
					output << "              ";
				}
			}
			output << curent->value << " / " << curent->count;
			display_in_FILE_helper(curent->left, level + 1, output);
		}
	}

	void print_inOrder(Node *root)
	{
		if (root != NULL)
		{
			print_inOrder(root->left);
			cout << "\t" << root->value << " / " << root->count << endl << endl;
			print_inOrder(root->right);
		}
		else
		{
			return;
		}
	}

	void push_to_vector(Node *root)
	{
		if (root != NULL)
		{
			name_list.push_back(root->value);
			count_list.push_back(root->count);

			push_to_vector(root->left);
			push_to_vector(root->right);
		}
		else
		{
			return;
		}
	}

	void save_helper(Node *root, ostream &output)
	{
		if (root != NULL)
		{
			save_helper(root->left, output);
			output << root->value << " " << root->count << endl;
			save_helper(root->right, output);
		}
		else
		{
			return;
		}
	}

public:

	void add(string val) {
		if (root) {
			this->addHelper(root, val);
		}
		else {
			root = new Node(val);
		}
	}

	void add_by_count(string val, int count) {
		if (root) {
			this->add_by_counthelper(root, count, val);
		}
		else {
			root = new Node(val, count);
		}
	}

	void add_FILE(string val, int count)
	{
		if (root) {
			this->add_asFile_helper(root, count, val);
		}
		else {
			root = new Node(val, count);
		}
	}

	void print() {
		printHelper(this->root);
	}

	int nodesCount() {
		return nodesCountHelper(root);
	}

	bool deleteValue(string value) {
		return this->deleteValueHelper(NULL, this->root, value);
	}

	void display_in_FILE()
	{
		fstream output;
		output.open("Draw_BST_Tree.txt", ios::out);	//Make File
		if (!output)
		{
			cerr << "File can not open." << endl;
			exit(1);
		}

		display_in_FILE_helper(root, 0, output);
	}

	void print_name()
	{
		print_inOrder(root);
	}

	void push_vector()
	{
		name_list.clear();
		count_list.clear();
		push_to_vector(root);
	}

	bool search_print(string name)
	{
		Node *temp = root;

		while (temp != NULL)
		{
			if (temp->value == name)
				break;
			if (temp->value.compare(name) < 0){
				temp = temp->right;
			}
			else if (temp->value.compare(name) >= 0){
				temp = temp->left;
			}
		}

		if (temp == NULL)
			return false;

		if (temp->value == name)
		{
			cout << temp->value << " / " << temp->count << endl;
			return true;
		}

		return false;
	}

	bool search_plus(string name)
	{
		Node *temp = root;

		while (temp != NULL)
		{
			if (temp->value == name)
				break;
			if (temp->value.compare(name) < 0){
				temp = temp->right;
			}
			else if (temp->value.compare(name) >= 0){
				temp = temp->left;
			}
		}

		if (temp == NULL)
			return false;

		if (temp->value == name)
		{
			temp->count++;
			return true;
		}

		return false;
	}

	bool search_minus(string name)
	{
		Node *temp = root;

		while (temp != NULL)
		{
			if (temp->value == name)
				break;
			if (temp->value.compare(name) < 0){
				temp = temp->right;
			}
			else if (temp->value.compare(name) >= 0){
				temp = temp->left;
			}
		}

		if (temp == NULL)
			return false;

		if (temp->value == name)
		{
			if (--temp->count > 0)
			{
				return true;
			}
			else
			{
				deleteValue(temp->value);
				return true;
			}
		}

		return false;
	}

	void save_tree()
	{
		fstream output;
		output.open("tree.txt", ios::out);	//Make File
		if (!output)
		{
			cerr << "File can not open." << endl;
			exit(1);
		}

		save_helper(root, output);
	}
};


BST *word_tree = new BST();


void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
	}
}

void color(int number)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, number);
}



void init_tree_FILE()
{
	ifstream inputFile("TEXTS.txt", ios::in | ios::beg);
	if (!inputFile)	//check for file opening
	{
		cerr << "some thing wrong during opening file!" << endl;
		_getche();
		exit(1);
	}

	string tmp;
	while (!inputFile.eof())
	{
		inputFile >> tmp;
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

		for (int i = 0; i < tmp.size(); i++)
		{
			if (!isalpha(tmp[i]))
			{
				tmp.erase(i , 1);
			}
		}

		if (!tmp.empty())
		{
			if (!word_tree->search_plus(tmp))
			{
				word_tree->add(tmp);
			}
		}
	}
	system("cls");
	color(11);
	cout << "\n\n\n\t\t\tYour Tree has been set!";
	system("pause>0");
}

void sort_by_counts()
{
	word_tree->push_vector();

	BST *tmp_tree = new BST();

	for (int i = 0; i < name_list.size(); i++)
	{
		tmp_tree->add_by_count(name_list[i], count_list[i]);
	}

	tmp_tree->print_name();
}

void read_FILE()
{
	ifstream inputFile("tree.txt", ios::in | ios::beg);
	if (!inputFile)	//check for file opening
	{
		cerr << "some thing wrong during opening file!" << endl;
		_getche();
		exit(1);
	}

	string tmp;
	int tmp1;
	while (!inputFile.eof())
	{
		inputFile >> tmp >> tmp1;

		word_tree->add_FILE(tmp, tmp1);

	}
	word_tree->deleteValue(tmp);
	system("cls");
	color(11);
	cout << "\n\n\n\t\t\tYour Tree has been set!";
	system("pause>0");
}



void Add_Word()
{
	system("cls");
	string tmp1;
	cout << "\n\n\tEnter your NEW Word:" << endl;
	cout << "\t-> ";
	cin >> tmp1;
	if (!word_tree->search_plus(tmp1))
	{
		color(11);
		cout << "\n\n\t\tYour NEW Word has been Added for the FIRST time!" << endl;
		word_tree->add(tmp1);
	}
	else
	{
		color(11);
		cout << "\n\n\t\tYour New Word was Exist and Increased ONE time!" << endl;
		cout << "\n\n\n\tThe number of | " << tmp1 << " | has changed to: ";
		word_tree->search_print(tmp1);
	}
	system("pause>0");
}

void Delete_Word()
{
	system("cls");
	string tmp1;
	cout << "\n\n\tEnter your NEW Word:" << endl;
	cout << "\t-> ";
	cin >> tmp1;

	if (!word_tree->search_minus(tmp1))
	{
		color(10);
		cout << "\n\n\t\t\tYour Word NOT Founded!" << endl;
	}
	else
	{
		color(11);
		cout << "\n\n\t\tYour Word was Exist and Decreased ONE time!" << endl;
		cout << "\n\n\n\tThe number of | " << tmp1 << " | has changed to: ";
		if (word_tree->search_print(tmp1) == NULL)
		{
			cout << "0";
		}
	}
	system("pause>0");
}

void Found_Word()
{
	system("cls");
	string tmp1;
	cout << "\n\n\tEnter your NEW Word:" << endl;
	cout << "\t-> ";
	cin >> tmp1;
	color(11);
	cout << "\n\n\t\tResult: ";
	if (!word_tree->search_print(tmp1))
	{
		color(10);
		cout << "\n\n\t\t\tYour Word NOT Founded!" << endl;
	}
	system("pause>0");
}

void Print_Name()
{
	system("cls");
	color(10);
	cout << "\n\nTotal Of Unrepeated Words: " << word_tree->nodesCount() << "\n\n";
	color(11);
	word_tree->print_name();
	system("pause>0");
}

void Print_Count()
{
	system("cls");
	color(10);
	cout << "\n\nTotal Of Unrepeated Words: " << word_tree->nodesCount() << "\n\n";
	color(11);
	sort_by_counts();
	system("pause>0");
}



void about()
{
	system("cls");
	gotoxy(27, 10);
	cout << "Pragraph Words Counter v 0.1";
	gotoxy(27, 12);
	cout << "Coded By Ashkan.rmk";
	gotoxy(27, 14);
	gotoxy(27, 16);
	cout << ":D  ";
	_getch();
	system("cls");
}

void Loading()
{
	system("cls");
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
	gotoxy(48, 5);
	cout << ":) Tree in progress...";
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
	system("cls");
}

void exit_menu()
{
	system("cls");
	char ch;
	int select = 2;

	while (1)
	{
		system("cls");
		color(20);
		gotoxy(28, 6);
		cout << "Are you Sure to EXIT?";

		if (select == 1)
			color(11);
		else
			color(15);

		gotoxy(28, 10);
		cout << "YES";

		if (select == 2)
			color(11);
		else
			color(15);

		gotoxy(28, 12);
		cout << "NO";

		ch = _getch();
		switch (ch)
		{
		case 72:	//Up
			select--;
			if (select == 0)
				select = 2;
			break;
		case 80:	//Down
			select++;
			if (select == 3)
				select = 1;
			break;
		case 13:	//Enter
			if (select == 1)
				exit(1);
			if (select == 2)
			{
				return;
			}
		}
	}

}

void INIT_menu()
{
	system("cls");
	char ch;
	int select = 1;

	while (1)
	{
		system("cls");
		color(10);
		gotoxy(33, 6);
		cout << "BST Tree Initializer";

		if (select == 1)
			color(11);
		else
			color(15);

		gotoxy(28, 10);
		cout << "Read Pragraph as FILE";

		if (select == 2)
			color(11);
		else
			color(15);

		gotoxy(28, 12);
		cout << "Get Pragraph from SERVER";

		if (select == 3)
			color(11);
		else
			color(15);

		gotoxy(28, 14);
		cout << "Recover LAST Tree";

		if (select == 4)
			color(11);
		else
			color(15);

		gotoxy(28, 16);
		cout << "Back";

		ch = _getch();
		switch (ch)
		{
		case 72:	//Up
			select--;
			if (select == 0)
				select = 4;
			break;
		case 80:	//Down
			select++;
			if (select == 5)
				select = 1;
			break;
		case 13:	//Enter
			if (select == 1)
			{
				Loading();
				init_tree_FILE();
				word_tree->save_tree();
				word_tree->display_in_FILE();
				menu();
			}
			if (select == 2)
			{
				Loading();
				menu();
			}
			if (select == 3)
			{
				Loading();
				read_FILE();
				word_tree->display_in_FILE();
				menu();
			}
			if (select == 4)
				menu();
		}
	}
}

void OPR_menu()
{
	system("cls");
	char ch;
	int select = 1;

	while (1)
	{
		system("cls");
		color(10);
		gotoxy(33, 6);
		cout << "Oprations On BST Tree";

		if (select == 1)
			color(11);
		else
			color(15);

		gotoxy(28, 10);
		cout << "Insert New Word";

		if (select == 2)
			color(11);
		else
			color(15);

		gotoxy(28, 12);
		cout << "Delete a Word";

		if (select == 3)
			color(11);
		else
			color(15);

		gotoxy(28, 14);
		cout << "Find a Word";

		if (select == 4)
			color(11);
		else
			color(15);

		gotoxy(28, 16);
		cout << "Print Sorted by Name";

		if (select == 5)
			color(11);
		else
			color(15);

		gotoxy(28, 18);
		cout << "Print Sorted by Frequency";

		if (select == 6)
			color(11);
		else
			color(15);

		gotoxy(28, 20);
		cout << "Back";

		ch = _getch();
		switch (ch)
		{
		case 72:	//Up
			select--;
			if (select == 0)
				select = 6;
			break;
		case 80:	//Down
			select++;
			if (select == 7)
				select = 1;
			break;
		case 13:	//Enter
			if (select == 1)
			{
				Add_Word();
				word_tree->save_tree();
				word_tree->display_in_FILE();
			}
			if (select == 2)
			{
				Delete_Word();
				word_tree->save_tree();
				word_tree->display_in_FILE();
			}
			if (select == 3)
				Found_Word();
			if (select == 4)
				Print_Name();
			if (select == 5)
				Print_Count();
			if (select == 6)
				menu();
		}
	}
}

void menu()
{
	system("cls");
	char ch;
	int select = 1;

	while (1)
	{
		system("cls");
		color(10);
		gotoxy(33, 6);
		cout << "Pragraph Words Counter";

		if (select == 1)
			color(11);
		else
			color(15);

		gotoxy(28, 10);
		cout << "Initialize Words BST Tree";

		if (select == 2)
			color(11);
		else
			color(15);

		gotoxy(28, 12);
		cout << "Oprations on Tree";

		if (select == 3)
			color(11);
		else
			color(15);

		gotoxy(28, 14);
		cout << "About";

		if (select == 4)
			color(11);
		else
			color(15);

		gotoxy(28, 16);
		cout << "Exit";


		ch = _getch();
		switch (ch)
		{
		case 72:	//Up
			select--;
			if (select == 0)
				select = 4;
			break;
		case 80:	//Down
			select++;
			if (select == 5)
				select = 1;
			break;
		case 13:	//Enter
			if (select == 1)
				INIT_menu();

			if (select == 2)
				OPR_menu();

			if (select == 3)
				about();

			if (select == 4)
				exit_menu();
		}
	}
}



int main()
{
	menu();

	return 0;
}