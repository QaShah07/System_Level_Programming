#include <bits/stdc++.h>
using namespace std;
// global variable
int n, m;
vector<vector<int>>g;
// vector<int>vis;
// for this we are using dp concept
int dp[10010];
int rec(int start_node)
{
	if(dp[start_node]!=-1)
	{
		return dp[start_node];
	}
	int ans = 1;
	for(auto v: g[start_node])
	{
		ans = max(ans,1+rec(v));
	}
	return dp[start_node] = ans;
}

void solve()
{
	// input section
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	// logic section
	memset(dp,-1,sizeof(dp));
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		ans = max(ans,rec(i));
	}
	cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}
