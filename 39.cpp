#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int p[1001]={};
	for(int a=1;a<500;++a)
	{
		for(int b=1;b<500;++b)
		{
			float c=sqrt(a*a+b*b);
			if(c==(int)(c))
			{
				if(a+b+(int)(c)<=1000) ++p[a+b+(int)(c)];
			}
		}
	}
	int highIndex=0;
	for(int i=0;i<=1000;++i)
	{
		if(p[i]>p[highIndex])
		{
			highIndex = i;
		}
	}
	cout << highIndex << endl;
}

// 840
