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
int n,m;
int mat[1010][1010];
int dp[1010][1010];
// recrusive function
ll rec(int r, int c)
{
    // pruning 
    if(r<0 || c<0) return 0;
    // base case
    if(r==0 && c==0)
    {
        if(mat[r][c]==1) return 1;
        else return 0;
    }
    // cache check
    if(dp[r][c]!=-1)
    {
        return dp[r][c];
    }
    // Compute/Transition
    ll ans ;
    if(mat[r][c]==0) ans = 0;
    else ans = 1+min(rec(r-1,c),min(rec(r,c-1),rec(r-1,c-1)));
    // Save and Return 
    return dp[r][c] = ans;
}

// Global variables (if any)

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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j] = -1;
        }
    }

    // Logic section
    ll best = -1e9;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            best = max(best,rec(i,j));
        }
    }
    cout<<best*best<<"\n";
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