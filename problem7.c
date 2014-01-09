#include <stdio.h>
#include <stdbool.h>

bool isPrime(int input)
{
	for (int i = 2; i < input; i++)
	{
		if (input % i == 0)
		{
			return false;
		}
	}	
	return true;
} 

int main(void)
{
	int counter = 0;
	int number = 2;
	int prime = 0;
	while(counter < 10001)
	{
		if (isPrime(number))
		{
			counter++;
			prime = number;
		}
		number++;
	}
	printf("%d", prime);
	return 0;
}