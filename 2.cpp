#include <iostream>
using namespace std;

int main()
{
	int total=2;
	int termPrevPrev=1,termPrev=2,termCur=3;
  while(termCur<4000000)
  {
		if(termCur%2==0) total+=termCur;
		termPrevPrev=termPrev;
		termPrev=termCur;
		termCur=termPrev+termPrevPrev;
	}
	cout << total << endl;
}

// 233168
