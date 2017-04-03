#include<stdio.h>
#include<iostream>

using namespace std;

int fibo(int n)
{
    if(n == 0 || n == 1)
        return 1;
   
    return fibo(n-1) + fibo(n-2);
     cout << n << " ";
}

int main()
{
    cout << fibo(5) << endl;
    return 0;
}

void shit()
{
    cout << "this is shit\n";
}