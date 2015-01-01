#include <iostream>
#include "InfInt.h"
using namespace std;

int main()
{
	InfInt res=0;
	InfInt two10="1048576";
	InfInt num="1";
	for(long i=0;i<50;++i) num*=two10;
	
	while(num>0)
	{
		res+=num%10;
		num/=10;
	}
	cout << res << endl;
}

// 137846528820
