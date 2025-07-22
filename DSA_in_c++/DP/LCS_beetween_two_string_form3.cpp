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
string a,b;
int dp[1001][1001];
int rec(int i, int j)
{
	// pruning
	// base case
	if(i>=n || j>=m)
	{
		return 0;
	}
	// Cache check
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	// Compute/Transition
	int ans = 0;
	ans = max(ans,rec(i+1,j));
	ans = max(ans,rec(i,j+1));
	if(a[i]==b[j])
	{
		ans = max(ans,rec(i+1,j+1)+1);
	}
	// Save and Return 
	return dp[i][j] = ans;

}
void solve() {
    // Input section
    cin>>n>>m;
	cin>>a>>b;
    // Logic section
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
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