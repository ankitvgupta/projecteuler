#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node* ptr;
}
node;

int dijpower(int input);
bool addlink(int input);

node* first = NULL;

int main(void)
{
  first = malloc(sizeof(node));
  bool check;
  for(int i = 0; i < 1000000; i++)
    {
      int j = dijpower(i);
      if (i == j)
	{
	  check = addlink(i);
	}
    
    }
  node* nextptr = first;
  int sum = 0;
  while(nextptr != NULL && nextptr->value != 1)
    {
      // printf("%d\n", nextptr->value);
      sum += nextptr->value;
      nextptr = nextptr->ptr;
    }
  printf("%d\n", sum);
   return 0;

}

int dijpower(int input)
{
  int result = 0;;
  char* conversion = malloc(7*sizeof(char));
  sprintf(conversion, "%d", input);
  // printf("%s\n", conversion);

  int nums[7];
  for(int i = 0; i < 7; i++)
    {
      nums[i] = 0;
    }

  for(int i = 0; conversion[i] != '\0'; i++)
    {
      nums[i] = conversion[i];
      nums[i] = nums[i] - '0';
    }
  for(int i = 0; conversion[i] != '\0'; i++)
    {
      result += pow(nums[i],5);
    }
  // printf("%d\n", result);
  return result;
}

bool addlink(int input)
{
  node* newnode = malloc(sizeof(node));
  if(newnode == NULL)
    {
      return false;
    }
  newnode -> value = input;

  newnode -> ptr = first;
  first = newnode;
  return true;
}
