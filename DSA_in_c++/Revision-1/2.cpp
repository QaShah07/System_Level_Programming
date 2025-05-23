#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// global variable
vector<vector<int>>g;
vector<int>vis;
vector<int>cmp_num;
// travesal algorithm
void dfs(int node, int cmp_cc)
{
	vis[node] = 1;
	cmp_num[node] = cmp_cc;
	for(auto v: g[node])
	{
		if(!vis[node])
		{
			dfs(v,cmp_cc);
		}	
	}
}

// sovle funtion which handle my intput 
void solve(){
	// input section
	int n,m;
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a); /// for undirectional graph
	}
	// logic section
	int cmp_cc = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cmp_cc++;
			dfs(i,cmp_cc);
		}
	}

	// now logic 2 for query
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		// 
		if(cmp_num[x]==cmp_num[y])
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}

}

// main function
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin>>t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
	return 0;
}