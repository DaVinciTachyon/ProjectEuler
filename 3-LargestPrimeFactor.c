/*The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?*/
#include <stdio.h>
#include <math.h>

#define N 600851475143

int main()
{
  unsigned long long i;
  int flag,
      j;

  flag = 0;
  for(i = (int)sqrt(N); i > 0 && !flag; i--)
    if(N % i == 0 && i % i == 0 && i % 1 == 0 && i > 1)
    {
      printf("i = %d\n", i);
      for(j = 2, flag = 1; j <= sqrt(i) && flag; j++)
        if(i % j == 0)
          flag = 0;
    }
  i++;

  printf("The highest factor is %d\n", i);

  return 0;
}
