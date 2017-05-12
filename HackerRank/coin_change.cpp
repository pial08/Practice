#include <stdio.h>
#include <iostream>

using namespace std;

int sum(int* coin, int len, int sum)
{
    int dp[sum + 1][len];
    for(int i = 0; i < len; i++)
    {
        dp[0][i] = 1;
    }
    int x, y;
    for(int i = 1; i < sum + 1; i++)
    {
        for(int j = 0; j < len; j++)
        {

            x = (i - coin[j] >= 0)? dp[i - coin[j]][j] : 0;
            y = (j >= 1)? dp[i][j - 1] : 0;
            dp[i][j] = x + y;
        }
    }
    return dp[sum][len - 1];
}

int main()
{
    int coin[] = {1, 2, 3};
    int len = sizeof(coin) / sizeof(coin[0]);
    int su = 4;
    cout << sum(coin, len, su) << endl;

    return 0;
}
