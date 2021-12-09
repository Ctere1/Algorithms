#include <iostream>

using namespace std;

/*
 Problem: There are N gates whose numbers are 1, 2 3, ..., N, respectively, and each is initially closed.
 Passing by these gates N times, action will be taken on some gates each time. Action means closing the open door,
 opening the closed door. Beside the doors k. Once passed, only the gates whose number is divisible by k will be processed.
 In other words, when passed for the 1st time, all doors will be opened (as their numbers are all divisible by one),
 when passed for the 2nd time, the ones with even numbers will be closed and N times will continue. Which doors will be
 open after the last time has passed?

* Example Input: 8
  Output: 1 4
* Example Input: 2
  Output: 1
*/
void print(char arr[], int size);

void algorithm(char arr[], int size);

int main()
{
    int size;
    cin >> size;
    char array[size];

    for (int i = 1; i <= size; i++)
        array[i] = 'C'; // Close all the doors.

    algorithm(array, size);
}

void algorithm(char arr[], int size)
{
    for (int door_number = 1; door_number <= size; door_number++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (door_number % j == 0)
            {
                if (arr[door_number] == 'O') // It is opened close it now.
                {
                    arr[door_number] = 'C';
                }
                else // Open the door.
                {
                    arr[door_number] = 'O';
                }
            }
        }
    }
    print(arr, size);
}

void print(char arr[], int size)
{
    for (int i = 1; i <= size; i++)
    {
        if (arr[i] == 'O')
        {
            cout << i << ' ';
        }
    }
}