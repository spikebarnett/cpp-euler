#include <iostream>
using namespace std;

const long long unsigned numbers=100;

int main()
{
	long long unsigned sumOfSqr=0, sqrOfSum=(numbers*numbers+numbers)*(numbers*numbers+numbers)/4;
	for(long long unsigned i=1;i<numbers+1;++i) sumOfSqr+=i*i;	
	cout << sqrOfSum - sumOfSqr << endl;
}

// 25164150