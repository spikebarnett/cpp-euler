#include <iostream>
#include "InfInt.h"
using namespace std;

InfInt factorial(InfInt i)
{
	if(i==0) return 1;
	return i*factorial(i-1);
}

int main()
{
	int res=0;
	InfInt fact=factorial(100);
	for(unsigned int i=0;i<fact.numberOfDigits();++i)
	{
		int digit = fact.digitAt(i);
		res+=digit;
	}
	cout << res << endl;
}
