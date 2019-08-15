#include <stdio.h>

int main()
{
  int t,
      tt,
      tN,
      x,
      sum;

  t = 1;
  tN = 2;
  tt = 2;
  sum = 0;

  do
  {
    if(tt % 2 == 0)
      sum += tt;
    t += tt;
    x = tt;
    tt = t;
    t = x;
  }while(tt <= 4000000 && t <= 4000000);

  printf("%d\n", sum);
  return 0;
}
