#include <iostream>
#include <vector>
using namespace std;

void generatePrimes(long i, vector<long> &v)
{
	v.clear();
	bool notPrime[i+1]={false};
	for(long j=2;j<=i;++j)
	{
		if(notPrime[j]) continue;
		for(long k=j+j;k<=i;k+=j)
		{
			if(k<=i) notPrime[k]=true;
		}
	}
	for(int j=2;j<=i;++j)
	{
		if(!notPrime[j]) v.push_back(j);
	}
}

int main()
{
	vector<long> p; generatePrimes(1000000, p); int a=0;
	for(int i:p)
	{
		++a;
		if(a==10001)
		{
			cout << i << endl;
			return 0;
		}
	}
}

// 104743
