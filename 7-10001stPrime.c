#include <stdio.h>
#include <time.h>
int main()
{
  int n, //Number of Primes
      p, //Prime indicator
      m, //Counter for n
      i, //Counter
      j; //Counter
  clock_t t[2];
  double tim; //timer

  m = 0;
  j = 1; //Using 1 as a starting point as it will be increased by one before the first check and 2 is the first prime by bringing the definition of a prime number to its logical conclusion
  printf("Which prime do you want to see? ");
  scanf("%d",&n);

  t[0] = clock();
  if (n <= 0) printf("That cannot be done.");
  else while(m<n) //Repeats for requeted amount of prime numbers
  {
    p = 0;
    while (p == 0) //Finds the next prime
    {
      j++;
      if(j % 1 == 0 && j % j == 0 && j > 1) //Is it a potential prime, satisfies positive cases
        {
          p = 1;
          for (i = 2; i < (j+2)/2; i++) //Searches for factors between 2 and j - 1, gets rid of negative cases
          {
            if (j % i == 0) //If a potential factor is divisible by j, it is not a prime number, Checks the negative case
            {
              p = 0;
            }
          }
        }
    }
    m++;
  }

  t[1] = clock();
  if(n%10==1) printf("The %dst prime is %d.",n,j);
  else if(n%10==2) printf("The %dnd prime is %d.",n,j);
  else if(n%10==3) printf("The %drd prime is %d.",n,j);
  else printf("The %dth prime is %d.",n,j);

  printf("\n");

  printf("It took %lf seconds to find.\n", tim = (double) (t[1] - t[0]) / CLOCKS_PER_SEC);

  return 0;
}
