#include <stdio.h>
#include <stdlib.h>
#define N 1000000

typedef struct linkedlist {
    unsigned long long value;
    int length;
    struct linkedlist * next;
} node;


int main()
{
    node * linkedlist;
    int maxLength = 0;
    unsigned long long maxValue = 0;
    for(unsigned long long i = 1; i < N; i++) {
        int length = 0;
        unsigned long long num = i;
        while(num > 1) {
            if(num % 2 == 0)
                num = num / 2;
            else
                num = 3 * num + 1;  
            length++;
            if(num < i) {
                node * node = linkedlist;
                while(node->value != num)
                    node = node->next;
                length += node->length;
                num = 1;
            }
        }
        node * new = malloc(sizeof(node));
        new->value = i;
        new->length = length;
        new->next = linkedlist;
        linkedlist = new;
        if(length > maxLength) {
            maxLength = length;
            maxValue = i;
        }
        if(i % 10000 == 0)
            printf("%lld\n", i);
    }
    printf("Max Value: %lld - Length: %d\n", maxValue, maxLength);
    return 0;
}