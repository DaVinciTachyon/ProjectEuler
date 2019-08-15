/*2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/
#include <stdio.h>
#include <math.h>

#define N 20
#define M 1

int main()
{
  int i,
      j,
      flag;

  i = 0;

  do {
    if(i % (int)pow(10, 6) == 0) printf("i = %d\n", (int)(i/pow(10, 6)));
    for(j = M, flag = 0, i+=N; j <= N && !flag; j++)
      if(i % j != 0)
        flag = 1;
  } while(flag);

  printf("The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is %d\n", i);

  return 0;
}
