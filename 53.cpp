#include <iostream>
#include "InfInt.h"

using namespace std;

InfInt factorial(const InfInt i)
{
	if(i<2) return 1;
	return factorial(i-1)*i;
}

InfInt fact[101]={0};
InfInt nCr(const int n, const int r)
{
	return (fact[n])/(fact[r]*fact[n-r]);
}

int main()
{
	for(int i=0;i<102;++i) fact[i]=factorial(i);
	
	int retval=0;
	for(int n=23;n<101;++n)
	{
		for(int r=1;r<n;++r)
		{
			if(nCr(n,r)>1000000) ++retval;
		}
	}
	cout << retval << "\n";
}
