/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int digits_sum(string x)
{
	int result = 0;
	for(int i =0;x[i];i++)
	{
		result += x[i] - '0';
	}
	return result%10;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x = t*10;
		x += (10-digits_sum(to_string(t)));
		cout<<x<<"\n";
	}
}

