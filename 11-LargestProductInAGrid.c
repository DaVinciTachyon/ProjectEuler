#include <stdio.h>

#define N 20
#define M 4

void extractArray(char inputName[37], int grid[N][N]);
long findLargestProductInGrid(int grid[N][N]);
long findLargestHorizontalProduct(int grid[N][N]);
long findLargestVerticalProduct(int grid[N][N]);
long findLargestDiagonalProduct(int grid[N][N]);

int main()
{
  char inputName[37] = "11-LargestProductInAGridTextFile.txt";
  int grid[N][N];

  extractArray(inputName, grid);

  long largestProduct = findLargestProductInGrid(grid);

  printf("largestProduct = %ld\n", largestProduct);

  return 0;
}

void extractArray(char inputName[37], int grid[N][N])
{
  FILE *fileToInput;
	fileToInput = fopen(inputName, "r");

	for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      fscanf(fileToInput, "%d", &grid[i][j]);

  fclose(fileToInput);
}

long findLargestProductInGrid(int grid[N][N])
{
  long  largestProduct,
        tempLargest;

  tempLargest = findLargestHorizontalProduct(grid);
  if(tempLargest > largestProduct)
    largestProduct = tempLargest;
  printf("\n");
  tempLargest = findLargestVerticalProduct(grid);
  if(tempLargest > largestProduct)
    largestProduct = tempLargest;
  printf("\n");
  tempLargest = findLargestDiagonalProduct(grid);
  if(tempLargest > largestProduct)
    largestProduct = tempLargest;

  return largestProduct;
}

long findLargestHorizontalProduct(int grid[N][N])
{
  long  largestProduct = 0;

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N - M + 1; j++)
    {
      long tempProduct = 1;
      for(int k = 0; k < M; k++)
        tempProduct *= grid[i][j + k];
      if(tempProduct > largestProduct)
        largestProduct = tempProduct;
      printf("%8ld\tlong\t%ld\n", tempProduct, largestProduct);
    }
  }

  return largestProduct;
}

long findLargestVerticalProduct(int grid[N][N])
{
  long  largestProduct = 0;

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N - M + 1; j++)
    {
      long tempProduct = 1;
      for(int k = 0; k < M; k++)
        tempProduct *= grid[j + k][i];
      if(tempProduct > largestProduct)
        largestProduct = tempProduct;
      printf("%8ld\tlong\t%ld\n", tempProduct, largestProduct);
    }
  }

  return largestProduct;
}

long findLargestDiagonalProduct(int grid[N][N])
{
  long  largestProduct = 0;

  for(int i = 0; i < N - M + 1; i++)
  {
    for(int j = 0; j < N - M + 1; j++)
    {
      long tempProduct = 1;
      for(int k = 0; k < M; k++)
        tempProduct *= grid[i + k][j + k];
      if(tempProduct > largestProduct)
        largestProduct = tempProduct;
      printf("%8ld\tlong\t%ld\n", tempProduct, largestProduct);
    }
  }
  printf("\n");

  for(int i = 0; i < N - M + 1; i++)
  {
    for(int j = N - 1; j > M - 1; j--)
    {
      long tempProduct = 1;
      for(int k = 0; k < M; k++)
        tempProduct *= grid[i + k][j - k];
      if(tempProduct > largestProduct)
        largestProduct = tempProduct;
      printf("%8ld\tlong\t%ld\n", tempProduct, largestProduct);
    }
  }

  return largestProduct;
}
