#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

vector<int> palis;

string makeBinary(int a)
{
	const string result = bitset<32>(a).to_string();
	return result.substr(result.find("1", 0));
}

bool isPalindromic(string a)
{
	for(unsigned int i=0;i<a.size()/2;++i)
	{
		if(a[i]!=a[a.size()-i-1]) return false;
	}
	return true;
}

void generatePalindromes()
{
	// 1 and 2 digit palindromes
	for(int a=1;a<10;a+=2)
	{
		palis.push_back(a);
		palis.push_back(a*10 + a);
	}	
	// 3 and 4 digit palindromes
	for(int a=1;a<10;a+=2)
	{
		for(int b=0;b<10;++b)
		{
			palis.push_back(a*100 + b*10 + a);
			palis.push_back(a*1000 + b*100 + b*10 + a);
		}
	}
	// 5 and 6 digit palindromes
	for(int a=1;a<10;a+=2)
	{
		for(int b=0;b<10;++b)
		{
			for(int c=0;c<10;++c)
			{
				palis.push_back(a*10000 + b*1000 + c*100 + b*10 + a);
				palis.push_back(a*100000 + b*10000 + c*1000 + c*100 + b*10 + a);
			}
		}
	}
}

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
	int total=0;
	generatePalindromes();
	for(int i:palis)
	{
		if(isPalindromic(makeBinary(i))) total+=i;
	}
	cout << total << endl;
}

// 872187
