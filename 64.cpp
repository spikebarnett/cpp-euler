#include <iostream>
#include <cmath>
#include <vector>
#include "cln/cln.h"
using namespace std;

vector<unsigned> contfrac;
const unsigned reqSize=6;
const unsigned reqLoops=3;
const cln::cl_I zero=0;
const cln::cl_I one=1;

unsigned checkLoop(vector<cln::cl_I> n)
{
	if(n.size()<reqSize) return 0;
	const unsigned p=n.size()/reqLoops;
	for(unsigned i=0;i<p;i++)
	{
		for(unsigned j=1;j<reqLoops;j++)
		{
			if(n[i]!=n[i+j*p]) return 0;
		}
	}
	return p;
}

unsigned sqrtPeriod(const cln::cl_I N)
{
	vector<cln::cl_I> nums;
	cln::cl_I n=N;
	cln::cl_LF nroot=sqrt(n);
	contfrac.clear();
	cln::cl_LF f=nroot;f-=truncate1(f); cln::cl_I h=floor1(nroot);
	if(f==zero) return 0;
	unsigned period=0;
	while (!period)
	{
		period++;
		f=recip(f);h=floor1(f);f-=h;
		nums.push_back(h);
		period=checkLoop(nums);
		for(unsigned i=0;i<nums.size();i++) cout << nums[i] << ", ";
		cout << " ...\n";
	}
	return period;
}

int main(void)
{
	unsigned retval=0; int period=-1;
	for(unsigned i=1;i<600;i++)
	{
		long int p=sqrtPeriod(i);
		if(p>period)
		{
			cout << i << ", ";
			period=p;
		}
		//if(sqrtPeriod(i)%2==1) retval++;
	}
	//cout << retval << "\n";
}





// 1, 2, 3, 7, 13, 19, 31, 43, 46, 94, 139, 151, 166, 211, 331, 421, 526, 571
// 1, 2, 3, 7, 13, 19, 31, 43, 46, 94, 163, 166, 217, 421,


