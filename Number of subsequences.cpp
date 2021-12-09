#include <iostream>
#include <chrono>

using namespace std;

int o_n_squared_alg(int arr[], int size)
{
	/*
	1,2,5,3,6,7,3,3,7,0,3,4,9,7,8
	Given an array with n elements, each term being a digit. This sequence starts with 3, ends with 7, and
	We want to find the number of subsequences of consecutive terms. For example this array's result is 8.
	3,6,7
	3,6,7,3,3,7
	3,6,7,3,3,7,0,3,4,9,7
	3,3,7
	3,3,7,0,3,4,9,7
	3,7
	3,7,0,3,4,9,7
	3,4,9,7
	*/
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 3)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] == 7)
				{
					total++;
				}
			}
		}
	}

	return total;
	// Algorithm running in O(n)^2 time.
}
int o_n_alg(int arr[], int size)
{
	/*
	First need to check is it started from three ?
	Then need to calculate the number of sevens and threes (but don't forget the reset seven count when multiply proccess finished)
	After that need to multiply seven count and three count and add up the 'total'.
	*/
	int total = 0;
	int three_count = 0;
	int seven_count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 3)
		{
			three_count++;
		}
		else if (arr[i] == 7)
		{
			if (three_count != 0)
			{
				seven_count++;
				total += three_count * seven_count;
			}
			seven_count = 0;
		}
	}
	return total;
	// algorithm running in O(n) time
}
int main()
{
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::milliseconds;

	int size = 1000000;
	int *array = new int[size];
	int ans_n_squared;
	int ans_n;

	for (int i = 0; i < size; i++) // Get it from the input.txt file.
		cin >> array[i];

	auto t1 = high_resolution_clock::now();
	ans_n_squared = o_n_squared_alg(array, size);
	auto t2 = high_resolution_clock::now();

	auto t3 = high_resolution_clock::now();
	ans_n = o_n_alg(array, size);
	auto t4 = high_resolution_clock::now();

	auto time_o_n_squared = duration_cast<milliseconds>(t2 - t1);
	auto time_o_n = duration_cast<milliseconds>(t4 - t3);

	cout << "O(n'2) result:" << ans_n_squared << endl;
	cout << "O(n) result:" << ans_n << endl;
	if (time_o_n_squared.count() > 1000 * time_o_n.count()) // For an array with 1 million elements, the O(n)^2 algorithm will take much more time than the O(n) algorithm.
		cout << "O(n) works much faster.";
	else
		cout << "o(n) does not work fast enough";
}