#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int lis(string str1, string str2, int len1, int len2)
{
    int dp[100][100];
    cout << len1 << " " << len2 << endl;

    for(int i = 0; i <= len1; i++)
    {
        for(int j = 0; j <= len2; j++)
        {
            //if(i == 0 || j == 0)
                //dp[i][j] = 0;
            if(!i)  dp[i][j] = j;
            else if(!j)  dp[i][j] = i;

            else if(str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }

        }
    }
    return dp[len1][len2];

}

int main()
{

    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    cout << lis(str1, str2, str1.length(), str2.length());

    return 0;
}
