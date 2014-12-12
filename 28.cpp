#include <iostream>
using namespace std;

int main()
{
  int retval = 1, i = 1, j = 2;
  while(j <= 1000)
  {
    for(int k = 0; k < 4; ++k)
    {
      i+=j;
      retval+=i;
    }
    j+=2;
  }
  cout << retval << endl;
}
// 669171001
