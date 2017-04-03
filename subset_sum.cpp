#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <set>

using namespace std;

int result[100];

string dec2Bin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return dec2Bin(number / 2) + "0";
    else
        return dec2Bin(number / 2) + "1";
}

int bin2Dec(string number)
{
    int result = 0, pow = 1;
    for ( int i = number.length() - 1; i >= 0; --i, pow <<= 1 )
        result += (number[i] - '0') * pow;

    return result;
}

string make_perfect_binary(string bin, int len)
{
    int n = bin.length();
    string str = "";
    int sub = len - n;
    for(int i=0;i<sub;i++)
    {
        str += "0";
    }
    str += bin;
    return str;

}



int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int n_set = pow(2,n);
    int sum = 0;
    set<int> s;

    for(int i=0;i<n_set;i++)
    {
        string bin = dec2Bin(i);
        bin = make_perfect_binary(bin,n);
        for(int i=0;i<n;i++)
        {
            if(bin[i] == '1')
            {
                sum += arr[i];
            }
        }
        //result[i-1] = sum;
        s.insert(sum);
        sum = 0;

    }
    set<int> :: iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout << *it << " ";

    }
    cout << endl;
    //string bin = dec2Bin(1);
    //cout << make_perfect_binary(bin,n);
    //cout << n_set;
    return 0;
}
