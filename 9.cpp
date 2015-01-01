#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	for(int m=2;m<23;++m)
	{
		for(int n=1;n<m;++n)
		{
			int a=m*m-n*n;
			int b=2*m*n;
			int c=m*m+n*n;
			if(a+b+c==1000)
			{
				cout << m << "\t" << n << endl << a*b*c << endl;
				return 0;
			}
		}
	}
}

// 40824
