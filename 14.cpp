#include <iostream>
using namespace std;

long cache[1000000]={0};

long collatz(long i)
{
	if(i<1000000)
	{
		if(cache[i]) return cache[i];
	}
	if(i==1) return 1;
	if(i%2) return 1+collatz((3*i)+1);
	return 1+collatz(i/2);
}

int main()
{
	long res=0,val=0;
	for(long i=2;i<1000000;++i)
	{
		long col=collatz(i);
		cache[i]=col;
		if(col>val)
		{
			res=i;
			val=col;
		}
	}
	cout << res << endl;
}

// 837799
