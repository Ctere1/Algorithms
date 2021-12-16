#include <iostream>
using namespace std;

int result = 1;
int complete = 0;

void firstRule(int *num1, int *num2);
void secondRule(int *num1, int *num2);
void thirdRule(int *num1, int *num2);
void fourthRule(int *num1, int *num2);
void fifthRule(int *num1, int *num2);

/*
 It is an algorithm that finds the greatest common divisor of 2 non-negative integers,
 both of which are not equal to zero, by modifying the Eucild algorithm.
 • Rule 1: If a and b are even, GCD(2a, 2b)=2.GCD(a,b)
 • Rule 2: if a even b odd GCD(2a,b)=GCD,b)
 • Rule 3: GCD(a,0)=a
 • Rule 4: If a≥b GCD(a,b)=GCD(b, a-b)
 • Rule 5: GCD(a, b)=GCD(b, a)

 Input: 60
        50
 Output: 1. Rule
         2. Rule
         5. Rule
         4. Rule
         4. Rule
         2. Rule
         4. Rule
         3. Rule
         10
*/

int main()
{
    int num1;
    int num2;
    cin >> num1;
    cin >> num2;
    if (num1 == 0 && num2 == 0)
    {
        return 0;
    }
    if (num1 && num2 < 0)
    {
        return 0;
    }

    while (complete == 0)
    {
        if (num1 % 2 == 0 && num2 % 2 == 0)
        {
            firstRule(&num1, &num2);
        }
        else if (num1 % 2 == 0 && num2 % 2 != 0)
        {
            secondRule(&num1, &num2);
        }
        else if (num1 == 0 || num2 == 0)
        {
            thirdRule(&num1, &num2);
        }
        else if (num1 >= num2)
        {
            fourthRule(&num1, &num2);
        }
        else
        {
            fifthRule(&num1, &num2);
        }
    }
    cout << result;
    return 0;
}

void firstRule(int *num1, int *num2)
{
    cout << "1. Rule" << endl;
    result *= 2;
    *num1 = *num1 / 2;
    *num2 = *num2 / 2;
}
void secondRule(int *num1, int *num2)
{
    cout << "2. Rule" << endl;
    *num1 = *num1 / 2;
}
void thirdRule(int *num1, int *num2)
{
    cout << "3. Rule" << endl;
    if (*num1 == 0)
    {
        result *= *num2;
    }
    else
    {
        result *= *num1;
    }
    complete = 1;
}
void fourthRule(int *num1, int *num2)
{
    cout << "4. Rule" << endl;
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp - *num1;
}
void fifthRule(int *num1, int *num2)
{
    cout << "5. Rule" << endl;
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}