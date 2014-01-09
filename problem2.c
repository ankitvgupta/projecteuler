#include <stdio.h>

int main(void)
{
	int first = 1;
	int second = 2;
	int sum = 2;
	while (second <= 4000000)
	{
		int temp = first + second;
		first = second;
		second = temp;
		if (second % 2 == 0){
			sum += second;
		}

	}
	printf("%d", sum);

}