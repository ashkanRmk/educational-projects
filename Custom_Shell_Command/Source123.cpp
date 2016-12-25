#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Sort_Desc(vector<string> &res)
{
	bool flag = true;
	string temp;
	for (int i = 1; (i <= res.size()) && flag; i++)
	{
		flag = false;
		for (int j = 0; j < (res.size() - 1); j++)
		{
			if (res[j + 1] > res[j])
			{
				res[j].swap(res[j + 1]);
				flag = true;
			}
		}
	}
	return;
}

void Sort_Acs(vector<string> &res)
{
	bool flag = true;
	string temp;
	for (int i = 1; (i <= res.size()) && flag; i++)
	{
		flag = false;
		for (int j = 0; j < (res.size() - 1); j++)
		{
			if (res[j + 1] < res[j])
			{
				res[j].swap(res[j + 1]);
				flag = true;
			}
		}
	}
	return;
}

int main(int argc, char *argv[])
{

	string filter1 = argv[1];
	char filter = filter1[0];

	ifstream input;
	input.open("/home/smn/Desktop/dir.txt", ios::in);

	string tmp;
	string info;
	string name_file;
	input >> tmp >> tmp;

	vector<string> name_list;
	vector<string> info_list;

	while (input >> info >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> name_file)
	{
		info = info.substr(0, 4);

		name_list.push_back(name_file);
		info_list.push_back(info);
	}

	bool sort = false;
	vector<string> name_res;
	vector<string> info_res;

	for (int i = 0; i < name_list.size() ; i++)
	{
		switch (filter)
		{
		case 'd':
			if (info_list[i][0] == 'd')
			{
				name_res.push_back(name_list[i]);
				info_res.push_back(info_list[i]);
			}
			break;
		case 'f':
			if (info_list[i][0] == '-')
			{
				name_res.push_back(name_list[i]);
				info_res.push_back(info_list[i]);
			}
			break;
		case 'r':
			if (info_list[i][0] == '-')
			{
				if (info_list[i][1] == 'r')
				{
					name_res.push_back(name_list[i]);
					info_res.push_back(info_list[i]);
				}
			}
			break;
		case 'w':
			if (info_list[i][0] == '-')
			{
				if (info_list[i][2] == 'w')
				{
					name_res.push_back(name_list[i]);
					info_res.push_back(info_list[i]);
				}
			}
			break;
		case 'x':
			if (info_list[i][0] == '-' || info_list[i][0] == 'd')
			{
				if (info_list[i][3] == 'x')
				{
					name_res.push_back(name_list[i]);
					info_res.push_back(info_list[i]);
				}
			}
			break;
		case 's':
			Sort_Acs(name_list);
			sort = true;
			break;
		case 'n':
			Sort_Desc(name_list);
			sort = true;
			break;
		}
	}

	if (sort)
	{
		for (int i = 0; i < name_list.size(); i++)
		{
			cout << name_list[i] << endl;
		}
	}
	else
	{
		for (int i = 0; i < name_res.size(); i++)
		{
			cout << name_res[i] << endl;
		}
	}

	return 0;
}