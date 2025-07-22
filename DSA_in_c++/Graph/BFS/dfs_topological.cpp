#include<bits/stdc++.h>
using namespace std;
// global variable
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>topo;
// traversal algorithm DFS
void dfs(int start_node)
{
	vis[start_node] = 1;
	for(auto v: g[start_node])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
	topo.push_back(start_node);

}
void solve()
{
	// input section
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		// DAG
		g[a].push_back(b);
	}
	// now for travesing all ndoe
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	reverse(topo.begin(),topo.end());
	// for printing kind of thing
	for(auto it: topo)
	{
		cout<<it<<" ";
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t_ = 1;
	// cin>>t_;
	for(int i =0;i<t_;i++)
	{
		solve();
	}
}