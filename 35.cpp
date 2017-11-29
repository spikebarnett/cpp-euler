#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;

bool isPrime(long long int i)
{
	for(int j = 2; j <= sqrt(abs(i)); ++j)
	{
		if(i%j == 0) return false;
	}
	return true;
}

int concat(int a, int b)
{
	int c = b;
	while (c > 0) {
		a *= 10;
		c /= 10;
	}
	return a + b;
}

void generatePrimes(unsigned a, unsigned b)
{
	bool notPrime[b+1] = { };
	for(unsigned j=2;j<=b;j++)
	{
		if(notPrime[j]) continue;
		for(unsigned k=j*j;k<=b;k+=j) notPrime[k] = true;
		if(j>=a) primes.push_back(j);
	}
}

bool checkRotations(int a)
{
	int b=concat(a%10,a/10);
	while(b!=a)
	{
		//cout << b << endl;
		if(!isPrime(b)) return false;
		b=concat(b%10,b/10);
	}
	return true;
}

int main()
{
	int total=0;
	generatePrimes(2,1000000);
	for(int i: primes)
	{
		//cout << i << endl;
		total+=checkRotations(i);
	}
	cout << total << endl;
}

// 55
