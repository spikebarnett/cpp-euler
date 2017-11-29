#include <iostream>
#include <algorithm>

using namespace std;

int getDigits(int i)
{
	return floor(log10(i))+1;
}

bool sameDigits(const int a, const int b)
{
	if(getDigits(a) != getDigits(b)) return false;
	int da[10]={0},db[10]={0},A=a,B=b;
	while (A>0)
	{
		++da[A%10];++db[B%10];
		A/=10;B/=10;
	}
	for(int i=0;i<10;++i)
	{
		if(da[i]!=db[i]) return false;
	}
	return true;
}

int main()
{
	for(int i=123456;;++i)
	{
		if(!sameDigits(i,i*6)) continue;
		if(!sameDigits(i,i*5)) continue;
		if(!sameDigits(i,i*4)) continue;
		if(!sameDigits(i,i*3)) continue;
		if(!sameDigits(i,i*2)) continue;
		cout << i << "\n";
		return 0;
	}
}
