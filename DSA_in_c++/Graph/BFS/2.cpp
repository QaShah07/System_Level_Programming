#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// global variable 
int n,m;
vector<int>vis;
vector<vector<int>>g;
// travesal algorithm
void dfs(int node)
{
	vis[node] = 1;
	for(auto v: g[node])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
}
void solve()
{
	// input section
	cin>>n>>m;
	vis.assign(n+1,0);
	g.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a); // for non-directional
	}
	// logic section
	int cc_num = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cc_num++;
			dfs(i);
		}
	}
	cout<<(cc_num-1)<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
    return 0;
}
