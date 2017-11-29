#include "infinint.hpp"
#include <limits>
using namespace std;

//18 446 744 073 709 551 615
//   999 999 999 999 999 999
int main(void)
{
	//cout << numeric_limits<unsigned long>::max() << endl;
	//cout << numeric_limits<unsigned long long>::max() << endl;
	//cout << numeric_limits<signed long long int>::min() << "-" << numeric_limits<signed long long int>::max() << endl;
	infinint a=infinint("12345678901234567890e35");
	infinint b=infinint("12345678901234567890");
	cout << a+b << endl;
	//cout << b << endl;
	//cout << c << endl;
	//cout << d << endl;
}
