#include <iostream>
#include "InfInt.h"
using namespace std;
//numberOfDigits

InfInt pow(const InfInt a, const InfInt b)
{
	InfInt retval=1;
	for(InfInt i=0;i<b;i++) retval*=a;
	return retval;
}

int main(void)
{
	unsigned retval=0;
	for(InfInt i=1;i<10;i++)
	{
		for(InfInt j=1;(InfInt)pow(i,j).numberOfDigits()==j;j++) { retval++; }
	}
	cout << retval << "\n";
}