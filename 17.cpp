#include <iostream>
using namespace std;

int ones[20]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
int tens[10]={0,0,6,6,5,5,5,7,6,6};

int main()
{
	int res=0;
	for(int i=1;i<=1000;++i)
	{
		if(i%100<20)
		{
			res+=ones[i%100];
		} else {
			res+=ones[i%10];
			res+=tens[(i%100)/10];
		}
		if((i%1000>=100)&&(i%100>0))
		{
			res+=10; // hundred and
			res+=ones[(i/100)%10];
		}
		if((i%1000>=100)&&(i%100==0))
		{
			res+=7; // hundred
			res+=ones[(i/100)%10];
		}
		if(i==1000) res+=11; // one thousand
	}
	cout << res << endl;
}

// 21124
