#include <iostream>
using namespace std;

void exchange(void) {
    int num = 10;
    int array[num];
    for (int i = 0; i < num; ++i) {
        cin >> array[i];
    }
    int min = 0;
    int max = 0;

    for (int i = 0; i < num; ++i) {
        if (array[min] > array[i]) {
            min = i;
        }
    }
    int temp;
    temp = array[0];
    array[0] = array[min];
    array[min] = temp;
    
    for (int i = 0; i < num; ++i) {
        if (array[max] < array[i]) {
            max = array[i];
        }
    }
    temp = array[num - 1];
    array[num - 1] = array[max];
    array[max] = temp;

    for (int i = 0; i < num; ++i) {
        cout << array[i] << '\t';
    }
}

int main(void) {
    exchange();

    return EXIT_SUCCESS;
}