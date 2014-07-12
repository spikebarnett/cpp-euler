#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long int i)
{
	for(int j = 2; j <= sqrt(abs(i)); ++j)
	{
		if(i%j == 0) return false;
	}
	return true;
}

int main()
{
	unsigned int most_primes = 0;
	int most_primes_a = 0, most_primes_b = 0;
	for(long long int a = -999; a <= 999; ++a)
	{
		for(long long int b = -999; b <= 999; ++b)
		{
			unsigned int n = 0;
			while (isPrime(((n * n) + (a * n) + b))) ++n;
			if(n > most_primes)
			{
				most_primes = n;
				most_primes_a = a;
				most_primes_b = b;
			}
		}
	}
	cout << most_primes_a*most_primes_b << endl;
}
