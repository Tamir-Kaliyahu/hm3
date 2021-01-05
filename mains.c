#include <stdio.h>
#include "isort.h"

int main()
{
    printf("Please enter 50 numbers to fill the array: \n");
    int x = 50;
    int arr [x];
    int in;
    for (int i = 0; i < x; ++i) {
        printf("%d) pick a number",(i+1));
        scanf("%d", &in);
        *(arr+i)=in;
    }
    int *pointer;
    pointer=arr;
    insertion_sort(pointer,x);
    printf("\n sorted succesfully \n ");
    for(int i=0;i<x;i++)
    {
        printf(" %d ,", *(arr+i));
    }

    return 0;
}
