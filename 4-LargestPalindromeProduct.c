/*A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.*/
#include <stdio.h>
#include <math.h>
#define D 3


int checkPalindrome(int);
int findLength(int, int);

int main()
{
  int i,
      j,
      temp,
      palindrome;

  for (i = pow(10, D - 1), palindrome = 0; i < pow(10, D); i++)
  {
    printf("i = %d\n", i);
    for (j = i; j < pow(10, D); j++)
    {
      temp = i * j;
      if(checkPalindrome(temp) && temp > palindrome)
        palindrome = temp;
    }
  }

  printf("The largest palindrome made from the product of two %d-digit numbers is %d\n", D, palindrome);

  return 0;
}

int checkPalindrome(int n)
{
  int flag,
      length,
      i;

  flag = 1;
  length = findLength(D*2, n) - 1;

  for(i = 0; i <= (length + 2) / 2; i++, length--)
  {
    if((int)(n / pow(10, length)) % 10 != (int)(n / pow(10, i)) % 10)
    {
      flag = 0;
      break;
    }
  }

  if(flag)
    return 1;
  else
    return 0;
}

int findLength(int l, int n)
{
  int flag;

  flag = 1;

  while(flag)
  {
    l--;
    if((int)(n / pow(10, l)) != 0)
      flag = 0;
  }
  return l + 1;
}
