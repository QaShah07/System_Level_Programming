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
int arr[1001];
int dp[1001][101];
// recursive function
int rec(int i, int x)
{
	// pruning 
	if(x<0) return 1e9;
	// base case
	if(i==-1)
	{
		if(x==0)
		{
			return 0;
		}
		else
		{
			return 1e9;
		}
	}
	// cache check
	if(dp[i][x]!=-1)
	{
		return dp[i][x];
	}
	// compute/Transition
	int ans = 1e9;
	int min_seen = arr[i];
	for(int j=i-1;j>=-1;j--)
	{
		ans = min(ans, rec(j,x-1)+min_seen);
		min_seen = min(min_seen,arr[j]);
	}
	// save and return
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