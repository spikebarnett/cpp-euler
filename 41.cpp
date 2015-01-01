#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int i)
{
	for(int j=2;j<=sqrt(abs(i));++j)
	{
		if(i%j==0) return false;
	}
	return true;
}

int main()
{
	string pan="7654321";
	do {
		int i=stol(pan);
		if(isPrime(i)) break;
	} while(prev_permutation(pan.begin(), pan.end()));
	cout << pan << endl;
	return 0;
}

// 7652413
