#include<bits/stdc++.h>
using namespace std;
#define int long long
// global vaiable
vector<vector<int>>g;
vector<int>topo;
vector<int>ans;
vector<int>indeg;
int mod = 1e9+7;
int n,m;
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
	// iinput section
	cin>>n>>m;
	g.resize(n+1);
	ans.assign(n+1,0);
	indeg.assign(n+1,0);
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		indeg[b]++;
	}
	// logic section
	kahn();
	ans[1] = 1;
	for(int i=0;i<topo.size();i++) {
	for(auto v: g[topo[i]]) {
		ans[v] = (ans[v] + ans[topo[i]]) % mod;
	}
}
	cout<<ans[n];

}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie(0);
	solve();
	return 0;
}