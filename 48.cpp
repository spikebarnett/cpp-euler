#include <iostream>
using namespace std;

long modAdd(const long a, const long b, const long c)
{
	return ((a%c)+(b%c))%c;
}

long modMul(const long a, const long b, const long c)
{
	return ((a%c)*(b%c))%c;
}

long modPow(const long a, const long b, const long c)
{
	long retval=a;
	for(long i=1;i<b;++i) retval=modMul(retval,a,c);
	return retval;
}

int main()
{
	long res=0;
	for(long i=1;i<=1000;++i) res=modAdd(res,modPow(i,i,10000000000),10000000000);
	cout << res << endl;
}

// 9110846700
