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
const int INF = 1e9;

// Global variables (if any)
int n;
int arr[1010];
int dp[1010][1010];
int rec(int index, int x)
{
	// pruning
	if(x<0)
	{
		return 0;
	}
	// base case
	if(index==n)
	{
		if(x==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	// chache checked
	if(dp[index][x]!=-1)
	{
		return dp[index][x];
	}
	// print and check
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// }
	// cout<<endl;
	// calculate 
	int ans = rec(index+1,x)+rec(index+1,x-arr[index]);
	// save and return
	cout<<dp[index][x]<<" "<<ans<<" ";
	dp[index][x] = ans;
	return ans;
}
void solve() {
    // Input section
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	int x;
	cin>>x;
    // Logic section
    cout<<rec(0,x);
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