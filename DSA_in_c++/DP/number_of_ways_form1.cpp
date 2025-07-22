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
int n;
string s;
int dp[100100][4];
// int rec
int rec(int i, int prev)
{
	// pruning 
	// base case
	if(i==n)
	{
		return 1;
	}
	// cache check
	if(prev != -1 && (dp[i][prev] != -1))
	{
		return dp[i][prev];
	}
	// transition
	int ans = 0 ;
	if(s[i]=='?')
	{
		for(int ch=0;ch<4;ch++)
		{
			if(ch==prev) continue;
			ans +=rec(i+1,ch);
		}
	}
	else
	{
		if((s[i]-'A')==prev)
		{
			return 0;
		}
		else
		{
			ans = rec(i+1,(s[i]-'A'));
		}
	}
	// save and return 
	if(prev !=-1) dp[i][prev] = ans;
	return ans;
}

void solve() {
    // Input section
	cin>>n;
	cin>>s;
	memset(dp,-1,sizeof(dp));
    // Logic section
    cout<<rec(0,-1);
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