#include "InfInt.h"
#include <fstream>
using namespace std;

int main()
{
	const unsigned long long ubound = 15000000000;
	bool* prime = new bool[ubound];
	for(unsigned long long i=0;i<ubound;++i) prime[i]=true;
	prime[0]=false;prime[1]=false;prime[2]=true;
	for(unsigned long long i=4;i<ubound;i+=2) prime[i]=false;
	for(unsigned long long i=3;i*i<ubound;i+=2)
	{
		if(!prime[i]) continue;
		for(unsigned long long j=i*i;j<ubound;j+=i) prime[j]=false;
	}
	ofstream file("/home/cbarnett/primes2.txt",ios::out|ios::app);
	if (file)
	{
		for(unsigned long long i=0;i<ubound;++i)
		{
			if(prime[i]) file << i << endl;
		}
	}
	file.close();
	//"/dev/shm/primes2.txt"
	//"/home/cbarnett/primes2.txt"
	delete [] prime;
}
