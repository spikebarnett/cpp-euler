#include <iostream>
using namespace std;

int main()
{
	int total=0;
	for(int i=3; i<1000;i+=3)  total+= i;
	for(int i=5; i<1000;i+=5)  total+= i;
	for(int i=15;i<1000;i+=15) total-= i;
	cout << total << endl;
}

// 233168
