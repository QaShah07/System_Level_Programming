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
string s1, s2,s3;
int dp[101][101][101];
// reucrsive function
int rec(int i ,int j, int k)
{
	// pruning
    // base case
    if(i==s1.size() || j==s2.size() || k == s3.size())
    {
        return 0;
    }
    // cache check
    if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    // Compute/Transitioin
    int ans = 0;
    ans = max(ans,rec(i+1,j,k));
    ans = max(ans,rec(i,j+1,k));
    ans = max(ans,rec(i,j,k+1));
    if(s1[i]==s2[j] && s2[j]== s3[k]) ans = max(ans,1+rec(i+1,j+1,k+1));
    // save and return
    return dp[i][j][k] = ans;
}

void solve() {
    // Input section
    cin>>s1>>s2>>s3;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl;
    // Logic section
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