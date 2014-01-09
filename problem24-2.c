#include <stdio.h>
#include <stdbool.h>

int factorials(int i);


int main(void)
{
	int number = 2;
 	int nums[10];
 	for (int i = 0; i < 10; i++)
 	{
 		int temp = factorials(10 - i);
 		nums[i] = number / temp;
 		number = number - nums[i]*temp;

 	}
 	printf("%d %d %d %d %d %d %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8], nums[9]);

}


int factorials(int i)
{
	int product = 1;
	for(int j = i; j >= 1; j--)
	{
		product *= j;
	}
	return product;
}