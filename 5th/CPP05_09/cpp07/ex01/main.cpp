#include "include/iter.hpp"

static void printSquareI(int &i)
{
	std::cout << i * i << std::endl;
}

static void printSquareF(float &i)
{
	std::cout << i * i << std::endl;
}

static void printThreeChar(char &i)
{
	std::cout << i << i << i << std::endl;
}

int main( void )
{
	int a[] = {2, 3, 5, 2, 6};
	float b[] = {2.234, 3.5, 5.12, 2.03, 6.99};
	char c[] = {'a', 'r', 'i', 'g', 'a', 't', 'o'};

	iter(a, 5, printSquareI);
	iter(b, 5, printSquareF);
	iter(c, 7, printThreeChar);

	return (0);
}
