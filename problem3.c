#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(long long input)
{
	long long j = sqrt(input) + 1;
	for (long long i = 2; i <= j; i = i + 1)
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

	int prime = 0;
	for(long long i = 2; i < 600851475143; i++)
	{	
		long long remainder = 600851475143 % i;

		if (remainder == 0)
		{
			if(isPrime(i))
			{
				prime = i;
			}
		}
	}
	printf("%d", prime);
	return 0;
}