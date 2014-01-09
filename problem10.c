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
	
	long long sum = 2;
	for(long long count = 3; count < 2000000; count += 2)
	{
		if (isPrime(count))
		{
			sum += count;
		}
	}
	printf("%lld", sum);
	
	return 0;
}