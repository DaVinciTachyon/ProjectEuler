#include<stdio.h>

double calculateLatticePaths(int, int);

int main()
{
    int dimensions[2];
    printf("What is the first dimension?\n\t");
    scanf("%d", &dimensions[0]);
    printf("What is the second dimension?\n\t");
    scanf("%d", &dimensions[1]);
    double result = calculateLatticePaths(dimensions[0], dimensions[1]);
    printf("The number of lattice paths is %.0lf.\n", result);
    return 0;
}

double calculateLatticePaths(int dimension1, int dimension2)
{
    if(dimension1 == 0 && dimension2 == 0)
        return 1;
    double result = 0;
    double first;

    if(dimension1 > 0) {
        first = calculateLatticePaths(dimension1 - 1, dimension2);
        result += first;
    }
    if(dimension1 - 1 == dimension2 - 1 && dimension2 == dimension1)
        result += first;
    else if(dimension2 > 0)
        result += calculateLatticePaths(dimension1, dimension2 - 1);

    return result;
}