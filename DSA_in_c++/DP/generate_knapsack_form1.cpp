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
int W;
int w[3003];
int v[3003];

// dp function
int dp[3003][3003];
int rec(int i, int x)
{
	// pruning 
	// base case
	if(i==n)
	{
		return 0;
	}
	// cache check
	if(dp[i][x]!=-1)
	{
		return dp[i][x];
	}
	// transition
	int ans = rec(i+1,x);
	if(w[i]<=x)
	{
		ans = max(ans,rec(i+1,x-w[i])+v[i]);
	}
	// save and return
	return dp[i][x] = ans;
}

// genreate function to store taking index
vi solution;
void generate(int i, int x)
{
	if(i==n)
	{
		return;
	}
	else
	{
		int dontake = rec(i+1,x);
		if(w[i]<=x)
		{
			int take = rec(i+1,x-w[i]);
			if(dontake>take)
			{
				generate(i+1,x);
			}
			else
			{
				solution.push_back(i);
				generate(i+1,x-w[i]);
			}

		}
		else
		{
			// can't take
			generate(i+1,x);
		}
	}
}
void solve() {
    // Input section
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
    	cin>>v[i];
    }
    cin>>W;

    // Logic section
    cout<<rec(0,W)<<endl;
    generate(0,W);
    cout<<solution.size()<<endl;
    for(auto v: solution)
    {
    	cout<<v<<" ";
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