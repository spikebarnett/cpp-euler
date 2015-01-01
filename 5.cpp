#include <iostream>
#include <algorithm>
using namespace std;

long long f[20]={0};

void getFactors(long i)
{
	for(long long j:{2,3,5,7,11,13,17,19})
	{
		long long n=0;
		while(i%j==0)
		{
			i/=j;
			f[j]=max(f[j],++n);
		}
		if(i==1) return;
	}
}

int main()
{
	long long ans=1;
	for(long long i=2;i<21;++i)
	{
		getFactors(i);
	}
	for(long long i:{2,3,5,7,11,13,17,19})
	{
		for(long long j=0;j<f[i];++j) ans*=i;
	}
	cout << ans << endl;
}

// 232792560
