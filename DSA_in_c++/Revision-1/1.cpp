#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// global variable
vector<vector<int>>g;
vector<int>vis;
int cmp_size;

// Travesal algorithm -DFS
void dfs(int node)
{
	cmp_size++;
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
	int n,m;
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0); // 0 means not visite 
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		// for undirectional graph
		g[b].push_back(a);
	}

	// logic section
	int cc_num = 0;
	vector<int>cmp_size_a;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cmp_size=0;
			cc_num++;
			dfs(i);
			cmp_size_a.push_back(cmp_size);
		}
	}

	// for(auto c: cmp_size_a)
	// {
	// 	cout<<c<<" ";
	// }
	// cout<<endl;


	// now for 2nd logic part for calcualting 
	long long ans = 0;
	long long sum = accumulate(cmp_size_a.begin(),cmp_size_a.end(),0);
	for(auto v: cmp_size_a)
	{
		ans += v*v;
	}
	long long finalAns = (sum*sum-ans)/2;
	cout<<finalAns<<endl;
	// cout<<cc_num<<endl;
	// debug we want to print this
	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<i<<" "<<vis[i]<<"\n";
	// }
}

// 
signed main()
{
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