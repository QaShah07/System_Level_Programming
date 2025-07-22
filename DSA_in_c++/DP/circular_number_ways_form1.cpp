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
// recursive funtion
int rec(int i, int prev, int first)
{
	// pruning
	// base case
	if(i==n)
	{
		if(prev ==first && n !=1) return 0;
		return 1;
	}
	// chache check
	if(prev != -1 && dp[i][prev] != -1)
	{
		return dp[i][prev];
	}
	// Transition
	int ans = 0;
	if(s[i]=='?')
	{
		for(int ch=0;ch<4;ch++)
	{
		if(ch==prev) continue;
		if(i==0)
		{
			ans += rec(i+1,ch,ch);
		}
		else
		{
			ans += rec(i+1,ch,first);
		}
	}
	}
	else
	{
		if((s[i]-'A')==prev) return 0;
		if(i==0)
		{
			ans +=rec(i+1,(s[i]-'A'),(s[i]-'A'));
		}
		else
		{
			ans +=rec(i+1,(s[i]-'A'),first);
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
    cout<<rec(0,-1,-1);
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