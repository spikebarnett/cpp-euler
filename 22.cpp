#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int get_name_value(string s)
{
	int retval = 0;
	for (unsigned int i = 0; i < s.length(); ++i)
	{
		retval += (int)(s[i]) - 64;
	}
	return retval;
}

int main()
{
	unsigned long long int retval = 0;
	vector<string> names;
	ifstream file ("names.txt");
	if (file.is_open())
	{
		string n;
		while (getline(file, n, ','))
		{
			n.erase(remove(n.begin(), n.end(), '\"' ), n.end());
			names.push_back(n);
		}
	}
	sort(names.begin(), names.end());
	for (unsigned int i; i < names.size(); ++i)
	{
		retval += (get_name_value(names[i]) * (i+1));
	}
	cout << retval << endl;
}
