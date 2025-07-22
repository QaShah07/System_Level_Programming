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
int a[100010],b[100010],c[100010];
// rec function
int dp[100010][3];
int rec(int i, int choice ) // i basicaly days
{
	// pruning
	// base case
	if(i==n) return 0;
	// cache check
	if(dp[i][choice]!=-1)
	{
		return dp[i][choice];
	}
	// calculate/Transistion

	int res = 0;
	if(choice !=0) res = max(res,rec(i+1,0)+a[i]);
	if(choice !=1) res = max(res,rec(i+1,1)+b[i]);
	if(choice !=2) res = max(res,rec(i+1,2)+c[i]);
	// Save and return
	return dp[i][choice] = res;
}

void solve() {
    // Input section
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	memset(dp,-1,sizeof(dp));
    // Logic section
    cout<<rec(0,3)<<endl;
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