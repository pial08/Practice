#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int L[20][20];


// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
int n = strlen(str);
int i, j, cl;
//int L[n][n]; // Create a table to store results of subproblems


// Strings of length 1 are palindrome of lentgh 1
for (i = 0; i < n; i++)
	L[i][i] = 1;

	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cout << L[i][j] << " ";
	    }
	    cout << endl;
	}
	cout << endl << endl;

	// Build the table. Note that the lower diagonal values of table are
	// useless and not filled in the process. The values are filled in a
	// manner similar to Matrix Chain Multiplication DP solution (See
	// http://www.geeksforgeeks.org/archives/15553). cl is length of
	// substring

	int counter = 0;
	for (cl=2; cl<=n; cl++)
	{
		for (i=0; i<n-cl+1; i++)
		{
			j = i+cl-1;
			cout << i << " " << j << endl;
			counter++;
			//cout << j << " ";
			if (str[i] == str[j] && cl == 2)
			L[i][j] = 2;
			else if (str[i] == str[j])
			L[i][j] = L[i+1][j-1] + 2;
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}

	cout << "total " << counter << " loops were executed\n";

	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cout << L[i][j] << " ";
	    }
	    cout << endl;
	}

	cout << endl;

	return L[0][n-1];
}



/*
int lps(string pal, int left, int right)
{
    if(left == right)
        return 1;
    if(pal[left] == pal[right] && right == left + 1)
        return 2;
    if(pal[left] == pal[right])
        return lps(pal, left+1, right-1) + 2;

    else
        return max(lps(pal, left+1, right), lps(pal, left, right-1));


    //cout << pal;

}

*/

void lpsdp(string str)
{
    int len = str.length();
    cout << len << endl;
    for(int i = 0; i < len; i++)
        L[i][i] = 1;

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(i <= j)
            {
                if(str[i] == str[j] && j == i + 1)
                if(true)
                {
                    L[i][j] = 2;
                }
                else if(str[i] == str[j])
                {
                    L[i][j] = L[i+1][j-1] + 2;
                }
                else
                {
                    L[i][j] = max(L[i+1][j], L[i][j-1]);
                }

            }
        }
    }

    for(int i=0;i<len;i++)
	{
	    for(int j=0;j<len;j++)
	    {
	        cout << L[i][j] << " ";
	    }
	    cout << endl;
	}

	cout << endl;

}




int main()
{
    string pal = "GEEKS FOR GEEKS";
    //cout << pal.length();
    lpsdp(pal);
    cout << "Longest palindromic subsequence is " <<  endl;

    /*
    char seq[] = "GEEKS FOR GEEKS";
	int n = strlen(seq);
	printf ("The lnegth of the LPS is %d", lps(seq));

	*/

    return 0;
}
