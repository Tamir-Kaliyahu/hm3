#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "isort.h"

void shift_element(int *arr, int i)
{
    int tempint;
    int *Pint;
    for (int j = i-1; j >=0 ; j--)
    {
        tempint=*(arr+j);
        Pint=&*(arr+j+1);
        *Pint=tempint;
    }
}

void insertion_sort(int *arr,int len)
{
    if(len>1)
        for (int i = 1; i < len; i++)
        {
            //printf("arr+i is: %d \n", *(arr+i));
            for (int j =0; j <=i-1 ; j++) {

                if((*(arr+i))<*(arr+j))// if( arr[i]>arr[i-1]
                {
                    int temporary=0;
                    temporary = *(arr+i);
                    shift_element(&*(arr+j),(i-j));
                    *(arr+j)=temporary;

                }

            }

        }
}


