/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/
#include <stdio.h>
#include <math.h>

#define N 1000

int main()
{
  int a,
      b,
      c,
      flag;

  for(a = b = c = 1, flag = 0; a < N/3 && !flag; a++)
  {
    for(b = a; b < N/2 && !flag; b++)
    {
      c = N - (a + b);
      if(pow(a, 2) + pow(b, 2) == pow(c, 2))
        flag = 1;
    }
    b--;
  }
  a--;

  printf("%d\n", a * b * c);

  return 0;
}
