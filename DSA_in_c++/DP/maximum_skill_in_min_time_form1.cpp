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
int t[i];
int s[i];
int x,k;
// rec funtion
int dp[101][101][101];
int rec(int i, int time_taken, int item_taken)
{
	// pruning
	// base case
	if(i==n)
	{
		return 0;
	}
	// cache check
	if(dp[i][time_taken][item_taken]!-1)
	{
		return dp[i][time_taken][item_taken];
	}
	// Transition
	int ans = 0;
	ans = rec(i+1,time_taken,item_taken);
	if(time_taken+t[i]<=x && item_taken+1<=k)
	{
		ans  =  min(ans, rec(i+1,time_taken+s[i],item_taken+1)+s[i]);
	}
	// save and return 
	return dp[i][time_taken][item_taken] = ans;
}
void solve() {
    // Input section
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>t[i];
    }
    for(int i=0;i<n;i++)
    {
    	cin>>s[i];
    }
    cin>>x>>k;
    memset(dp,-1,sizeof(dp));
    // Logic section

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