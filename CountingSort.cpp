#include <iostream>
using namespace std;

void counting_sort(int array[], int size);

int main()
{
    int size;
    cin >> size;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    counting_sort(array, size);
    return 0;
}

void counting_sort(int array[], int size)
{
    int arr[10];
    int count[10];
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        arr[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}