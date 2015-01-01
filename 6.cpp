#include <iostream>
using namespace std;

int main()
{
	long sumOfSqr=0, sqrOfSum=0;
	for(long i=1;i<101;++i)
	{
		sumOfSqr+=i*i;
		sqrOfSum+=i;
	}
	cout << sqrOfSum * sqrOfSum - sumOfSqr << endl;
}

// 25164150
