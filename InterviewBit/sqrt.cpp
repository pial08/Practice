#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;


int square_root(int A)
{

    if(A == 0 || A == 1)
        return A;

    long int start = 1, fin = A, result;
    while(!(fin < start))    // or fin >= start
    {
        long int mid = (start + fin) / 2;
        //cout << mid;

        if(mid * mid == A)
            return mid;

        if(mid * mid < A)
        {

            //cout << "hati\n";
            start = mid + 1;
            result = mid;

        }
        else
        {
            fin = mid - 1;
            //cout << "ghora\n";
        }

    }

    return result ;


}



int main()
{
    //2147483647
    int a;
    cin >> a;
    cout << square_root(a);
    //cout << sqrt1(a);
    //cout << 2147483647 - 1;
    //cout << (a+1) * -1;
    return 0;
}
