#include <iostream>

using namespace std;

/*
*  C++ code that consists of consecutive terms of the given n-element array of integers and
*  prints descending subarrays one after the other
*/
int algorithm(int array[], int size)
{
    int min = array[0];
    int i = 0;

    for (i; i < size; i++)
    {
        if (array[i] <= min)
        {
            min = array[i];
            cout << min << " ";
        }
        else
        {
            cout << "*\n";
            min = array[i];
            cout << array[i] << " ";
        }
    }
    if (i == size)
    {
        cout << "*";
    }
}
int main()
{
    int size;
    cin >> size;
    int *array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    algorithm(array, size);
}
