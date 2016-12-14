#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

class Node
{
public:
	string name, family, birthPlace, wifeName;
	int id, birthDate, wifeId, numOfChilds;
	bool isAlive, isMarried, gender;
	Node *next, *child, *back;

	Node(string _name, string _family, string _birthPlace, string _wifeName,
		int _id, int _birthDate, int _wifeId,
		bool _isAlive, bool _isMarried, bool _gender)
	{
		name = _name;
		family = _family;
		birthPlace = _birthPlace;
		wifeName = _wifeName;
		id = _id;
		birthDate = _birthDate;
		wifeId = _wifeId;
		numOfChilds = 0;
		isAlive = _isAlive;
		isMarried = _isMarried;
		gender = _gender;
		next = NULL;
		child = NULL;
		back = NULL;
	}
};

class List
{
public:

	Node *first, *heHasTheMostChild;
	int maxChild;

	List()
	{
		first = NULL;
		heHasTheMostChild = NULL;
		maxChild = 0;
	}

	bool addChild(Node *, Node *);
	bool showWifeGirlCousinsBirthPlace();
	Node * countChilds(Node *);
	bool showDeads(Node *);
	bool showMaleCousins(Node *);
	bool showAllChilds(Node *);
	void showAll(Node *);
	bool edit();
	bool showInfo();
	bool delSubTree();
	Node * search(Node *, int);
	Node * getData();
	bool searchAndEdit();
	bool showFather(Node *);

};


Node * List::getData() {
	string name, family, birthPlace, wifeName, ans;
	int id, birthDate, wifeId;
	bool isAlive, isMarried, gender;
	Node * person;

	//////////////////////////////////////////////////////////////////////////

	cout << "\n\n\n\t-NAME- : ";
	getline(cin, name);
	replace(name.begin(), name.end(), ' ', '_');

	///family
	cout << "\t-FAMILY- : ";
	getline(cin, family);
	replace(family.begin(), family.end(), ' ', '_');

	//bithPlace
	cout << "\t-birthPlace- : ";
	getline(cin, birthPlace);
	replace(birthPlace.begin(), birthPlace.end(), ' ', '_');

	///id
	cout << "\t-id- : ";
	while (!(cin >> id)) {
		cout << "\tBad value!\n\tEnter again:";
		cin.clear();
		cin.ignore(99, '\n');
	}
	cin.ignore();

	///birthDate
	cout << "\t-birthDate- : ";
	while (!(cin >> birthDate)) {
		cout << "\tBad value!\n\tEnter again:";
		cin.clear();
		cin.ignore(99, '\n');
	}
	cin.ignore();

	///gender
	cout << "\t-gender?- [male,female]: ";
	getline(cin, ans);
	if (ans == "male") gender = 1;
	else gender = 0;

	///isAlive
	cout << "\t-isAlive?- [y,n]: ";
	getline(cin, ans);
	if (ans == "y") isAlive = 1;
	else isAlive = 0;

	///isMarried
	cout << "\t-isMarried?- [y,n]: ";
	getline(cin, ans);
	if (ans == "y") {
		isMarried = 1;
		///wifeName
		cout << "\t-wifeName- : ";
		getline(cin, wifeName);
		replace(wifeName.begin(), wifeName.end(), ' ', '_');
		///wifeId
		cout << "\t-wifeId- : ";
		while (!(cin >> wifeId)) {
			cout << "\tBad value!\n\tEnter again:";
			cin.clear();
			cin.ignore(99, '\n');

		}
		cin.ignore();
	}
	else {
		isMarried = 0;
		wifeName = "single";
		wifeId = 0;
	}
	//////////////////////////////////////////////////////////////////////////
	///adding child
	///make person node
	person = new Node(name, family, birthPlace, wifeName,
		id, birthDate, wifeId,
		isAlive, isMarried, gender);
	if (!person)
		return NULL;
	return person;
}

bool List::addChild(Node * root, Node * person) {

	Node *head = root;
	//////////////////////////////////////////////////////////////////////////
	///control paths
	if (!person) {
		cout << "no data found";
		return false;
	}
	if (!first) {
		first = person;
		return true;
	}

	if (!head->child) {
		head->child = person;
		person->back = head;
		///child counter
		head->numOfChilds++;
		if (maxChild < head->numOfChilds) {
			maxChild = head->numOfChilds;
			heHasTheMostChild = head;
		}
		///
		return true;
	}
	if (head->child) {
		///child counter
		head->numOfChilds++;
		if (maxChild < head->numOfChilds) {
			maxChild = head->numOfChilds;
			heHasTheMostChild = head;
		}
		///
		head = head->child;
		while (head->next) head = head->next;
		head->next = person;
		person->back = head;
		return true;
	}

}

Node * List::search(Node * root, int id) {
	//////////////////////////////////////////////////////////////////////////
	///recurcieve function
	Node *k_child = NULL, *k_next = NULL;
	if (!root)
		return NULL;
	if (root->id == id)
		return root;
	if (root->child)
		k_child = search(root->child, id);
	if (k_child)
		return k_child;
	if (root->next)
		k_next = search(root->next, id);
	return k_next;
}

void List::showAll(Node *root) {
	Node *head = root;
	if (!head) {
		cout << "the tree is empty" << endl;
		return;
	}
	cout << head->name << "\t" << head->id << endl << "\t\t";
	if (root->child)
		showAll(root->child);
	if (root->next)
		showAll(root->next);
	return;
}

bool List::searchAndEdit() {
	int id;
	//////////////////////////////////////////////////////////////////////////
	///get id
	cout << "\t-id- : ";
	while (!(cin >> id)) {
		cout << "\tBad value!\n\tEnter again:";
		cin.clear();
		cin.ignore(99, '\n');
	}
	cin.ignore();
	//////////////////////////////////////////////////////////////////////////
	///find node
	Node * result = search(first, id);
	if (!result) {
		cout << "not found" << endl;
		return false;
	}
	cout << "pls enter new data:" << endl;
	Node * newData = getData();
	//////////////////////////////////////////////////////////////////////////
	///REPLACE NEW DATA
	result->name = newData->name;
	result->family = newData->family;
	result->birthPlace = newData->birthPlace;
	result->wifeName = newData->wifeName;
	result->id = newData->id;
	result->birthDate = newData->birthDate;
	result->wifeId = newData->wifeId;
	result->isAlive = newData->isAlive;
	result->isMarried = newData->isMarried;
	result->gender = newData->gender;
	return true;
}

bool List::delSubTree() {
	int id;
	//////////////////////////////////////////////////////////////////////////
	///get id
	cout << "\t-id- : ";
	while (!(cin >> id)) {
		cout << "\tBad value!\n\tEnter again:";
		cin.clear();
		cin.ignore(99, '\n');
	}
	cin.ignore();
	//////////////////////////////////////////////////////////////////////////
	///find node
	Node *root = search(first, id);
	if (!root){
		cout << "id not found. " << endl;
		return false;
	}

	Node *head = root->back;
	if (!head) {
		delete root;
		first = NULL;
		heHasTheMostChild = NULL;
		maxChild = 0;
		return true;
	}
	//////////////////////////////////////////////////////////////////////////
	///delete a middle node
	if (root->next) {
		if (head->next->id == id) {
			head->next = root->next;
			root->next->back = head;
			delete root;
			return true;
		}
		if (head->child->id == id) {
			head->child = root->next;
			root->next->back = head;
			delete root;
			return true;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	///delete from last of the list
	if (!root->next) {
		if (root->child) {
			head->child = NULL;
			delete root;
			return true;
		}
	}
}

bool List::showAllChilds(Node * father) {
	Node * head = father;
	if (!head) {
		cout << "list is empty." << endl;
		return false;
	}
	if (!head->child) {
		cout << "this node doesn't have any child.";
		return false;
	}
	head = head->child;
	while (head){
		cout << head->name << "\t" << head->id << endl;
		head = head->next;
	}
	return true;
}


bool List::showDeads(Node * root) {
	Node *head = root;
	if (!head) {
		cout << "the tree is empty" << endl;
		return false;
	}
	if (!head->isAlive)
		cout << head->name << "\t" << head->id << endl << "\t\t";
	if (root->child)
		showDeads(root->child);
	if (root->next)
		showDeads(root->next);
	return true;
}


void main() {
	List a;
	int key, id;
	Node * person, *result, *rslt;
	string ans;
	system("cls");
	while (true) {
		cout << "\n\n\n\Choose any Number For following action:\n\n";
		cout << "\t1 -> Add child\n"
			<< "\t2 -> Search and show info\n"
			<< "\t3 -> Search and edit\n"
			<< "\t4 -> Del sub Tree\n"
			<< "\t5 -> Show all\n"
			<< "\t6 -> Show all childs\n"
			<< "\t7 -> Show all dead\n"
			<< "\t8 -> Exit" << endl;
		cout << "\n\n\t-> ";
		while (!(cin >> key)) {
			cout << "\tBad value!\n\tEnter again:";
			cin.clear();
			cin.ignore(99, '\n');
		}
		cin.ignore();

		switch (key) {
			///ADD
		case 1:
			system("cls");
			person = a.getData();
			cout << "does he/she have father?[y/n]";
			getline(cin, ans);
			if (ans == "y") {
				cout << "\t-father's id- : ";
				while (!(cin >> id)) {
					cout << "\tBad value!\n\tEnter again:";
					cin.clear();
					cin.ignore(99, '\n');
				}
				cin.ignore();
				result = a.search(a.first, id);
				if (a.addChild(result, person))
					cout << "\t------------------------" << endl << "\tDONE!" << endl;
				else
					cout << "\t------------------------" << endl << "\tERROR!" << endl;
			}
			else
				a.addChild(a.first, person);
			system("pause");
			system("cls");
			break;
			//////////////////////////////////////////////////////////////////////////
			///search and show data
		case 2:
			system("cls");
			cout << "\t-id- : ";
			while (!(cin >> id)) {
				cout << "\tBad value!\n\tEnter again:";
				cin.clear();
				cin.ignore(99, '\n');
			}
			cin.ignore();
			result = a.search(a.first, id);
			if (!result) {
				cout << "there's no tree." << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << endl
				<< "name:" << result->name << endl
				<< "family:" << result->family << endl
				<< "birthplace:" << result->birthPlace << endl
				<< "wifeName:" << result->wifeName << endl
				<< "id:" << result->id << endl
				<< "Birthdate:" << result->birthDate << endl
				<< "wifeid:" << result->wifeId << endl
				<< "isalive:" << (result->isAlive ? "yes" : "no") << endl
				<< "ismarried:" << (result->isMarried ? "yes" : "no") << endl
				<< "gender:" << (result->gender ? "male" : "female") << endl;
			system("pause");
			system("cls");
			break;
			//////////////////////////////////////////////////////////////////////////
			///sub tree delete funcion
		case 3:
			system("cls");
			if (a.searchAndEdit())
				cout << "\t------------------------" << endl << "\tDONE!" << endl;
			else
				cout << "\t------------------------" << endl << "\tERROR!" << endl;
			system("pause");
			system("cls");
			break;
			//////////////////////////////////////////////////////////////////////////
			///del sub tree
		case 4:
			system("cls");
			if (a.delSubTree())
				cout << "\t------------------------" << endl << "\tDONE!" << endl;
			else
				cout << "\t------------------------" << endl << "\tERROR!" << endl;
			system("pause");
			system("cls");
			break;
			//////////////////////////////////////////////////////////////////////////
			///show all
		case 5:
			system("cls");
			cout << "\t------------SHOW ALL------------" << endl;
			a.showAll(a.first);
			system("pause");
			system("cls");
			break;
			//////////////////////////////////////////////////////////////////////////
			///show all childs
		case 6:
			system("cls");
			cout << "\t------------SHOW ALL CHILDS------------" << endl;
			cout << "\t-id- : ";
			while (!(cin >> id)) {
				cout << "\tBad value!\n\tEnter again:";
				cin.clear();
				cin.ignore(99, '\n');
			}
			cin.ignore();
			result = a.search(a.first, id);
			a.showAllChilds(result);
			system("pause");
			system("cls");
			break;
			//////////////////////////////////////////////////////////////////////////
			///show deads
		case 7:
			system("cls");
			cout << "\t------------SHOW DEADS------------" << endl;
			if (a.showDeads(a.first))
				cout << "\t------------------------" << endl << "\tDONE!" << endl;
			else
				cout << "\t------------------------" << endl << "\tERROR!" << endl;
			system("pause");
			system("cls");
			break;
			//////////////////////////////////////////////////////////////////////////
			///exit
		case 8:
			system("cls");
			cerr << "\n\n\n" << endl << endl;
			cout << "\n\t-----------EXIT-------------" << endl;
			system("pause");
			exit(1);
			break;
			//////////////////////////////////////////////////////////////////////////
			///default case
		default:
			system("cls");
			cout << "\n\n\n\tpls enter a number between 1-8 !";
			cout << "\n\t------------------------" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}