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
int x[1001];
// recursive function for
int dp[1001][1001];
int rec(int l, int r)
{
	// pruning
	// base case
	if(l+1==r)
	{
		return 0;
	}
	// cache check
	if(dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	// compute/Transition
	int ans = 1e9;
	for(int i=l-1;i<r;i++)
	{
		ans = min(ans,x[r]-x[l]+rec(l,i)+rec(i,r));
	}
	// save and return
	return dp[l][r] = ans;
}
void solve() {
    // Input section
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>x[i];
    }
    x[0] = 0;

    // Logic section
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n);
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