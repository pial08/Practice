#include <stdio.h>
#include <iostream>

using namespace std;

int A[100], B[100], C[200];

int main()
{
    freopen("input2.txt", "r+", stdin);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> B[i];
    }

    for(int i = 0;i<2*n;i++)
    {
        cin >> C[i];

    }
    int counter1 = 0, counter2 = 0;
    for(int i=0;i<2*n;i++)
    {
        if(C[i] == A[counter1])
        {
            counter1++;
        }
        if(C[i] == B[counter2])
        {
            counter2++;
        }

    }
    cout << counter1 << " *** " << counter2 << endl;
    if(counter1 + counter2 == 2*n)
        cout << "matched\n";
    else
        cout << "not matched\n";
    return 0;
}
