#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void swap(char a1[], char a2[]);
void reverseString(char *x, int begin, int end);
void findSum(char str1[], char str2[]);

int main()
{
  FILE *fp;
  char file_name[] = "13-LargeSumTextFile.txt";

  fp = fopen(file_name, "r");

  if (fp == NULL)
  {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  char total[N];
  fgets(total, N, fp);
  for(int i = 0; i < N; i++) {
    if(total[i] < 48 || total[i] > 57)
      total[i] = 0;
  }
  char str[N];
  while (fgets(str, N, fp) != NULL) {
    for(int i = 0; i < N; i++) {
      if(str[i] < 48 || str[i] > 57)
        str[i] = 0;
    }
    findSum(total, str);
  }

  fclose(fp);

  printf("%s\n", total);
  return 0;
}

void findSum(char str1[], char str2[]) {
  if (strlen(str1) > strlen(str2))
    swap(str1, str2);
  int n1 = strlen(str1),
      n2 = strlen(str2);
  reverseString(str1, 0, n1 - 1);
  reverseString(str2, 0, n2 - 1);

  char str[N];
  int carry = 0;
  for (int i = 0; i < n1; i++) {
      int sum = str1[i] + str2[i] + carry - (2 * '0');
      str[i] = sum % 10 + '0';
      carry = sum / 10;
  }
  for(int i = n1; i < n2; i++) {
      int sum = str2[i] + carry - '0';
      str[i] = sum % 10 + '0';
      carry = sum / 10;
  }
  int length = n2;
  if(carry) {
    str[n2] = carry + '0';
    length++;
  }
  reverseString(str, 0, length - 1);
  str[length] = 0;
  swap(str, str1);
}

void reverseString(char *x, int begin, int end)
{
  if (begin >= end)
    return;
  
  char temp = x[begin];
  x[begin] = x[end];
  x[end] = temp;

  reverseString(x, begin + 1, end - 1);
}

void swap(char a1[], char a2[])
{
  int length = (strlen(a2) > strlen(a1)) ? strlen(a2) : strlen(a1);
  for(int i = 0; i < length + 1; i++) {
    char tmp = a1[i];
    a1[i] = a2[i];
    a2[i] = tmp;
  }
}