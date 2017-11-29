#include <iostream>
#include <vector>
using namespace std;

inline bool isPrime(unsigned i)
{
	if (i <= 1)  return false;
	if (i == 2)  return true;
	if (i%2 == 0) return false;
	
	for(long j=3;j*j<=i;j+=2)
	{
		if(i%j==0) return false;
	}
	return true;
}

int main()
{
	unsigned primes = 3;
	unsigned delta_pos = 2; // Equal to side length - 1
	unsigned cur_pos = 9;
	
	while( ((double)primes)/(2*delta_pos+1) > 0.10){
		delta_pos += 2;
		for(int i = 0; i < 3; i++){
			cur_pos += delta_pos;
			if(isPrime(cur_pos)) primes++;
		}
		cur_pos += delta_pos;
	}
	cout << delta_pos + 1 << "\n";
}

// 26241