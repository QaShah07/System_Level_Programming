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
int n,k;
int h[100010];
int dp[100010];
int rec(int i)
{
	// pruning 
	// base case
	if(i==n)
	{
		return 0;
	}
	// cache check
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	// Compute/Transition
	int res = 1e9;
	for(int j=1;j<=k;j++)
	{
		if(i + j <= n) {
            res = min(res, rec(i + j) + abs(h[i + j] - h[i]));
        }
	}
	// Save and return 
	return dp[i] = res;

}
void solve() {
    // Input section
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>h[i];
    }
    memset(dp,-1,sizeof(dp));

    // Logic section
    cout<<rec(1);
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