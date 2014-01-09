#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool pandig(int product, int a, int b);
void addnum(int input);

typedef struct node
{
  int value;
  struct node* ptr;
}
node;

node* first = NULL;

int main(void)
{
  first = malloc(sizeof(node));
  int product;
   for (int i = 1; i < 1000; i++)
   {
     for(int j = 1; j < 1000; j++)
       {
	  int result = i  * j;
	  if(pandig(result, i, j))
	    {
	      //    printf("this works: %d\n", result);
	      addnum(result);
	    }
	  else
	    {
	      // printf("this doesn't work");
	    }
       } 
   }
   node* nextpointer = first;
   int sum = 0;
   while(nextpointer != NULL)
     {
       // printf("%d\n", nextpointer->value);                
       sum += nextpointer->value;
       nextpointer = nextpointer-> ptr;
     }
   printf("%d\n", sum);
}

void addnum(int input)
{
  node* newnode = malloc(sizeof(node));
  newnode->value = input;
  newnode->ptr = NULL;
  node* nextptr = first;
  node* currptr = nextptr;

  while(nextptr != NULL)
    {
      //  currptr = nextptr;
      if(input < nextptr->value)
	{
	  if(nextptr == first)
	    {
	      newnode->ptr = nextptr;
	      first = newnode;
	    }
	  else
	    {
	      newnode->ptr = nextptr;
	      currptr->ptr = newnode;
	    }
	  return;
	}
      else if (input == nextptr->value)
	{
	  // printf("%d is already in there\n", input);
	  free(newnode);
	  return;
	}
      else
	{
	  //printf("trying next node\n");
	  currptr = nextptr;
	  nextptr = nextptr->ptr;
	}
    }
  currptr->ptr = newnode;
  // printf("%d  added to the end\n", input);
}

bool pandig(int product, int a, int b)
{
  char buffer1[8];
  char buffer2[4];
  char buffer3[4];
  bool nums[10];

  // start wtih each of the nums being not present
  for(int num = 0; num < 10; num++)
    {
      nums[num] = false;
    }

  // convert the inputs to strings
  sprintf(buffer1, "%d", product);
  sprintf(buffer2, "%d", a);
  sprintf(buffer3, "%d", b);



  // check the product string
  for (int i = 0; buffer1[i] != '\0';i++)
    {
      if(nums[buffer1[i]-'0'])
	{
	  return false;
	}
      else
	{
	  nums[buffer1[i] - '0'] = true;
	}
    }
  // check the 'a' string
  for (int j = 0; buffer2[j] != '\0';j++)
    {
      if(nums[buffer2[j]-'0'])
	{
          return false;
	}
      else
	{
          nums[buffer2[j] - '0'] = true;
        }
    }



  // check the 'b' string
  for (int k = 0; buffer3[k] != '\0';k++)
    {
      if(nums[buffer3[k]-'0'])
        {
          return false;
        }
      else
        {
          nums[buffer3[k] - '0'] = true;
        }
    }

  // check if all elements of nums are true
  for (int check = 1; check < 10; check++)
    {
      //   printf("%d\n", nums[check]);
      if(!nums[check])
	{
	  return false;
	}
    }
  return true;
}
