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
string s1,s2;
int dp[505][505];
int rec(int l1, int l2)
{
	// pruning 
	if(l1>n || l2>m) return 1e9;
	// base case
	int ans = 1e9;
	if(l1==n)
	{
		return m-l2;
	}
	if(l2==m)
	{
		return n-l1;
	}
	if(l1==n && l2 == m)
	{
		return 0;
	}
	// cache check
	if(dp[l1][l2]!=-1)
	{
		return dp[l1][l2];
	}
	// compute/Transition
	if(s1[l1]==s2[l2])
	{
		ans = rec(l1+1,l2+1);
	}
	else{
		ans = 1+rec(l1+1,l2+1);
	}
	ans = min(ans,rec(l1+1,l2));
	ans = min(ans,rec(l1,l2+1));
	// save and return
	return dp[l1][l2] = ans;
}

void solve() {
    // Input section
    cin>>s1>>s2;
    n = s1.length();
    m = s2.length();
    memset(dp,-1,sizeof(dp));


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