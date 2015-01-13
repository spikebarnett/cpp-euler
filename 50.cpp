#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void generatePrimes(const long i, vector<long> &v)
{
	v.clear();
	bool p[i];
	for(long j=3;j<i;j+=2) p[j]=true;
	for(long j=3;j*j<i;j+=2)
	{
		if(!p[j]) continue;
		for(long k=j*j;k<i;k+=j)
		{
			p[k]=false;
		}
	}
	v.push_back(2);
	for(long j=3;j<i;j+=2)
	{
		if(p[j]) v.push_back(j);
	}
}

inline bool isPrime(unsigned long i)
{
	for(long j=2;j*j<=i;++j)
	{
		if(i%j==0) return false;
	}
	return true;
}

int main()
{
	vector<long> p; generatePrimes(1000000L,p);
	long r=0,c=0;
	for(unsigned long i=1;i<p.size();++i)
	{
		long v=0,n=0;
		for(unsigned long j=i;j>0;--j)
		{
			v+=p[j];++n;
			if(v>1000000L) break;
			if(isPrime(v))
			{
				if(n>c)
				{
					r=v;c=n;
				}
			}
		}
	}
	cout << r << endl;
}

// 997651
