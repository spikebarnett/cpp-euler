#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int fact(int i)
{
  if (i == 0) return 0;
  if (i == 1) return 1;
  return i * fact(i - 1);
}

int main()
{
  vector<int> retval, numbers = { 0,1,2,3,4,5,6,7,8,9 };
  int examined = 0;

  for(int i = 9; i >= 1; --i)
  {
    int j = 0;
    while((fact(i) * (j+1)) + examined < 1000000)
    {
      ++j;
    }
    //cout << j << endl;
    retval.push_back(j);
    examined += (fact(i) * j);
  }
  for(int i = 0; i < 10; ++i)
  {
    cout << numbers[retval[i]];
    numbers.erase(numbers.begin() + retval[i]);
  }
  cout << endl;
}
