#include <stdio.h>

int findNumOfDivisors(long triangleNum);

int main()
{
  int numOfDivisors,
      i = 1;
  long triangleNum = 0;

  do
  {
    triangleNum += i++;
    numOfDivisors = findNumOfDivisors(triangleNum);
  } while(numOfDivisors <= 500);

  printf("triangle number = %d\n", triangleNum);

  return 0;
}

int findNumOfDivisors(long triangleNum)
{
  int numOfDivisors = 1;

  for(long i = 1; i <= triangleNum / 2; i++)
    if(triangleNum % i == 0)
      numOfDivisors++;

  return numOfDivisors;
}
