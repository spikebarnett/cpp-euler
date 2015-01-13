#include <iostream>
#include <algorithm>
using namespace std;

long makeTriangular(long i)
{
	return i*(2*i-1)/2;
}

long makePentagonal(long i)
{
	return i*(3*i-1)/2;
}

long makeHexagonal(long i) // is double the triangular
{
	return i*(2*i-1);
}

long whatTriangular(long i)
{
	double j=(sqrt(8*(double)(i)+1)-1)/2;
	if(j==(long)(j)) return j;
	else return 0;
}

long whatPentagonal(long i)
{
	double j=(sqrt(24*(double)(i)+1)+1)/6;
	if(j==(long)(j)) return j;
	else return 0;
}

long whatHexagonal(long i)
{
	double j=(sqrt(8*(double)(i)+1)+1)/4;
	if(j==(long)(j)) return j;
	else return 0;
}

int main()
{
	for(long i=whatHexagonal(40755)+1;;++i)
	{
		long j=makeHexagonal(i);
		if(whatPentagonal(j))
		{
			cout << j << endl;
			return 0;
		}
	}
}

// 1533776805
