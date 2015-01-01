#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <vector>
using namespace std;

vector<int> tri;

void generateTriNums(int n)
{
	for(int i=1;i<=n;++i)
	{
		tri.push_back(i*(i+1)/2);
	}
}

inline int toLetterVal(char l)
{
	return (int)(l)-64;
}

inline int toWordVal(string w)
{
	int retval=0;
	for(unsigned int i=0;i<w.size();++i)
	{
		retval+=toLetterVal(w[i]);
	}
	return retval;
}

int main()
{
	int total=0;
	generateTriNums(27);
	
	string word;
  ifstream file ("p042_words.txt");
  if (file.is_open())
  {
    while ( getline (file,word,','))
    {
			boost::erase_all(word, "\"");
			if(find(tri.begin(),tri.end(),toWordVal(word))!=tri.end()) ++total;
    }
    file.close();
  }
  cout << total << endl;
}

// 162
