#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int max(int a, int b)
{
	return (a<b)? b : a;
}

int dp[100][100];

int lcsdp(char* a, char* b, int m, int n)
{
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int lcs(char *a, char *b, int l1, int l2)
{
	if(l1 == 0 || l2 == 0)
		return 0;
	else if(a[l1-1] == b[l2-1])
		return 1 + lcs(a,b,l1-1,l2-1);

	else
		return max(lcs(a,b,l1-1,l2), lcs(a,b,l1,l2-1));

}

int main()
{
	char a[] = "AGGTAB";
	char b[] = "GXTXAYB";
	cout << lcs(a,b,strlen(a), strlen(b)) << endl;
	cout << lcsdp(a,b,strlen(a), strlen(b)) << endl;
	return 0;
}
