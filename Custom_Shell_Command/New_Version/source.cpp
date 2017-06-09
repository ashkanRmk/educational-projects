#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{

	string filter1 = argv[1];
	char filter = filter1[0];
	filter = tolower(filter);

	ifstream input;
	input.open("/home/smn/Desktop/dir.txt", ios::in);

	string tmp;
	string stat;
	string process_name;
	input >> tmp >> tmp >> tmp >> tmp >> tmp;

	vector<string> process_list;
	vector<string> stat_list;

	while (input >> tmp >> tmp >> stat >> tmp >> process_name)
	{
		process_list.push_back(process_name);
		stat_list.push_back(stat);
	}

	vector<string> name_res;
	vector<string> stat_res;

	for (int i = 0; i < process_list.size() ; i++)
	{
		switch (filter)
		{
		case 'r':
			if (stat_list[i][0] == 'R')
			{
				name_res.push_back(process_list[i]);
				stat_res.push_back(stat_list[i]);
			}
			break;
		case 's':
			if (stat_list[i][0] == 'S')
			{
				name_res.push_back(process_list[i]);
				stat_res.push_back(stat_list[i]);
			}
			break;
		case 'hp':
			if (stat_list[i].find('<'))
			{
				name_res.push_back(process_list[i]);
				stat_res.push_back(stat_list[i]);
			}
			break;
		case 'b':
			if (stat_list[i][0] == 'R' && stat_list[i].find('+'))
			{
				name_res.push_back(process_list[i]);
				stat_res.push_back(stat_list[i]);
			}
			break;
		}
	}

	for (int i = 0; i < name_res.size(); i++)
	{
		cout << stat_res[i] << name_res[i] << endl;
	}

	return 0;
}