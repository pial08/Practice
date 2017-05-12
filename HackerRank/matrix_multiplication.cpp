#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int matmul(int* mat, int l, int r)
{
    if(l == r)
        return 0;

    int sum, min = INT_MAX;
    //cout << "hati\n";
    for(int i = l; i < r; i++)
    {
        sum = matmul(mat, l, i) +
                matmul(mat, i + 1, r) +
                mat[l - 1] * mat[i] * mat[r];
        //cout << sum << endl;
        if(sum < min)
            min = sum;

    }

    return min;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << matmul(arr, 1, len - 1);
    return 0;
}
