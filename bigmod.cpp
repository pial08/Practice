#include <stdio.h>
#include <iostream>

using namespace std;

int bigmod(int a, int b, int M)
{
    if(b == 0) return 1 % M;
    int x = bigmod(a, b / 2, M);
    x = (x * x) % M;
    if(b % 2 == 1)  x = (x * a) % M;
    //return (x >= 0)? x : (M + x) % M;
    return x;

}

/*int main()
{
    //71045970
    //41535484
    //64735492

    int a, b, c;
    cin >> a >> b >> c;
    //cout << (bigmod(a, b, c) + c ) % c  << endl;
    unsigned long long int pial;

    //cout << 1 % 20 << endl;


    return 0;
}*/


#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<vector<int> > v = {
                            {1,2},
                            {3,4}
                            };
  for (const auto& inner : v) {
      for (const auto& item : inner) {
          cout << item << " ";
      }
      cout << endl;
  }
  cout << endl;

  return 0;
}


