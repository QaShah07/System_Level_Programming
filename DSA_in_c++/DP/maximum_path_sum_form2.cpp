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
int n,m;
vvi arr;
int dp[1001][1001];
int rec(int r, int c)
{
	// pruning
	 if(r<0 || c<0)
	 {
	 	return -1e9;
	 }
	// base case
	 if(r==0 & c==0)
	 {
	 	return arr[0][0];
	 }
	// cache check
	 if(dp[r][c]!=-1)
	 {
	 	return dp[r][c];
	 }
	// Compute / Transition
	 int ans = -1e9;
	 if(r!=0)
	 {
	 	ans = max(ans,rec(r-1,c)+arr[r][c]);
	 }
	 if(c!=0)
	 {
	 	ans = max(ans, rec(r,c-1)+arr[r][c]);
	 }
	// Save and return 
	 return dp[r][c] = ans;
}
void solve() {
    // Input section
    cin>>n>>m;
    arr.resize(n,vi(m));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>arr[i][j];
    	}
    }
    memset(dp,-1,sizeof(dp));
    // Logic section
    cout<<rec(n-1,m-1);

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