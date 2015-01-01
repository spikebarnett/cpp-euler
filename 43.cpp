#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

vector<int> tri;

int concat(int a, int b)
{
	int c = b;
	while (c > 0) {
		a *= 10;
		c /= 10;
	}
	return a + b;
}

int main()
{
	long long unsigned int total=0;
	string pan="1023456789"; // lowest posible 0-9 pandigital number
	do
	{
		if(pan=="0123456789") break; // we're done
		long i=stol(pan);
		if(((i/1000000)%1000)%2!=0) continue;
		if(((i/100000)%1000)%3!=0) continue;
		if(((i/10000)%1000)%5!=0) continue;
		if(((i/1000)%1000)%7!=0) continue;
		if(((i/100)%1000)%11!=0) continue;
		if(((i/10)%1000)%13!=0) continue;
		if(((i/1)%1000)%17!=0) continue;
		total+=i;
	} while(next_permutation(pan.begin(), pan.end()));
	cout << total << endl;
}

// 16695334890
