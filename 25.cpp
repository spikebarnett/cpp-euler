#include <iostream>

using namespace std;

unsigned short int *back2, *back1, *current, *tmp;

void swap_pointers()
{
	tmp = back2;
	back2 = back1;
	back1 = current;
	current = tmp;

	for(int i = 0; i < 1000; ++i)
	{
		current[i] = 0;
	}
}

void generate_next()
{
	// back2 + back1
	unsigned short int carriage = 0;
	for(int i = 0; i < 1000; ++i)
	{
		carriage = back2[i] + back1[i] + carriage;
		current[i] = carriage % 10;
		carriage /= 10;
	}
}

int main()
{
	// init arrays
	back2   = new unsigned short int[1000];
	back1   = new unsigned short int[1000];
	current = new unsigned short int[1000];
	for(int i = 0; i < 1000; ++i)
	{
		back2[i] = back1[i] = current[i] = 0;
	}
	back2[0] = back1[0] = 1;
	
	int term = 0;
	while(current[999] == 0)
	{
		swap_pointers();
		generate_next();
		++term;
	}
	cout << term << endl;

}
