#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void find_divisors(int i, vector<int> &v)
{
	v.resize(0);
	if (i < 2) return;
	for (int j = 1; j <= sqrt(i); ++j)
	{
		if (i % j == 0)
		{
			v.push_back(j);
			if (i/j != j)
			{
				v.push_back(i/j);
			}
		}
	}
}

void reduce(int n, int d)
{
	vector<int> ndivs, ddivs;
	find_divisors(n,ndivs);
	find_divisors(d,ddivs);
	while ((ndivs.size()>1)&&(ddivs.size()>1))
	{
		sort(ndivs.begin(),ndivs.end());
		if(find(ddivs.begin(), ddivs.end(), ndivs.back())!=ddivs.end())
		{
			n/=ndivs.back();
			d/=ndivs.back();
			find_divisors(n,ndivs);
			find_divisors(d,ddivs);
			continue;
		} else {
			ndivs.pop_back();
		}
	}
	cout << d;
}


int main()
{
	int n=1,d=1;
	
	for(float i=1; i <= 9; ++i)
	{
		for(float j=1; j <= 9; ++j)
		{
			for(float s=1; s <= 9; ++s) // Shared digit
			{
				if((i==s)||(j==s)) continue;
				if(((i*10+s)/(s*10+j))==(i/j))
				{
					n*=(i*10+s);
					d*=(s*10+j);
				}
			}
		}
	}
	reduce(n,d);
}

// 100
