#include <iostream>
#include <algorithm>

using namespace std;

bool pattern[9][6] = { {1,1,0,0,0,1},
											{1,0,1,0,0,1},
											{1,0,0,1,0,1},
											{1,0,0,0,1,1},
											{0,1,0,1,0,1},
											{0,1,0,0,1,1},
											{0,0,1,1,0,1},
											{0,0,1,0,1,1},
											{0,0,0,1,1,1}};

inline bool isPrime(unsigned long i)
{
	if (i <= 1)  return false;
	if (i <= 3)  return true;
	if(i%2==0||i%3==0) return false;
	
	for(long j=5;j*j<=i;j+=6)
	{
		if(i%j==0) return false;
	}
	return true;
}



int fillPattern(const int pat, const int num, const int dig)
{
	if((pat>3)&&(dig==0)) return 0;
	int n[2]={num/100,(num/10)%10};
	int np=1;
	int retval=num%10;
	for(int i=4;i>=0;--i)
	{
		if(pattern[pat][i])
		{
			retval+=n[np]*pow(10,5-i);
			--np;
		} else {
			retval+=dig*pow(10,5-i);
		}
	}
	return retval;
}

int main()
{
	for(int i=100;i<1000;++i)
	{
		for(int j=0;j<9;++j)
		{
			int low=0,cnt=10;
			for(int k=9;k>=0;--k)
			{
				int num=fillPattern(j,i,k);
				if(isPrime(num))
				{
					low=num;
				} else {
					--cnt;
				}
				if(cnt<8) break;
			}
			if(cnt>=8)
			{
				cout << low << "\n";
				return 0;
			}
		}
	}
}

