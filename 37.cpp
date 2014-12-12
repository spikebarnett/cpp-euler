#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> primes;

int concat(int a, int b)
{
	int c = b;
	while (c > 0) {
		a *= 10;
		c /= 10;
	}
	return a + b;
}

bool isPrime(int i)
{
	for(int j = 2; j <= sqrt(abs(i)); ++j)
	{
		if(i%j == 0) return false;
	}
	return true;
}

void generatePrimes2(int n, int a)
{
	if(n<pow(10,a-1))
	{
		int d[4] = {1,3,7,9};
		for(int i:d)
		{
			int m = concat (n, i);
			generatePrimes2(m, a);
			if((m%10==1)||(m%10==9)) continue;
			if(isPrime(m)) primes.push_back(m);
		}
	}
}

int removeFirstDigit(int i)
{
    if(i<10) return 0 ;
    else return i%10+removeFirstDigit(i/10)*10;
}

void generatePrimes(int a)
{
	int d[4] = {2,3,5,7};
	for(int i:d) generatePrimes2(i,a);
}	

int checkTruncations(int i)
{
	int j=i;
	while(j>0)
	{
		j/=10;
		if(!isPrime(j)) return false;
	}
	j=i;
	while(j>0)
	{
		j=removeFirstDigit(j);
		if(!isPrime(j)) return false;
	}	
	return i;
}

int main()
{
	int total=0;
	generatePrimes(6);
	for(int i:primes) total+=checkTruncations(i);
	cout << total << endl;
}

// 748317
