#include <iostream>
using namespace std;
#include "sort.h"
#include "max.h"
#include "min.h"

int main(void)
{
    int arr[] = {7, 5, 3, 2, 9, 4, 1};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    cout << "before sort" << endl;
    for (int i = 0; i < arr_len; ++i)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    sort(arr, arr_len);

    cout << "after sort" << endl;
    for (int i = 0; i < arr_len; ++i)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    find_min(arr, arr_len);

    find_max(arr, arr_len);

    return EXIT_SUCCESS;
}