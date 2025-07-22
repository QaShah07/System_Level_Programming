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
const int INF = 1e9; 

// Global variables (if any)
int n,k;
int arr[1001];
int dp[1001][1010];
int rec(int i, int x)  // -> max of value
{
	// pruning
	if(i>=0 && x==0) return -INF;
	// base case
	if(i==-1)
	{
		if(x==0) return 0;
		else return -INF;
	}
	// cache check
	if(dp[i][x]!=-1)
	{
		return dp[i][x];
	}
	// Compute / Transition
	int ans = -INF;
	int min_seen = arr[i];
	for(int j=i;j>=0;j--)
	{
		min_seen = min(min_seen,arr[j]);
		ans  = min(ans,rec(i-1,x-1)+min_seen);
	}

	// Save and Return
	return dp[i][x] = ans;
}
void solve() {
    // Input section
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
    // Logic section
    cout<<rec(n-1,k);

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