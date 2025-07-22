#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// function for calculating binpow in TC: O(logN)

ll binpow(ll a, ll b, ll mod)
{
	if(b==0)
	{
		return 1;
	}
	if(b%2)
	{
		return a*binpow(a,b-1,mod)%mod;
	}
	else
	{
		ll temp = binpow(a,b/2, mod);
		return temp*temp%mod;
	}
}

// 
signed main()
{
	ll a, b;
	cin>>a>>b;
	cout<<binpow(a,b,1e9+7);
	return 0;
}