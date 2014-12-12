#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pans;

int concat(int a, int b)
{
	int c = b;
	while (c > 0) {
		a *= 10;
		c /= 10;
	}
	return a + b;
}

bool isPandigital(long int x)
{
	if(x>987654321) return false;
	long int y = x;
	long int n[10] = {};
	
	while (y>0)
	{
		if(y%10==0) return false; 
		++n[y%10];
		y/=10;
	}
	if(n[0]>0) return false;
	bool hitZero = false;
	for(long int i=1;i<=9;++i)
	{
		if(hitZero)
		{
			if(n[i]>0) return false;
		} else {
			if(n[i]==0)
			{
				hitZero=true;
				continue;
			} else if(n[i]>1) return false;
		}
	}
	if(n[9]!=1) return false;
	return true;
}

int catProd(int a, int b)
{
	if(a<1) return 0;
	if(b<2) return 0;
	int i=0;
	for(int j=1;j<=b;++j) i=concat(i, a*j);
	return i;
}

int main()
{
	for(int i=2;i<10;++i)
	{
		for(int j=3;j<9876;++j)
		{
			if(isPandigital(catProd(j,i))) pans.push_back(catProd(j,i));
		}
	}
	sort(pans.begin(),pans.end());
	cout << pans.back() << endl;
}

// 932718654
