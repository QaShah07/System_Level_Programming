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
int x[101];
int S;
int dp[101][10001];
// rec function
int rec(int i, int left)
{
	// pruning 
	if(left<S) return 0;
	// base case 
	if(i==n+1)
	{
		if(left==0)
		{
			return 1;
		}
		else return 0;
	}
	// cache check
	if(dp[i][left]!=-1)
	{
		return dp[i][left];
	}
	// Transition
	int ans = 0;
	if(rec(i+1,left)==1)
	{
		ans  = 1;
	}
	else if(rec(i+1,left-x[i]))
	{
		ans  = 1;
	}
	// save and return 
	return dp[i][left] = ans;
}
// generate solution means print the solution 
void printset(int i, int left)
{
	// base case
	if(i==n+1)
	{
		return ;
	}
	// 
	if(rec(i+1,left)==1) // don't take case
	{
		printset(i+1,left);
	}
	// take case
	else if (rec(i+1, left-x[i]))
	{
		cout<<x[i]<<" ";
		printset(i+1,left-x[i]);
	}
}

void solve() {
    // Input section
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>x[i];
    }
    // cin>>S;
    // this basically resotre the thing
    memset(dp,-1,sizeof(dp));

    // Logic section
    int q;
    cin>>q;
    while(q--)
    {
    	int t;
    	cin>>t;
    	if(rec(1,t))
    	{
    		printset(1,t);
    	}
    }
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