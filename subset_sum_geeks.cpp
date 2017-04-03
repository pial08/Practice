#include <stdio.h>
#include <iostream>

using namespace std;
int s[] = {3, 34, 4, 12, 5, 2};
//************* invalid output on error sum value ******************//
bool subsetSum(int sum, int left, int right)
{
    //cout << sum << endl;
    if(sum == 0)
        return true;
    if(sum != 0 && left == right + 1)
        return false;
    if(sum - s[left] >= 0)
    {
        return subsetSum(sum - s[left], left + 1, right) || subsetSum(sum, left + 1, right);
        //subsetSum(sum - s[left], left + 1, right);
        //subsetSum(sum, left + 1, right);
    }

}

int main()
{
    int sum = 9;
    int r = sizeof(s)/sizeof(s[0]);
    cout << subsetSum(sum, 0, r-1);
    return 0;
}
