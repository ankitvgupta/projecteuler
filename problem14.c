#include <stdio.h>

int main(void)
{
	long long highest = 1;
	long long counter = 0;
	for (int i = 2; i < 1000000; i++)
	{
		long long j = i;
		long long newcounter = 0;
		while (j != 1)
		{
			if (j % 2 == 0)
			{
				j /= 2;
			}
			else
			{
				j = 3 * j + 1;
			}
			newcounter++;
		}
		if(newcounter > counter)
		{
			counter = newcounter;
			highest = i;
		}

	}
	printf("%lld\n", highest);
	return 0;
}