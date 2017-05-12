#include <stdio.h>
#include <iostream>

using namespace std;

int count_ones(int A)
{
    int counter = 0;
    unsigned int temp;
    while(A)
    {
        //temp = 1;
        counter += A & 1;
        A >>= 1;
        //counter += temp;




    }
    //cout << counter << endl;
}

int search(int* A, int B, bool flag, int len)
{
    int left = 0, right = len - 1;
    int result = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(A[mid] == B)
        {
            result = mid;
            //cout << result << " ";
            //return mid;
            if(flag)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
                //cout << " hati";
            }

        }
        else if(B < A[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return result;
}


int main()
{
    //count_ones(10);
    int arr[] = {4, 7, 7, 7, 8, 10, 10};
    //int arr[] = { 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int x = search(arr, 5, false, len);
    int y = search(arr, 5, true, len);
    cout << x << " " << y << y - x + 1 <<  endl;

    string str = "pial";
    string temp = "";
    for(int i = 0; i < str.length(); i++)
    {
        temp.push_back(str[i]);

    }
    cout << temp;
    return 0;
}
