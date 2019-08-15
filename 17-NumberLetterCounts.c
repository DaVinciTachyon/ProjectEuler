#include<stdio.h>

int numberNameLength(int);
int nameLength(int);

int main()
{
    int max;
    printf("What is the number you want to count to?\n\t");
    scanf("%d", &max);
    int result = 0;
    for (int i = 1; i <= max; i++) {
        result += numberNameLength(i);
    }
    printf("The number of letters is %d.\n", result);
    return 0;
}

int numberNameLength(int number)
{
    int length = 0;
    int tempNumber = number;

    if(tempNumber >= 1000) {
        length += 8;
        int temp = tempNumber;
        temp %= 100000;
        temp /= 1000;
        length += nameLength(temp);
    }
    tempNumber %= 1000;
    if(tempNumber >= 100) {
        length += 7;
        int temp = tempNumber;
        temp %= 1000;
        temp /= 100;
        length += nameLength(temp);
    }
    tempNumber %= 100;
    if(tempNumber > 0) {
        if(number >= 100)
            length += 3;
        length += nameLength(tempNumber);
    }
    
    return length;
}

int nameLength(int number)
{
    int length = 0;
    switch (number)
    {
    case 1: case 2: case 6: case 10:
        length += 3;
        break;
    case 3: case 7: case 8:
        length += 5;
        break;
    case 4: case 5: case 9:
        length += 4;
        break;
    case 11: case 12:
        length += 6;
        break;
    case 13: case 14: case 18: case 19:
        length += 8;
        break;
    case 15: case 16:
        length += 7;
        break;
    case 17:
        length += 9;
        break;
    }
    if(number >= 20 && number < 40 || number >= 80 && number < 100)
        length += 6;
    if(number >= 40 && number < 70)
        length += 5;
    if(number >= 70 && number < 80)
        length += 7;
    if(number >= 20){
        number %= 10;
        length += nameLength(number);
    }

    return length;
}