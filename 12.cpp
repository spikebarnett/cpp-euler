#include <iostream>
#include <algorithm>
using namespace std;

long numDivisors(long i)
{
	int d=0,s=sqrt(i);
	for(int j=1;j<=s;++j)
	{
		if(i%j==0) d+=2;
	}
	if(s*s==i) --d;
	return d;
}

int main()
{
	int a=0,i=1;
	while (numDivisors(a)<=500) { a+=i; ++i; }
	cout << a << endl;
}

// 76576500
