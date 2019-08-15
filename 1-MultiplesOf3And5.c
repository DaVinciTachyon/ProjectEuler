#include <stdio.h>

#define N 1000

int main()
{
  int i,
      sum;

  sum = 0;

  for(i = 0; i < N; i++)
  {
    if(i % 3 == 0 || i % 5 == 0)
    {
      sum += i;
    }
  }

  printf("The multiples of 3 and 5 below %d add up to %d.\n", N, sum);
  return 0;
}
