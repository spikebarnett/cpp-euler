#include <iostream>
#include <cmath>
#include "InfInt.h"
using namespace std;

unsigned GetNumberOfDigits (unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

unsigned is_numerator_more_digits(unsigned I) {
	InfInt n=3, d=2;
	for(unsigned i=1;i<I;i++) {
		InfInt tmp_d=d;
		d+=n;
		n+=tmp_d+tmp_d;
	}
	if (n.numberOfDigits() > d.numberOfDigits()) return 1;
	return 0;
}

int main()
{
	unsigned ans=0;
	for (unsigned i=1;i<1001;i++) {
		ans += is_numerator_more_digits(i);
	}
	cout << ans << "\n";
}

// 153