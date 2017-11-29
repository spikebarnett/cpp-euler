#include "InfInt.h"
#include <fstream>
using namespace std;


inline bool isPrime(InfInt i)
{
	InfInt sq = i.intSqrt();
	ifstream file("/home/cbarnett/primes.txt",ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file,line))
		{
			InfInt prime=line;
			if(prime>sq) break;
			if(i%prime==0) return false;
		}
	}
	file.close();
	return true;
}

string getLastLine()
{
	ifstream file("/home/cbarnett/primes.txt");
	if(file)
	{
		std::string line;
		while (file >> ws && getline(file, line));
		file.close();
		return line;
	}
	cout << "Failed to get last line!" << endl;
	return "0";
}

int main()
{
	InfInt lbound = getLastLine();
	InfInt ubound = "20000000000";
	
	for(InfInt i=lbound+2;i<ubound;i+=2)
	{
		if(i%10==5) continue;
		if(isPrime(i))
		{
			ofstream file("/home/cbarnett/primes.txt",ios::out|ios::app);
			if (file)
			{
				file << i << endl;
			}			
		}
	}
}
