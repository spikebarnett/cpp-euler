#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int total = -1; // Setting to -1 so as to not count 1;
	for(int a = 0; a <= 9; ++a)
	{
		for(int b = 0; b <= 9; ++b)
		{
			for(int c = 0; c <= 9; ++c)
			{
				for(int d = 0; d <= 9; ++d)
				{
					for(int e = 0; e <= 9; ++e)
					{
						for(int f = 0; f <= 9; ++f)
						{
							int p = pow(a,5) + pow(b,5) + pow(c,5) + pow(d,5) + pow(e,5) + pow(f,5);
							int n = a + b*10 + c*100 + d*1000 + e*10000 + f*100000;
							if (p == n) total += p;
						}
					}
				}
			}
		}
	}
	cout << total << endl;
}
// 443839
