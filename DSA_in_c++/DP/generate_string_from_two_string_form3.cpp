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
string x , y;
int n,m;
vector<vector<int>>dp; // here we need Dynamic array and also due to save MLe
int rec(int l1,int l2)
{
    // prining 
    // base case
    if(l1==n && l2 ==m) return 0;
    // cache check
    if(dp[l1][l2]!=-1)
    {
        return dp[l1][l2];
    }
    // Compute and transition
    int ans = 1e9;
    if(l1<n) // -1 x[l1] transition
    {
        ans = min(ans,rec(l1+1,l2)+1);
    }
    if(l2<m) // +1 y[l2] transiton
    {
        ans = min(ans,rec(l1,l2+1)+1);
    }
    // bothe comman 
    if(l1<n && l2<m && x[l1]==x[l2])
    {
        ans = min(ans,rec(l1+1,l2+1)+1);
    }
    // saven and return
    return dp[l1][l2] = ans;
}

void solve() {
    // Input section
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    dp.assign(n+1,vector<int>(m+1,-1)); 

    // Logic section
    cout<<rec(0,0);
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