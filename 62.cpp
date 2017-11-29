#include <iostream>
#include <map>
using namespace std;

class cube {
	public:
	long unsigned base,count;
	cube (long unsigned BASE, long unsigned COUNT) { base=BASE; count=COUNT; }
};

long unsigned maxPermutation(const long unsigned A)
{
	long unsigned digs[10], a=A;
	for(long unsigned i=0;i<10;++i) digs[i]=0;
	do { digs[a%10]++; a/=10; } while(a>0);
	long unsigned retval=0;
	for(int i=9;i>=0;--i)
	{
		for(long unsigned j=0;j<digs[i];++j) { retval*=10;retval+=i; }
	}
	return retval;
}

int main(void)
{
	map<long unsigned, cube> perms;
  long unsigned i=0;
  while (i<9000)
  {
		++i;
		long unsigned p=maxPermutation(i*i*i);
		auto l=perms.find(p);
		if(l==perms.end())
		{
			perms.insert(pair<long unsigned,cube>(p,cube(i,1)));
		}
		else
		{
			if(++l->second.count==5)
			{
				cout << l->second.base*l->second.base*l->second.base << "\n";
				return 0;
			}
		}
	};
}

// 127035954683