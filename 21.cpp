#include <algorithm>
#include <iostream>

using namespace std;

int find_divisors_sum(int i)
{
	if (i < 2) return 0;

	int retval = 0;
	for (int j = 1; j <= sqrt(i); ++j)
	{
		if (i % j == 0)
		{
			retval += j;
			if ((i/j != j) && (i/j != i))
			{
				retval += (i/j);
			}
		}
	}
	return retval;
}

int main()
{
	int retval = 0;
	for (int i = 2; i < 10000; ++i)
	{
		int sum = find_divisors_sum(i);
		if (i != sum)
		{
			if (i == find_divisors_sum(sum)) retval += i;
		}
	}
	cout << retval << endl;
}
