#include <iostream>
//#include <algorithm>
#include "InfInt.h"

using namespace std;

InfInt pow(const InfInt a, const InfInt b)
{
	InfInt retval=a;
	for(InfInt i=b;i>1;--i) retval*=a;
	return retval;
}

InfInt max(const InfInt a, const InfInt b)
{
	return a>b?a:b;
}

InfInt digitSum(const InfInt n)
{
	int retval=0;
	for(unsigned int i=0;i<n.numberOfDigits();++i) retval+=n.digitAt(i);
	return retval;
}

int main()
{
	InfInt retval=0;
	for(InfInt a=51;a<100;++a)
	{
		for(InfInt b=51;b<100;++b)
		{
			retval = max(retval,digitSum(pow(a,b)));
		}
	}
	cout << retval << "\n";
}

// 972
