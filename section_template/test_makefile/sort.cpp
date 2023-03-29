#include "sort.h"


void sort(int* arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        int min = i;
        for (int j = i; j < length; ++j)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}