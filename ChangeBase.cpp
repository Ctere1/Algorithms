#include <iostream>

using namespace std;

/*
* C++ code that can calculate the number of a'n with the following algorithm
* by taking the positive integers a and n from the user (0<a<=10, 0<n<=10).
  Algorithm:
  1. Write the number n in base 2.
  2. Initially, let the product be = 1.
  3. Scan the numbers of the base 2 software of n from left to right and square the product when you see 1,
  4. Multiply by a and assign the result to the product. When you see 0, square the product.
* Example Input : 3 7
  Output: 111
          1
          3
          27
          2187
*/
void algorithm(int ceiling, int floor);

int main()
{
    int floor;
    int ceiling;
    cin >> floor;
    cin >> ceiling;
    if (floor && ceiling > 10)
    {
        cout << "Enter numbers between 1 and 10";
        return 0;
    }
    algorithm(ceiling, floor);
    return 0;
}

void algorithm(int ceiling, int floor)
{
    int i = 0;
    int arr[4];
    int p = 1;
    while (ceiling > 0)
    {
        arr[i] = ceiling % 2;
        ceiling = ceiling / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        cout << arr[j];
    }

    for (int j = i - 1; j >= -1; j--)
    {
        cout << endl
             << p;
        if (arr[j] == 1)
        {
            p = (p * p) * floor;
        }
        else // arr[j] == 0
        {
            p = (p * p);
        }
    }
}
