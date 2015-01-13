#include <iostream>
#include <algorithm>
using namespace std;

vector<int> p;

int makePentagonal(int i)
{
	return i*(3*i-1)/2;
}

int whatPentagonal(int i)
{
	double j=(sqrt(24*(double)(i)+1)+1)/6;
	if(j==(int)(j)) return j;
	else return 0;
}

int main()
{
	int D=0,k=1,K,J;
	while(!D)
	{
		++k;
		K=makePentagonal(k);
		for(int j=1;j<k;++j)
		{
			J=makePentagonal(j);
			if((whatPentagonal(K+J))&&(whatPentagonal(K-J))) D=K-J;
		}
	}
	cout << D << endl;
}

// 5482660
