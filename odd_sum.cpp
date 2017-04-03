#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int ca = 1;
    int n;
    cin >> n;

    while(n--)
    {
        int x, y;
        cin >> x >> y;
        for(int i=x;i<=y;i++)
        {

            if(i%2 ==1)
            {
                sum += i;
            }
        }
        cout << "Case " << ca++ << ": "  << sum << endl;
        sum = 0;
    }
    return 0;
}
