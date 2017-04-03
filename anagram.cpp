#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;



bool compare(const char &a,const char &b)
{
    if(tolower(a) == tolower(b))
    {
        return a<b;

    }

    return tolower(a) < tolower(b);
}


int main()
{
	int n;
	string input;

	cin >> n;


	while(n--)
	{
    //for(int i=0; i<11; i++) v.push_back( i );

   		cin >> input;
   		//int len = strlen(input);
   		//cout << input <<endl << endl;

   		sort(input.begin(), input.end(),compare);

	    do {
	        // protitat jama prottekke porai dekho shukh maximize hochche kina
	        cout << input << endl;
	        //v.push_back(input);
	    }while( next_permutation(input.begin(), input.end(), compare));


	}

}
