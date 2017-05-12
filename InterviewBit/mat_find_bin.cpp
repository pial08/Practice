#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {

    vector <int> v;
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A[i].size(); j++)
        {
            //cout << A[i][j] << " ";
            v.push_back(A[i][j]);
        }
        //cout << endl;
    }

    int left = 0, right = v.size() - 1;
    while(left <= right)
    {
        int mid = (v[left] + v[right]) / 2;
        if(mid == B)
            return 1;

        if(B < mid)
            right = mid;
        else
            left = mid;
    }









    return 0;



}

int bs(int* A, int B, int len)
{
    int left = 0, right = len - 1 ;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(A[mid] == B)
            return mid;

        if(B < A[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;

}


int main()
{
    /*vector<vector<int> > A;
    int val;
    int row, col;
    cin >> row >> col;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int temp;
            cin >> temp;
            //A[i].push_back(temp);
        }
    }

    cout << searchMatrix(A, 41) <<  endl;
    */

    int arr[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(arr) / sizeof(arr[0]);
    //int* index = upper_bound(arr, arr+6,8);
    //cout <<  index - arr << endl;

    int x = bs(arr, 5, len);
    cout << x << endl;



    return 0;
}
