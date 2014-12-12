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
	vector<int> abundants, abundant_sums;	
	for(int i = 0; i < 28124; ++i)
	{
		if (i < find_divisors_sum(i)) abundants.push_back(i);
	}
	for(unsigned int i = 0; i < abundants.size()/2; ++i)
	{
		for(unsigned int j = i; j < abundants.size(); ++j)
		{
			if (abundants[i] + abundants[j] < 28124) abundant_sums.push_back(abundants[i]+abundants[j]);
		}
	}
	// sort and remove duplicates
	sort( abundant_sums.begin(), abundant_sums.end() );
	abundant_sums.erase( unique( abundant_sums.begin(), abundant_sums.end() ), abundant_sums.end() );
	unsigned long long int retval = 0; int search_start = 0;
	for(unsigned int i = 1; i < 28124; ++i)
	{
		vector<int>::iterator it;
		it = find (abundant_sums.begin() + search_start, abundant_sums.end(), i);
		if( it != abundant_sums.end())
		{
			//cout << i << "   " << search_start << endl;
			++search_start;
		} else {
			//cout << i << "   " << search_start << endl;
			retval += i;
		}
	}
	cout << retval << endl;
}

// 4179871
