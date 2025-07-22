#include <bits/stdc++.h>
using namespace std;
// global variable
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>parent;
bool is_cycle ;
// traversal algorithm
void dfs(int node,int par){
    vis[node]=1; // being visited
    parent[node]=par;
    for(auto x:g[node]){
        if(vis[x]==0){
            dfs(x,node);
        }
        else if(vis[x]==1){
            is_cycle=true;
            return;
        }
    }
    vis[node]=2; // already visited
}
// sovle function
void solve()
{
	g.clear();
	// input section
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1, 0);
	parent.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		// directed graph
		g[a].push_back(b);
	}
	is_cycle = false;
	// logic section
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i,0);
		}
	}
	if(is_cycle)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}

}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t_ = 1;
	cin>>t_;
	for(int i=0;i<t_;i++)
	{
        solve();
	}

	return 0;
}