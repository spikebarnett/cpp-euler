#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long getDigits(long i)
{
	return floor(log10(i))+1;
}

bool checkFactors(long i)
{
	for(long j=101;j<=999;++j)
	{
		if(i%j==0)
		{
			if(getDigits(i/j)==3) return true;
		}
	}
	return false;
}

void generatePalindromes(vector<int> &v)
{
	v.clear();
	//6 digit palindromes
	for(int a=9;a>0;--a)
	{
		for(int b=9;b>=0;--b)
		{
			for(int c=9;c>=0;--c)
			{
				v.push_back(a*100000 + b*10000 + c*1000 + c*100 + b*10 + a);
			}
		}
	}
}

int main()
{
	vector<int> p;
	generatePalindromes(p);
	for(int i:p)
	{
		if(checkFactors(i))
		{
			cout << i << endl;
			break;
		}
	}
}

// 6906609
