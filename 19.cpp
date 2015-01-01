#include <iostream>
using namespace std;

int dpm[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
string weekday[8] = {"","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
class date
{
public:
	int day, month, year;
	
	date(string s)
	{
		day  =stoi(s.substr(0,2));
		month=stoi(s.substr(3,2));
		year =stoi(s.substr(6,4));
	}
};

void operator ++ (date &d)
{
	d.day++;
	int month;
	if(d.month==2)
	{
		month=2;
		if(d.year%4==0)   month=0;
		if(d.year%100==0) month=2;
		if(d.year%400==0) month=0;
	} else {
		month=d.month;
	}
	if(d.day>dpm[month])
	{
		d.day=1;
		++d.month;
		if(d.month>12)
		{
			d.month=1;
			++d.year;
		}
	}
}

bool operator > (const date a, const date b)
{
	if(a.year > b.year) return true;
	if(a.year < b.year) return false;
	if(a.month > b.month) return true;
	if(a.month < b.month) return false;
	if(a.day > b.day) return true;
	return false;
}

bool operator >= (const date a, const date b)
{
	if(a.year > b.year) return true;
	if(a.year < b.year) return false;
	if(a.month > b.month) return true;
	if(a.month < b.month) return false;
	if(a.day > b.day) return true;
	if(a.day < b.day) return false;
	return true;
}

bool operator < (const date a, const date b)
{
	if(a.year < b.year) return true;
	if(a.year > b.year) return false;
	if(a.month < b.month) return true;
	if(a.month > b.month) return false;
	if(a.day < b.day) return true;
	return false;
}

bool operator <= (const date a, const date b)
{
	if(a.year < b.year) return true;
	if(a.year > b.year) return false;
	if(a.month < b.month) return true;
	if(a.month > b.month) return false;
	if(a.day < b.day) return true;
	if(a.day > b.day) return false;
	return true;
}

ostream& operator << (ostream& s, const date d)
{
	if(d.day<10) s << "0" << d.day;
	else s << d.day;
	if(d.month<10) s << "-0" << d.month;
	else s << "-" << d.month;
	s << "-" << d.year;
	return s;
}

int main()
{
	int dow=2;
	int sundays=0;
	date e("31-12-2000");
	for(date d("01-01-1900");d<e;++d,++dow)
	{
		if(dow>7) dow=1;
		if(d.year>1900)
		{
			if((dow==1)&&(d.day==1)) ++sundays;
		}
	}
	cout << sundays << endl;
}

// 171
