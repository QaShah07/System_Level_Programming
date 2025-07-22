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
// form 4 for pallindrome check
int dp1[1001][1001];
int rec(int l, int r)
{
	// pruning 
	// base case
	if(l>=r) return 1;
	// cache check
	if(dp[l][r]!=-1)
	{
		return dp1[l][r];
	}
	// Compute/Transition
	int ans = 0;
	if(s[l]==s[r] && rec(l+1,r-1)) ans = 1;
	// save and return
	return ans;
}
// form 2 for minimum break
int dp2[1001];
int rec2(int i)
{
	// pruning
	if(i==0) return -1;
	// base case
	// cache check
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	// Compute/Transition
	int ans = 1e9;
	for(int j=0;j<i;j++){
		if(rec(j+1,i))
		{
			ans = min(ans,rec2(j)+1);
		}
	}
	// save and return 
	return dp[i]=ans; 
}

void solve() {
    // Input section
	cin>>n;
	cin>>s;
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	cout<<rec(n)<<endl;
    // Logic section
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