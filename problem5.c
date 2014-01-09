#include <stdio.h>

int gcf(int a, int b)
{
	
	int quotient = a/b;
	int remainder = a%b;
	if (remainder != 0)
	{
		return gcf(b,remainder);
	}
	else
	{
		return b;
	}	
}

int main(void)
{
	int product = 1;
	for(int i = 1; i <= 20; i++)
	{
		if (product % i != 0)
		{
			int temp = gcf(product, i);
			product *= i / temp;
		}


	}
	printf("%d", product);

}