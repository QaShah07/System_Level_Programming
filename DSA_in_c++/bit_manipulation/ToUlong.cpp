#include<iostream>
#include<bitset>
using namespace std;
#define ll long long int
// global variable 

void solve()
{
	bitset<4>bits;
	bits.set();
	int ans = bits.to_ulong();
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
    return 0;
}
