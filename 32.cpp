#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long int> products;

long int concat(long int a, long int b) {
    long int c = b;
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

int main()
{
	long int total = 0;
	for(long unsigned long int i=1; i <= 9876; ++i)
	{
		for(long unsigned long int j=2; j <= 98; ++j)
		{
			if(isPandigital(concat(concat(i,j),i*j)))	products.push_back(i*j);
		}
	}
	std::sort(products.begin(), products.end());
  auto last = std::unique(products.begin(), products.end());
	products.erase(last, products.end());
  for(long int i: products)
  {
		total += i;
	}
	cout << total << endl;
}

// 45228
