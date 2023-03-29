#include "min.h"

void find_min(int* arr, int length)
{
    int min = 0;
    for (int i = 0; i < length; ++i)
    {
        if (arr[min] > arr[i])
        {
            min = i;
        }
    }
    cout << "min value of array is " << arr[min] << endl;
}