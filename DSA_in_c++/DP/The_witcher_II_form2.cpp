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
int mat[205][205];
int dp[205][205];
ll rec(int i, int j)
{
    // pruning
    if(i>=n || j>=m)
    {
        return 1e9;
    }
    // base case
    if(i==n-1 && j==m-1)
    {
        if(mat[i][j]>=0)
        {
            return 1;
        }
        else
        {
            return abs(mat[i][j])+1;
        }
    }
    // cache check
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    // Compute/Transition
    ll ans = 0;
    ans = min(rec(i+1,j),rec(i,j+1))-mat[i][j];
    ans = max(ans,1LL);
    // save and return
    return dp[i][j] = ans;
}

void solve() {
    // Input section
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>mat[i][j];
    	}
    }
    memset(dp,-1,sizeof(dp));
    // Logic section
    cout<<rec(0,0)<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t_ = 1;
    cin >> t_;
    for (int i = 0; i < t_; i++) {
        solve();
    }

    return 0;
}