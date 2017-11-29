#include <iostream>
using namespace std;

bool isPrime(long i)
{
	for(long j=2;j*j<=i;++j)
	{
		if(i%j==0) return false;
	}
	return true;
}

int main()
{
	for(long i=775143;i>2;i-=2) {
		if(600851475143l%i!=0) continue;
		if(isPrime(i)) {
			cout << i << "\n";
			return 0;
		}
	}
}

// 6857