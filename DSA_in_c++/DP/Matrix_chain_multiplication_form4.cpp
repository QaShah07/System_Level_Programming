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
int n ,
int x[101], y[101];
int dp[101][101];
int rec(int l,int r)
{
	// pruning
	if(l>r) return 0;
	// base case
	if(l==0) return 0;
	// cache check
	if(dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	// compute/Transition
	int ans = 1e9;
	for(int mid=l;mid<r;mid++)
	{
		ans = min(ans,rec(l,mid)+rec(mid+1,r)+x[l]*x[mid]*x[r]);
	}
	// save and return 
	return dp[l][r] = ans;
}

void solve() {
    // Input section
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	memset(dp,-1,sizeof(dp));
    // Logic section
    cout<<rec(1,n)<<endl;

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