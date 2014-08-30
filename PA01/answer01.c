#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
    int count;
    int sum=0;
    for(count = 0; count <= len - 1; count++)
    {
       sum = sum + array[count];
    }
    return (sum);
}

int arrayCountNegative(int * array, int len)
{
  int count;
  int digit=0;
  for(count = 0; count <= len - 1; count++)
    {
      if(array[count] < 0)
	{
	  digit = digit + 1;
	}
    }
  return (digit);
}

int arrayIsIncreasing(int * array, int len)
{   
  int count;
  int neg=1;
  if(len == 0 || len == 1)
    {
      neg=1;
      return(neg);
    }
  for(count = 0; count < len - 1; count++)
    {
      if(array[count]<=array[count+1])
	{
	}
      else
	{
	  neg=0;
	  return(neg);
	}
    }
  return (neg);
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int count;
  int same=0;
  int location[20];
  int vertex=-1;
  int final=0;
  for(count = 0; count <= len-1; count++)
    {
      if(needle == haystack[count])
        {
	  same = same + 1;
	  location[++vertex] = count;
        }
    }
  if(same == 0)
    {
      final = -1;
    }
  else if(same == 1)
    {
      final = location[vertex];
    }
  else
    {
      final = location[vertex];
    }
  return(final);
}

int arrayFindSmallest(int * array, int len)
{
    return 0;
}
