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



int main()
{
	int highest_repeats = 0, highest_repeat_d = 0;
	for(int j = 1; j < 1000; ++j)
	{
		result.clear();
		divide(1, j);
		bool done = false;
		for(unsigned int i = 0; i < result.size(); ++i)
		{
			if(done == true) break;
			for(unsigned int l = i + 1; l < result.size(); ++l)
			{
				if(done == true) break;
				vector<int>::iterator it = find(result.begin() + i + 1, result.end(), result[i]);
				if(it != result.end())
				{
					int dist = l - i;
					for(int k = 0; k <= dist; ++k)
					{
						if(done == true) break;
						if(result[k] != result[k+dist]) break;
						if(k == dist)
						{
							if(dist > highest_repeats)
							{
								highest_repeats = dist;
								highest_repeat_d = j;
							}
							done = true;
							break;
						}
					}
				}
			}
		}
	}
	cout << highest_repeats << "\t" << highest_repeat_d << endl;
}
