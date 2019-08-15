#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
#define M 1000

void swap(char a1[], char a2[]);
void reverseString(char *x, int begin, int end);
void findSum(char str1[], char str2[]);
int addUpDigits(char str[]);

int main()
{
  char total[N] = "2";
  char str[N];
  for(int i = 0; i < M - 1; i++) {
    strcpy(str, total);
    findSum(total, str);
  }

  printf("%s\n", total);
  printf("%d", addUpDigits(total));
  return 0;
}

int addUpDigits(char str[])
{
    int total = 0;
    int i = 0;
    while(i < N && str[i] != 0)
        total += str[i++] - '0';
    return total;
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