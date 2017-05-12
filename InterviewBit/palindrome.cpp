#include <stdio.h>
#include <iostream>

using namespace std;

int isPalindrome(string A) {

    int len = A.length();
    cout << "main length is " << len << endl;
    string temp = "";
    for(int i = 0; i < len ; i++)
    {
        //cout << A[i] ;

        if(isalnum(A[i]))
        {
            temp.push_back(tolower(A[i]));
            //cout << "boo\n";
        }
    }
    cout << temp;

    int n = temp.length() -1;
    cout << "len is " << n << endl;
    for(int i = 0; i <= n / 2; i++)
    {
        cout << temp[i] << " * " << temp[n-i] << endl;
        if(temp[i] != temp[n - i])
            return 0;
    }
    return 1;



}

int main()
{
    cout << isPalindrome("A man, a plan, a canal: Panama");
    return 0;

}
