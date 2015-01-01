#include <iostream>
#include <algorithm>
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
	for(long j=2;j<=i;++j)
	{
		if(!notPrime[j]) v.push_back(j);
	}
}

int main()
{
	vector<long> p;long a=0;
	generatePrimes(2000000, p);
	for(long i:p) a+=i;
	cout << a << endl;
	
}

// 142913828922
