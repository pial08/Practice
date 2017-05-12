#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int xorP(vector<int> &A)
{
    int len = A.size();
    cout << "length is " << len << endl;
    int min = 2000000000;
    sort(A.begin(), A.end());


    for(int i = 0; i < len -1 ; i++)
    {
        cout << A[i] << " value of i " << i << endl;
        if(min > (A[i] ^ A[i+1]))
        {
            min = (A[i] ^ A[i+1]);
            cout << min << endl;
        }
    }
    return min;

}

int main()
{
    vector <int> A = {2,4,2};
    //cout << xorP(v);
    int a = 7;
    //cout << (a >>= 1);
    //int a = 150;

    int len = A.size();
    int result = A[0];
    for(int i = 1; i < len ; i++)
    {
        result = A[i] ^ result;
    }
    cout << result;

    return 0;
}
