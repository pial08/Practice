#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>


using namespace std;

int used[100], number[100];

//void next_permu()

void permutation(int at, int n)
{
    if(at == n + 1)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << number[i] << " ";

        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        used[i] = 1;
        number[at] = i;
        permutation(at+1, n);
        used[i] = 0;
    }

}

void permute(string str, int l, int r)
{
    if(l == r)
        cout << str << endl;
    else
    {
        for(int i = l; i <= r; i++)
        {
            swap(str[i],str[l]);
            permute(str, l+1, r);
            swap(str[i],str[l]);
        }

    }
}

int main()
{
    //permutation(1,3);

    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);



    /*vector <int> v;
    for(int i = 0; i < 6; i++)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end());

    vector <int> :: iterator it;


    do
    {
        for(it = v.begin(); it != v.end(); it++)
            cout << *it;
        cout << endl;
    }while(next_permutation(v.begin(), v.end()));

    */


}
