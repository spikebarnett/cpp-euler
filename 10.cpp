#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void generatePrimes(const unsigned long l, vector<unsigned long> &v)
{
	v.clear(); v.reserve(int(l*log(l))); v.push_back(2);
	bool notPrime[l+1] = {false};
	for(unsigned long j=3;j<=l;j+=2)
	{
		if(notPrime[j]) continue;
		for(unsigned long k=j*j;k<=l;k+=j*2) notPrime[k] = true;
		v.push_back(j);
	}
}

int main()
{
	vector<unsigned long> p; long a=0;
	generatePrimes(2000000, p);
	for(long i:p) a+=i;
	cout << a << endl;
	
}

// 142913828922