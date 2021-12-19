#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
 From the user; First, a program that takes n positive integers that will determine the size of the array, then takes
 n positive integers, sorts these numbers from smallest to largest using the 3 algorithms (Insertion Sort, Merge Sort
 , Quick Sort), and compares their times.
*/

void print(int arr[], int size);

void insertion_sort(int arr[], int size);
void merge_sort(int arr[], int l, int r, int size);
void quick_sort(int arr[], int low, int high, int size);

int partition(int array[], int low, int high);
void swap(int *a, int *b);

int main()
{
    int size;
    cin >> size;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    auto t1 = high_resolution_clock::now();
    insertion_sort(array, size);
    // cout << "Insertion Sort: \n";
    // print(array, size);
    auto t2 = high_resolution_clock::now();

    auto t3 = high_resolution_clock::now();
    merge_sort(array, 0, size - 1, size);
    // cout << "Merge Sort: \n";
    // print(array, size);
    auto t4 = high_resolution_clock::now();

    auto t5 = high_resolution_clock::now();
    quick_sort(array, 0, size - 1, size);
    // cout << "Quick Sort: \n";
    // print(array, size);
    auto t6 = high_resolution_clock::now();

    auto time_insertion_sort = duration_cast<nanoseconds>(t2 - t1);
    auto time_merge_sort = duration_cast<nanoseconds>(t4 - t3);
    auto time_quick_sort = duration_cast<nanoseconds>(t6 - t5);

    if (time_insertion_sort.count() < time_merge_sort.count() && time_quick_sort.count())
    {
        cout << "Fastest: Insertion";
    }
    else if (time_merge_sort.count() < time_insertion_sort.count() && time_quick_sort.count())
    {
        cout << "Fastest: Merge";
    }
    else if (time_quick_sort.count() < time_insertion_sort.count() && time_merge_sort.count())
    {
        cout << "Fastest: Quick";
    }
}

void insertion_sort(int arr[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = arr[step];
        int j = step - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void merge_sort(int arr[], int l, int r, int size)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m, size);
        merge_sort(arr, m + 1, r, size);

        int n1 = m - l + 1;
        int n2 = r - m;

        int arr1[n1], arr2[n2];

        for (int i = 0; i < n1; i++)
            arr1[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            arr2[j] = arr[m + 1 + j];

        int i, j, k;
        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
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
        while (i < n1)
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
}

void quick_sort(int arr[], int low, int high, int size)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1, size);
        quick_sort(arr, pi + 1, high, size);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}