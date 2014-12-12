#include <iostream>
using namespace std;

int total = 0;

void p(int i, int j)
{
	if((i >= 200)&&(j >= 200)) p(i-200, 200);
	if((i >= 100)&&(j >= 100)) p(i-100, 100);
	if((i >= 50)&&(j >= 50)) p(i-50, 50);
	if((i >= 20)&&(j >= 20)) p(i-20, 20);
	if((i >= 10)&&(j >= 10)) p(i-10, 10);
	if((i >= 5)&&(j >= 5)) p(i-5, 5);
	if((i >= 2)&&(j >= 2)) p(i-2, 2);
	if((i >= 1)&&(j >= 1)) p(i-1, 1);
	if(i == 0) ++total;
}

int main()
{
  p(200,200);
	cout << total << endl;
}

///73682
