#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const unsigned int precision = 2000;
vector<int> result;

void divide(unsigned int n, unsigned int d, unsigned int i = 0)
{
	if (n)
	{
		if(i == precision) return;
		if(n > d)
		{
			result.push_back(n/d);
			divide(n%d, d, ++i);
		} else {
			if(n*10 < d) result.push_back(0);
			divide(n*10, d, i);
		}
	}
}

bool check_repeat(int i, int d)
{
	for(int k = 0; k <= d; ++k)
	{
		if(result[i + k] != result[i+k+d]) return false;
		if(k == d) return true;
	}
	return false;
}

int get_num_repeats(unsigned int h)
{
	for(unsigned int i = 0; i < result.size(); ++i)
	{
		for(unsigned int l = i + 1; l < result.size(); ++l)
		{
			vector<int>::iterator it = find(result.begin() + i + 1, result.end(), result[i]);
			if(it != result.end())
			{
				if(check_repeat(i, l-i))
				{
					return l-i;
				}
			}
		}
	}
	return 0;
}

int main()
{
	unsigned int highest_repeats = 0, highest_repeat_d = 0;
	for(int j = 1; j < 1000; ++j)
	{
		result.clear();
		divide(1, j);
		unsigned int reps = get_num_repeats(highest_repeats);
		if(reps > highest_repeats)
		{
			highest_repeats = reps;
			highest_repeat_d = j;
		}
	}
	cout << highest_repeat_d << endl;
}
