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
int S; // S-> Total sum given 
int x[10001];
int dp[101][10001];
// now recursive function
int rec(int i, int taken)
{
	// pruining
	if(taken>S) return 0;
	// base case
	if(i==n+1)
	{
		if(taken==S)
		{
			return 1;
		}
		else return 0;
	}

	// cache check
	if(dp[i][taken]!=-1)
	{
		return dp[i][taken];
	}
	// Transition
	int ans = 0;
	if(rec(i+1,taken)==1)
	{
		ans = 1;
	}
	else if(rec(i+1, taken+x[i]))
	{
		ans = 1;
	}
	// save and return 
	return dp[i][taken] = ans;
}

void solve() {
    // Input section
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>x[i];
    }
    cin>>S;
    memset(dp,-1,sizeof(dp));

    // Logic section
    cout<<rec(1,0);
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