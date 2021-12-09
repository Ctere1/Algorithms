#include <iostream>

using namespace std;

/*
* C++ code that combines similarly to the MERGE function of the Merge Sort algorithm
* and assigns 16 decreasing integers to an array and prints the result.
* Example Input:
    16 11 10 1
    15 13 12 8
    19 5 4 2
    22 20 18 3
* Output:
    22 20 19 18 16 15 13 12 11 10 8 5 4 3 2 1
*/

int *merge(int *arr1, int *arr2, int size)
{
    int *arr = new int[2 * size];
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while (i < size && j < size)
    {
        if (arr1[i] >= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    return arr;
}
int *getNumbersIntoArray(int size)
{
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    return array;
}
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}
int main()
{
    const int SIZE = 4;

    int *arr1 = new int[SIZE];
    int *arr2 = new int[SIZE];
    int *arr3 = new int[SIZE];
    int *arr4 = new int[SIZE];

    int *arr12 = new int[2 * SIZE];
    int *arr34 = new int[2 * SIZE];

    int *reverseSequence = new int[4 * SIZE];

    arr1 = getNumbersIntoArray(SIZE);
    arr2 = getNumbersIntoArray(SIZE);
    arr3 = getNumbersIntoArray(SIZE);
    arr4 = getNumbersIntoArray(SIZE);

    arr12 = merge(arr1, arr2, SIZE);
    arr34 = merge(arr3, arr4, SIZE);

    reverseSequence = merge(arr12, arr34, 2 * SIZE);

    printArray(reverseSequence, 4 * SIZE);
}