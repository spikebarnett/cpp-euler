#include <iostream>
#include <algorithm>
using namespace std;

int getDigits(int i)
{
	return floor(log10(i))+1;
}

int getDigitN(int i, int n, int d)
{
	return (int)(i/pow(10,d-n))%10;
}

int main()
{
	int digs=1,res=1,cur=1;
	while(digs<=1000000)
	{
		int d=getDigits(cur);
		for(int i=1;i<=d;++i)
		{
			if(digs==1) res*=getDigitN(cur,i,d);
			if(digs==10) res*=getDigitN(cur,i,d);
			if(digs==100) res*=getDigitN(cur,i,d);
			if(digs==1000) res*=getDigitN(cur,i,d);
			if(digs==10000) res*=getDigitN(cur,i,d);
			if(digs==100000) res*=getDigitN(cur,i,d);
			if(digs==1000000) res*=getDigitN(cur,i,d);
			++digs;
		}
		++cur;
	}
	cout << res << endl;
}

// 210
