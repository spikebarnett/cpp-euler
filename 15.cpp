#include <iostream>
using namespace std;

long cache[20][20]={0};

long move(long x,long y)
{
	if(cache[x][y]) return cache[x][y];
	if(cache[y][x]) return cache[y][x];
	long retval=0;
	if((x==0)||(y==0)) return 1;
	if(x>0) retval+=move(x-1,y);
	if(y>0) retval+=move(x,y-1);
	return retval;
}

int main()
{
	for(long x=1;x<20;++x)
	{
		for(long y=x+1;y<20;++y)
		{
			cache[x][y]=move(x,y);
		}
	}
	cout << move(20,20) << endl;
}

// 137846528820
