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
int n;
int w[3003];
int v[3003];
int W;
// rec funtion
int dp[3003][3003];
int rec(int i, int x)
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
	// Transition
	int ans = 0;
	// for not take case
	ans = rec(i+1,x);
	if(w[i]<=x)
	{
		ans = max(ans,rec(i,x-w[i])+v[i]);
	}
	// save and return 
	return dp[i][x] = ans;
}
void solve() {
    // Input section
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
    	cin>>v[i];
    }
    cin>>W;
    memset(dp,-1,sizeof(dp));

    // Logic section
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