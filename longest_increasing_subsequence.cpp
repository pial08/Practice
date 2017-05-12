#include <stdio.h>
#include <iostream>

using namespace std;

int lis(int* arr, int len)
{
    int dp[100];
    for(int i = 0; i < len; i++)
        dp[i] = 1;

    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i], (dp[j])+1);
            }
        }
    }
    int max = -1;
    for(int i = 0; i < len; i++)
    {
        if(dp[i] > max)
            max = dp[i];
    }
    return max;
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << lis(arr, len) << endl;
    return 0;
}
