#include <stdio.h>
#include <iostream>

using namespace std;

void print(int* arr, int len)
{
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int res(int* arr, int len)
{
    int dp1[100], dp2[100];
    for(int i=0;i<len;i++)
    {
        dp1[i] = 1;
        dp2[i] = 1;
    }


    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                dp1[i] = max(dp1[j] + 1, dp1[i]);
            }
            if(arr[j] > arr[i])
            {
                dp2[i] = max(dp2[j] + 1, dp2[i]);
            }
        }
    }

    print(dp1, len);
    print(dp2, len);

    //now make a set including the values of the 2 dp variables.
    //return the length.


}

int main()
{
    int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    res(arr, len);
    return 0;
}
