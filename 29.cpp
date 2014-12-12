#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<double> terms;
	for(int a = 2; a <= 100; ++a)
	{
		for(int b = 2; b <= 100; ++b)
		{
			double p = pow(a,b);
			if (find(terms.begin(), terms.end(), p) == terms.end()) terms.push_back(p);
		}
	}
	cout << terms.size() << endl;
}
// 9183
