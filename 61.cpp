#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<unsigned> figurates[6];

bool canLink(unsigned a, unsigned b)
{
	if(a%100==b/100) return true;
	return false;
}

unsigned findChain(unsigned last=0, unsigned first=0, unsigned usedFigurates=0)
{
	if(usedFigurates==63) {
		if(canLink(last,first)) return last;
		return 0;
	} else if(usedFigurates==0) {
		for(unsigned i=0;i<6;++i) {
			for(auto j:figurates[i]) {
				unsigned retval=findChain(j,j,pow(2,i));
				if(retval > 0) return last+retval;
			}
		}
	} else {
		for(unsigned i=0;i<6;++i) {
			if(usedFigurates&(unsigned)(pow(2,i))) continue;
			for(auto j:figurates[i]) {
				if(canLink(last,j)) {
					unsigned retval=findChain(j,first,usedFigurates|(unsigned)(pow(2,i)));
					if(retval > 0) {
						return last+retval;
					}
				}
			}
		}
		return 0;
	}
	return 0;
}

int main(void)
{
	for(unsigned n=0,i=1;;++i) {
		n=i*(i+1)/2;
		if(n<1010) continue;
		if(n>10000) break;
		figurates[0].push_back(n);
	}
	for(unsigned n=0,i=1;;++i) {
		n=i*i;
		if(n<1010) continue;
		if(n>10000) break;
		figurates[1].push_back(n);
	}
	for(unsigned n=0,i=1;;++i) {
		n=i*(3*i-1)/2;
		if(n<1010) continue;
		if(n>10000) break;
		figurates[2].push_back(n);
	}
	for(unsigned n=0,i=1;;++i) {
		n=i*(2*i-1);
		if(n<1010) continue;
		if(n>10000) break;
		figurates[3].push_back(n);
	}
	for(unsigned n=0,i=1;;++i) {
		n=i*(5*i-3)/2;
		if(n<1010) continue;
		if(n>10000) break;
		figurates[4].push_back(n);
	}
	for(unsigned n=0,i=1;;++i) {
		n=i*(3*i-2);
		if(n<1010) continue;
		if(n>10000) break;
		figurates[5].push_back(n);
	}
	
	cout << findChain() << "\n";
}



