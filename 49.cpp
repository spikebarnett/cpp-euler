#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool isPrime(long i)
{
	for(long j=2;j<=sqrt(abs(i));++j)
	{
		if(i%j==0) return false;
	}
	return true;
}

int main()
{
	for(long p1=1234;p1<10000;++p1)
	{
		if(p1==1487) continue;
		if(isPrime(p1))
		{
			string p2; stringstream ss; ss << p1; ss >> p2;
			while (next_permutation(p2.begin(),p2.end()))
			{
				if(isPrime(stol(p2)))
				{
					string p3=p2;
					while (next_permutation(p3.begin(),p3.end()))
					{
						if(isPrime(stol(p3)))
						{
							if(stol(p3)-stol(p2)==stol(p2)-p1)
							{
								cout << p1 << p2 << p3 << endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
}

// 296962999629
