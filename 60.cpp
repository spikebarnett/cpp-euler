#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const unsigned primeGen = 10000;

bool isPrime(const unsigned i)
{
	for(int j=2;j*j<=i;++j)
	{
		if(i%j == 0) return false;
	}
	return true;
}

unsigned concat(const unsigned a, const unsigned b)
{
	unsigned A = a, B = b;
	while (B > 0) {
		A *= 10;
		B /= 10;
	}
	return A + b;
}

void generatePrimes(const unsigned i, vector<unsigned> &v)
{
	v.clear();
	bool p[i];
	for(unsigned j=3;j<i;j+=2) p[j]=true;
	for(unsigned j=3;j*j<i;j+=2)
	{
		if(!p[j]) continue;
		for(unsigned k=j*j;k<i;k+=j)
		{
			p[k]=false;
		}
	}
	v.push_back(2);
	for(unsigned j=3;j<i;j+=2)
	{
		if(p[j]) v.push_back(j);
	}
}

bool checkPair(const unsigned a, const unsigned b)
{
	if(!isPrime(concat(a,b))) return false;
	if(!isPrime(concat(b,a))) return false;
	return true;
}

int main()
{
	vector<unsigned> p; generatePrimes(primeGen,p);
	
	for(unsigned p1=0;p1<p.size()-4;++p1) {
		for(unsigned p2=p1+1;p2<p.size()-3;++p2) {
			if(!checkPair(p[p1],p[p2])) continue;
			for(unsigned p3=p2+1;p3<p.size()-2;++p3) {
				if(!checkPair(p[p1],p[p3])) continue;
				if(!checkPair(p[p2],p[p3])) continue;
				for(unsigned p4=p3+1;p4<p.size()-1;++p4) {
					if(!checkPair(p[p1],p[p4])) continue;
					if(!checkPair(p[p2],p[p4])) continue;
					if(!checkPair(p[p3],p[p4])) continue;
					for(unsigned p5=p4+1;p5<p.size();++p5) {
						if(!checkPair(p[p1],p[p5])) continue;
						if(!checkPair(p[p2],p[p5])) continue;
						if(!checkPair(p[p3],p[p5])) continue;
						if(!checkPair(p[p4],p[p5])) continue;
						cout << p[p1]+p[p2]+p[p3]+p[p4]+p[p5] << "\n";
						return 0;
					}
				}
			}
		}
	}
	return 0;
}

// 26033