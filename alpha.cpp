#include <bits/stdc++.h>
#define FR0(i,N) for(i=0;i<(N);i++)
#define FR1(i,N) for(i=1;i<=(N);i++)
#define FRN(i,k,N) for(i=k;i<(N);i++)
#define pf printf
#define db double
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)

#define sci(n) scanf("%d",&n)
#define scf(n) scanf("%f",&n)
#define scd(n) scanf("%lf",&n)
#define scs(s) scanf("%s",&s)
#define scll(n) scanf("%%I64d",&n)





using namespace std;
int X_D[9] = { 0, -1, -1, -1, 0, 1, 1,  1};
int Y_D[9] = {-1, -1,  0,  1, 1, 1, 0, -1};
int bin_0_9[]= {0,1,1,2,1,1,2,3,1,1};
int month[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
string day_0_7[]= {"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
string ans[13][32];
typedef long long LL;
int prime[1000001];

// Utility functions to get minimum of two integers
int min (int x, int y) {return x < y? x : y; }

// Utility functions to get maximum of two integers
int max (int x, int y) {return x > y? x : y; }

vector<string>per;
bool cmp(char a,char b)
{
    if(tolower(a)==tolower(b))
    {
        return a<b;
    }
    return tolower(a)<tolower(b);
}
int main()
{

    int t;
    sci(t);
    int i;
    getchar();
    FR1(i,t)
    {
        string s;
        int cnt=0;
        per.clear();
        cin>>s;
        sort(s.begin(),s.end(),cmp);
        do{
               cout<<s<<endl;
        }
        while(std::next_permutation(s.begin(),s.end(),cmp));


    }

}
