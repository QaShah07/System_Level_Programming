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
ll n, W;
ll w[101];       // weight of items
ll v[101];       // value of items
ll dp[101][100001]; 
// recurance the value
ll rec(ll i, ll x)
{
	// pruning
	// base case
	if(i==n)
	{
		return 0;
	}
	// cache check
	if(dp[i][x]!=-1)
	{
		return dp[i][x];
	}
	// transition
	ll ans = 0;
	ans = rec(i+1,x);
	if(w[i]<=x)
	{
		ans = max(ans, rec(i+1,x-w[i])+v[i]);
	}
	// save and return
	return dp[i][x] = ans;
}
void solve() {
    // Input section
	cin>>n>>W;
	for(ll i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];
	}
    // Logic section
    memset(dp,-1,sizeof(dp));
	cout<<rec(0,W);
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