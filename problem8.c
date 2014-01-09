#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int products(void);
bool enqueue (FILE* inptr);


typedef struct 
{
	int members[5];
	int front;
}
queue;

queue nums;



int main (void)
{
	FILE* input = fopen("inputp8.txt", "r");
	int product = 1;
	int qcapacity = 5;
	nums.front = 0;
	for (int i = 0; i < 5; i++)
	{
		char c = fgetc(input);
		nums.members[i] = c - '0';
	}
	product = products();

	while(enqueue(input))
	{
		int compare = products();
		if (compare > product)
		{
			product = compare;
		}
	}
	printf("%d\n", product);
	return 0;
}

int products(void)
{
	int result = 1;
	for(int i = 0; i < 5; i++)
	{
		result *= nums.members[i];
	}
	return result;
}

bool enqueue (FILE* inptr)
{
	char c = fgetc(inptr);
	if(c == EOF)
	{	
		return false;
	}
	int num = c - '0';
	nums.front = (nums.front + 1) % 5;
	nums.members[(nums.front+4) % 5] = num;
	return true;
}