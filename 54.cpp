#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class card
{
public:	
	int value;
	int suit;
	
	card(string s)
	{
		switch((int)(s[0]))
		{
			case 84: value=10; break;
			case 74: value=11; break;
			case 81: value=12; break;
			case 75: value=13; break;
			case 65: value=14; break;
			default: value=(int)(s[0])-48;
		}
		switch((int)(s[1]))
		{
			case 83: suit=0; break;
			case 68: suit=1; break;
			case 67: suit=2; break;
			case 72: suit=3; break;
		}
	}
	card()
	{
		value=0;
		suit=0;
	}
	
	friend std::ostream& operator<< (std::ostream& s, const card &c);
};

bool operator<(card const & a, card const & b)
{
    return a.value < b.value;
}

class hand
{
public:
	card cards[5];
	
	void sort()
	{
		std::sort(cards, cards + 5);
	}
	
	bool isSuited()
	{
		for(int i=1;i<5;++i)
		{
			if(cards[0].suit != cards[i].suit) return false;
		}
		return true;
	}
	
	bool isStraight()
	{
		for(int i=1;i<5;++i)
		{
			if(cards[i-1].value != cards[i].value-1) return false;
		}
		return true;
	}
	
	long highcard()
	{
		sort();
		long retval=0;
		for(int i=0;i<5;++i) retval+=cards[i].value*pow(100,i);
		return retval;
	}
	
	long rank()
	{
		sort();
		if(isSuited())
		{
			if(isStraight())
			{
				if(cards[0].value==10) return 90000;
				return 80000;
			}
			return 50000;
		} else {
			if(isStraight()) return 40000;
			int nums[15]={0};
			for(int i=0;i<5;++i) ++nums[cards[i].value];
			for(int i=2;i<15;++i)
			{
				if(nums[i]==2)
				{
					for(int j=0;j<15;++j)
					{
						if(i==j) continue;
						if(nums[j]==2) return 20000+i+j*100;
						if(nums[j]==3) return 60000+i+j*100;
					}
					return 10000+i;
				}
				if(nums[i]==3)
				{
					for(int j=0;j<15;++j)
					{
						if(nums[j]==2) return 60000+j+i*100;
					}
					return 30000+i;
				}
				if(nums[i]==4) return 70000+i;
			}
		}
		return 0;
	}
	
	friend std::ostream& operator<< (std::ostream& s, const hand &h);
};

std::ostream& operator<< (std::ostream& s, const card &c)
{
	if((2<=c.value)&&(c.value<=9)) s << c.value;
	if(c.value==10) s << "T";
	if(c.value==11) s << "J";
	if(c.value==12) s << "Q";
	if(c.value==13) s << "K";
	if(c.value==14) s << "A";
	
	if(c.suit==0) s << "S";
	if(c.suit==1) s << "D";
	if(c.suit==2) s << "C";
	if(c.suit==3) s << "H";
	
	return s;
}

std::ostream& operator<< (std::ostream& s, const hand &h)
{
	for(int i=0;i<5;++i) s << h.cards[i] << " ";
	return s;
}

int main()
{
  ifstream file ("git/euler/poker.txt");
  std::string line;
  int wins=0;
  while (std::getline(file, line))
	{
		istringstream cards(line);
		string c;
		hand player1, player2;
		
		for(int i=0;i<5;++i) { cards >> c; player1.cards[i]=card(c); }
		for(int i=0;i<5;++i) { cards >> c; player2.cards[i]=card(c); }
		int rank1=player1.rank(),rank2=player2.rank();
		if(rank1>rank2) ++wins;
		if((rank1==rank2)&&(player1.highcard()>player2.highcard())) ++wins;
	}
	cout << wins;
	return 0;
}

// 376