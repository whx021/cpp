#include "max.h"

void find_max(int* arr, int length)
{
    int max = 0;
    for (int i = 0; i < length; ++i)
    {
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }
    cout << "max value of array is " << arr[max] << endl;
}