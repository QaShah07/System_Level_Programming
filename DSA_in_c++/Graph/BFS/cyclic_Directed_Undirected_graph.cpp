#include <bits/stdc++.h>
using namespace std;
// global variable
int n,m;
vector<vector<int>>g;
vector<int>col;
bool is_cycle = 0;
// Traversal algorithm
void dfs(int start_node)
{
	col[start_node] = 1;
	for(auto v: g[node])
	{
		if(col[v]==1)
		{
			// node v is a forward edge
			dfs(v);
		}
		else if(col[v]==2)
		{
			// node -v is a back edge
			// we found cycle !
			is_cycle = 1;
		}
		else if (col[v]==3)
		{
			// node -v is a cross edge
			// unimportant
		}
	}
	col[node] = 3;
}
void solve()
{
	// input section
	cin>>n>>m;
	g.resize(n+1);
	col.assign(n + 1, 1);

	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a); // if graph is undirected
	}
	// we have to visit all node beacuse it may happen connected component concept
	for(int i=1;i<=n;i++)
	{
		if(col[node]==1)
		{
			dfs(i,0);
		}
	}
	if(is_cycle)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
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
