#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};

int main()
{	
	int t=0;
	for(int i=10; i <= 999999; ++i)
	{
		int s=0, n=i;
		while(n>0)
		{
			s+=fact[n%10];
			n/=10;
		}
		if(i==s) t+=i;
	}
	cout << t << endl;
}

// 40730
