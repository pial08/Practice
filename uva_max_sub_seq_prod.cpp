#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int max(int a, int b)
{
    return (a > b)? a:b;
}

int min(int a, int b)
{
    return (a < b)? a:b;
}

int maxProduct(int A[], int n) {
            // store the result that is the max we have found so far
            int r = A[0];

            // imax/imin stores the max/min product of
            // subarray that ends with the current number A[i]
            for (int i = 1, imax = r, imin = r; i < n; i++) {
                // multiplied by a negative makes big number smaller, small number bigger
                // so we redefine the extremums by swapping them
                if (A[i] < 0)
                    swap(imax, imin);

                // max/min product for the current number is either the current number itself
                // or the max/min by the previous number times the current one
                imax = max(A[i], imax * A[i]);
                imin = min(A[i], imin * A[i]);

                // the newly computed max value is a candidate for our global result
                r = max(r, imax);
            }
            return r;
        }

int maxProd(vector <int> &arr, int len)
{
    int maximum = -9999999;
    bool one = false;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] == 1 && !one)
            one = true;

        if(arr[i] > maximum)
            maximum = arr[i];

    }
    int max_so_far = 1;
    int max_ending_here = 1;
    int min_ending_here = 1;

    for(int i = 0; i < len; i++)
    {
        if(arr[i] > 0)
        {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(min_ending_here * arr[i], 1);

        }
        else if(arr[i] == 0)
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }
        else
        {
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];

        }

        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }


    //cout << min_ending_here << " " << max_so_far << endl;
    if(!one && max_so_far == 1)
        return maximum;
    return max_so_far;
}

int main()
{
    int input;
    vector <int> v;
    while(scanf("%d ", &input) != EOF)
    {
        //cin >> input;
        while(input != -999999)
        {
            v.push_back(input);
            cin >> input;
        }
        //cout << "result is ";
        cout << maxProd(v, v.size()) << endl;
        v.clear();

    }
    return 0;
}
