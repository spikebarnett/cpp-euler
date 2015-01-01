#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(long i)
{
	for(long j=2;j<=sqrt(abs(i));++j)
	{
		if(i%j==0) return false;
	}
	return true;
}

void getPrimeFactors(long i, vector<long> &v)
{
	v.clear();
	for(long j=2;j<=sqrt(i);++j)
	{
		if(i%j==0)
		{
			if(i/j==j)
			{
				if(isPrime(j)) v.push_back(j);
				continue;
			}
			if(isPrime(j)) v.push_back(j);
			if(isPrime(i/j)) v.push_back(i/j);
		}
	}
}

int main()
{
	vector<long> p;
	getPrimeFactors(600851475143,p);
	sort(p.begin(),p.end());
	cout << p.back() << endl;
}

// 6857
