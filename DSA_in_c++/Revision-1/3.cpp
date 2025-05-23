#include<bits/stdc++.h>
using namespace std;
// global variable
int n, m;
vector<vector<int>>g;
vector<int>vis;
vector<int>col;
bool is_bipartite = 1;
// traversal algorithm - DFS
void dfs(int node, int cur_col)
{
	vis[node] = 1;
	col[node] = cur_col;
	for(auto v: g[node])
	{
		if(!vis[v])
		{
			dfs(v, (1+2)-cur_col);
		}
		else
		{
			if(cur_col == v)
			{
				is_bipartite = 0;
			}
		}
	}
}

void solve()
{
	// input section 
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	col.assign(n+1,0);


	// for explicit graph
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		// for undirected graph
		g[b].push_back(a);
	}

	// logc section
	is_bipartite = 1;
	for(int i =1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,1);
		}
	}
	// now original answer
	if(is_bipartite)
	{
		cout<<"Possible\n";
	}
	else
	{
		cout<<"Not Possible\n";
	}
	// now printing  for debuging
	for(int i =1;i<=n;i++)
	{
		cout<<i<<" "<<col[i]<<endl;
	}
}