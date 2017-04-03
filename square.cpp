#include <stdio.h>
#include <iostream>

using namespace std;

int calculatesquares(int n, int m)
{
	int result = 0;     // n should be ggreater
    if(n<m)
        swap(n,m);

	while(true)
	{
        result += n/m;
        int rem = n%m;
        n = m;
        m = rem;
        if(rem == 0)
            break;
	}
	return result;
}

int main()
{
	int n,m;
	cin >> n >> m;

	cout << calculatesquares(n,m) << endl;

	return 0;
}
