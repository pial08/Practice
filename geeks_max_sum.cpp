// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 1;

	for (int i = 0; i < size; i++)
	{
	    cout << max_so_far << " start " << max_ending_here << endl;
		max_ending_here = max_ending_here * a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if /*(max_ending_here < 0) */((a[i+1] > 0 && max_ending_here < 0) || a[i] == 0)
			max_ending_here = 1;
        cout << max_so_far << " end " << max_ending_here << endl;
	}
	return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-5, -2, 2, -30};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}

