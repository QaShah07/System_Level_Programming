#include <bits/stdc++.h>
using namespace std;

// Self use terminology
#define ll long long
#define ld long double
#define F first
#define S second

using state = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

// Global variables (if any)
ll n;
ll arr[3003];
ll dp[3003][3003];
ll rec(ll l, ll r)
{
	// pruning

	// base case
	if(l==r) return arr[l];
	if(l>r) return 0;
	// Cache check
	if(dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	// Compute/Transition
	ll ans = max(arr[l]-rec(l+1,r),arr[r]-rec(l,r-1));

	// Save and Return
	return dp[l][r] = ans;
}

void solve() {
    // Input section
    cin>>n;
    for(ll i=0;i<n;i++)
    {
    	cin>>arr[i];
    }

    // Logic section
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t_ = 1;
    // cin >> t_;
    for (int i = 0; i < t_; i++) {
        solve();
    }

    return 0;
}