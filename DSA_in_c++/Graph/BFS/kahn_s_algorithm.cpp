#include <bits/stdc++.h>
using namespace std;
// global variable
vector<vector<int>>g;
vector<int>vis;
vector<int>indeg; // outdeg;
vector<int>topo;
int n,m;
// traversal algorithm - BFS
void kahn()
{
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		topo.push_back(cur);
		for(auto v: g[cur])
		{
			indeg[v]--;
			if(indeg[v]==0)
			{
				q.push(v);
			}
		}
	}
}

void solve()
{
	// input section
	cin>>n>>m;
	g.resize(n+1);
	indeg.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		// Dag
		g[a].push_back(b);
		indeg[b]++;
		// outdeg[a]++;
	}
	kahn();
	// printing kind of thing
	for(auto v: topo)
	{
		cout<<v<<" ";
	}

}
// main controling fuction
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}