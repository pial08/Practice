#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;


vector < vector <int> > ans;
vector<int> original;
int total_size;
vector<vector<vector<bool> > > dp;


int counter = 0;
vector <int> temp;
vector<int> res;

bool possible(int index, int sum, int sz)
{
    cout << "hati\n";
    cout << sz << " " << sum << " " << dp[index][sum][sz] << "***";
    if (sz == 0) return (sum == 0);
    if (index >= total_size) return false;


    if (dp[index][sum][sz] == false) return false;

    if (sum >= original[index]) {
        res.push_back(original[index]);
        if (possible(index + 1, sum - original[index], sz - 1)) return true;
        res.pop_back();
    }

    if (possible(index + 1, sum, sz)) return true;

    return dp[index][sum][sz] = false;
}



int subarraysum(int* arr, int len, int sum, int limit)
{
    if(limit == 0)
        return (sum == 0);
    if(sum == 0)
        return 1;
    if(len == 0 && sum != 0)
        return 0;
    if(arr[len - 1] > sum)
        return subarraysum(arr, len - 1, sum, limit);
    else
        return subarraysum(arr, len - 1, sum, limit) + subarraysum(arr, len , sum - arr[len - 1], limit - 1);
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
        counter++;
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
            temp.push_back(arr[len - 1]);
        }
        return a || b;
    }


}


int main()
{
    vector <int> arr = {47, 14, 30, 19, 30, 4, 32, 32, 15, 2, 6, 24};

    int sum = 0;


    int len = arr.size();
    sort(arr.begin(), arr.end());
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
        sum += arr[i];
    }
    //subarraypartition(arr, len, sum);

    //sort(arr, arr + len);
    ans.clear();
    temp.clear();

    for(int i = 1; i < len; i++)
    {
        if((sum * i) % len == 0)
        {
            int si = (sum * i) / len;
            cout << "value of sum " << si << " value of i=limit " << i << endl;
            if(subarraypartition(arr, len, si, i))
            {
                //cout << "found\n";
                int n2 = len - i;
                int s2 = sum - si;
                //cout << si << " " << i << " " << s2 << " " << n2 << endl;
                if(si/i == s2/n2)
                {
                    cout << si << " " << i << " " << s2 << " " << n2 << endl;
                    cout << "got it\n";
                    int pial = 0;
                    ans.push_back(temp);
                    temp.clear();
                    for(int k = 0; k < len; k++)
                    {
                        if(find(ans[0].begin(), ans[0].end(), arr[k]) == ans[0].end())
                        {
                            //ans[1].push_back(arr[k]);
                            temp.push_back(arr[k]);
                            //cout << arr[k] << " ";

                        }
                    }
                    ans.push_back(temp);
                    temp.clear();
                    cout << endl;
                    //break;
                    for(int i = 0; i < 2; i++)
                    {
                        for(int j = 0; j < ans[i].size(); j++)
                        {
                            cout << ans[i][j] << " ";
                        }
                        cout << endl;

                    }
                    break;


                }
            }

        }
    }

    /*vector <int> Vec = {1, 2, 3, 4};
    sort(Vec.begin(), Vec.end());
    original.clear();
    original = Vec;
    dp.clear();
    res.clear();
    int total_sum = 5;
    total_size = original.size();
    dp.resize(original.size(), vector<vector<bool> > (total_sum + 1, vector<bool> (total_size, true)));
    int limit = 2;
    cout << possible(0, total_sum, limit) << endl;
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    */




    /*if(sum % 2 != 0)
        cout << "impossible\n";
    else
    {
        int res = subarraypartition(arr, len, sum / 2);
        cout << "****** " << res << " *********\n";
        if(res)
            cout << "possible\n";
        else
            cout << "impossible\n";
    }*/
    //cout << subarraypartition(arr, len, sum) << endl;

    return 0;
}
