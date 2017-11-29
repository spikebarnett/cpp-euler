#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool isPalindromic(const string s)
{
	for(unsigned int i=0;i<s.size()/2;++i)
	{
		if(s[i]!=s[s.size()-i-1]) return false;
	}
	return true;
}

bool isPalindromic(const unsigned long i)
{
	string s;
	ostringstream c;
	c << i;
	s = c.str();
	return isPalindromic(s);
}

unsigned long concat(const unsigned long a, const unsigned long b)
{
	unsigned long A=a,B=b;
	while (B > 0) {
		A *= 10;
		B /= 10;
	}
	return A + b;
}

unsigned long getDigits(unsigned long i)
{
	return floor(log10(i))+1;
}

unsigned long reverse(const unsigned long n)
{
	unsigned long N=n,retval=0; int digs=getDigits(n);
	for(int i=digs-1;i>=0;--i)
	{
		retval+=(N%10)*pow(10,i);
		N/=10;
	}
	return retval;
}

bool isLychrel(const unsigned long i, int depth=1)
{
	if(depth==50) return true;
	unsigned long I=i+reverse(i);
	//cout << depth << ": " << i << " + " << reverse(i) << " = " << I << "\n";
	if(isPalindromic(I)) return false;
	return isLychrel(I, depth+1);
}

int main()
{
	int retval=0;
	for(int i=1;i<10000;++i)
	{
		if(isLychrel(i)) ++retval;
	}
	cout << retval << "\n";
}

// 249
