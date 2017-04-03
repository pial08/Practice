#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int max(int a, int b){return (a > b)? a: b;}

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

int main()
{
    string pal = "GEEKS FOR GEEKS";
    //cout << pal.length();

    cout << "Longest palindromic subsequence is " <<  lps(pal, 0, pal.length()-1) << endl;;

    return 0;
}
