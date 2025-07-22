#include<bits/stdc++.h>
using namespace std;

// global variable
int n,m;
vector<int>vis;
vector<int>col;
vector<vector<int>>g;
bool is_team = 1;

// traversal algorithm DFS
void dfs(int start_node, int cur_col)
{
	vis[start_node] =1 ;
	col[start_node] = cur_col;
	for(auto v: g[start_node])
	{
		if(!vis[v])
		{
			dfs(v,(1+2)-cur_col);
		}
		else
		{
			if(col[v]==col[start_node])

			{
				is_team = 0; 
			}
		}
	}
}
// solve funtion
void solve()
{
	// input section
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	col.assign(n+1,1);
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		// undirected graph
		g[a].push_back(b);
		g[b].push_back(a);
	}
	// logic section
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,1);
		}
	}
	if(is_team)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t_ = 1;
	// cin>>t_;
	for(int i=0;i<t_;i++)
	{
		solve();
	}
	return 0;
}