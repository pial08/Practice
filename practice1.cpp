#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<vector<vector<bool> > > dp;
vector<int> res;
vector<int> original;
int total_size;

bool possible(int index, int sum, int sz) {
    if (sz == 0) return (sum == 0);
    if (index >= total_size) return false;

    if (dp[index][sum][sz] == false) return false;

    if (sum >= original[index]) {
        res.push_back(original[index]);
        if (possible(index + 1, sum - original[index], sz - 1))
        {
            cout << original[index] << " ";
            return true;
        }
        res.pop_back();
    }

    if (possible(index + 1, sum, sz)) return true;

    return dp[index][sum][sz] = false;
}


bool subarraypartition(vector <int> arr, int len, int sum, int limit)
{
    //cout << "limit " << limit << endl;
    if(limit == 0)
    {
        if(sum == 0)
            cout << "sum found in limit\n";
        return (sum == 0);
    }


    if(sum == 0)
    {
        //counter++;
        cout << "sum found\n";
        return true;
    }
    if(len == 0 && sum != 0)
        return false;
    if(arr[len - 1] > sum)
        return subarraypartition(arr, len - 1, sum, limit);
    else
    {
        bool a, b;
        a = subarraypartition(arr, len - 1, sum, limit);
        b = subarraypartition(arr, len - 1, sum - arr[len - 1], limit - 1);
        if(b)
        {
            cout << arr[len - 1] << endl;
            //temp.push_back(arr[len - 1]);
        }
        return a || b;
    }


}


int calculate(vector <int> v, int len, int sum, int limit)
{
    if(limit == 0)
    {
        //cout << endl;
        return (sum == 0);
    }
    /*if(sum == 0)
    {
        cout << endl;
        return 1;
    }
    */
    if(sum != 0 && len == 0)
        return 0;
    if(v[len - 1] > sum)
        return calculate(v, len - 1, sum, limit);
    else
    {
        int a = calculate(v, len - 1, sum, limit);
        int b = calculate(v, len - 1, sum - v[len - 1], limit - 1);
        if(b)
        {
            cout << v[len - 1] << " ";
        }
        return a + b;
    }
}

int main()
{

    original = {47, 14, 30, 19, 30, 4, 32, 32, 15, 2, 6, 24};
    int limit = 4;
    sort(original.begin(), original.end(), greater<int>());
    int total_sum = 0;
    for(int i = 0; i < original.size(); i++)
    {
        cout << original[i] << " ";
        total_sum += original[i];
    }
    cout << endl;

    /*total_size = original.size();
    sort(original.begin(), original.end());
    int total_sum = 0;
    for(int i = 0; i < original.size(); i++)
    {
        cout << original[i] << " ";
        total_sum += original[i];
    }
    cout << endl;
    cout << total_size << endl;

    dp.resize(original.size(), vector<vector<bool> > (total_sum + 1, vector<bool> (total_size, true)));
    possible(0, 85, limit);

    */
    subarraypartition(original, original.size(), 85,  limit);

    //int r = bombs(v, v.size(), R);
   // cout <<  endl << r << endl;


}
