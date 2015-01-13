#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long> p;

bool isPrime(long i)
{
	for(long j=2;j<=sqrt(abs(i));++j)
	{
		if(i%j==0) return false;
	}
	return true;
}

int checkConjecture(long i)
{
	for(long j:p)
	{
		long k=1;
		for(;;)
		{
			if(i==j+2*k*k) return 0;
			if(i<j+2*k*k) break;
			++k;
		}
	}
	return i;
}

int main()
{
	long res=0,i=3;
	while(!res)
	{
		if(isPrime(i)) p.push_back(i);
		else res=checkConjecture(i);
		i+=2;
	}
	cout << res << endl;
}

// 5777
