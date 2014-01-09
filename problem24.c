#include <stdio.h>
#include <stdbool.h>

bool isper(int* input);

typedef struct node
{
	int value;
	struct node* nptr;
}
node;



int main(void)
{
	int nums[10];
	for (int c = 0; c < 10; c++)
	{
		nums[c] = c;
	}
	nums[9] = 8;
	int counter = 0;
	while(counter < 1000000)
	{
		nums[9]++;
		for(int j = 9; j > 0; j--)
		{
			if(nums[j] == 10)
			{
				nums[j] = 0;
				nums[j - 1]++;
			}
		}
		if(nums[0] == 10)
		{
			return 0;
		}
		if(isper(nums))
		{
			counter++;
		}
		printf("%d%d%d%d%d%d%d%d%d%d - %d\n", nums[0],nums[1],nums[2],nums[3],nums[4],nums[5],nums[6],nums[7],nums[8],nums[9], counter);

	}
	printf("%d%d%d%d%d%d%d%d%d%d", nums[0],nums[1],nums[2],nums[3],nums[4],nums[5],nums[6],nums[7],nums[8],nums[9]);

}

bool isper(int* input)
{
	bool checker[10];
	bool verify = true;
	for(int k = 0; k < 10; k++)
	{
		checker[k] = false;
	}
	for(int j = 0; j < 10; j++)
	{
		checker[input[j]] = true;
	}

	for(int m = 0; m < 10; m++)
	{
		if(!checker[m])
		{
			verify = false;
		}
	}
	return verify;
}
