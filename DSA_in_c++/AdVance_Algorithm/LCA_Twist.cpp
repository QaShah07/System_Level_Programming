#include <bits/stdc++.h>
using namespace std;

// Self use terminology
#define ll long long
#define ld long double
#define F first
#define S second

using state = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

// Global variables (if any)
const int LOG = 20;
vector<vector<int>>g;
vector<int>depth;
vector<vector<int>>par;
void dfs(int node, int parent,int dep)
{
	par[node][0] = parent;
	depth[node] = dep;
	for(int i=1;i<LOG;++i)
	{
		int mid = par[node][i-1];
		par[node][i] = (mid > 0 ? par[mid][i-1]:0);
	}
	// Recurse on childre
	for(int v: g[node])
	{
		if(v != parent)
		{
			dfs(v,node,dep+1);
		}
	}
}
// Now lifting concept of LCA
int lca(int u,int v)
{
	if(depth[u]<depth[v]) swap(u,v);
	int diff = depth[u]-depth[v];
	for(int i=0;i<LOG;++i)
	{
		if(diff&(1<<i))
		{
			u = par[u][i];
		}
	}
	if(u==v) return u;
	for(int i = LOG-1;i>=0;--i)
	{
		if(par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
void solve() {
    // Input section
    int n;
    cin>>n;
    g.assign(n+1,{});
    depth.assign(n+1,0);
    par.assign(n+1,vi(LOG,0));
    for(int i=0;i<n-1;i++)
    {
    	int a, b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    dfs(1,0,0);
    int q;
    cin>>q;
    while(q--)
    {
    	int u,v,z;
    	cin>>u>>v>>z;
    	int x = lca(u,v), a= lca(u,z), b = lca(v,z);
    	if(a==x) cout<<b<<"\n";
    	else if (b==x) cout<<a<<"\n";
    	else cout<<x<<"\n";

    }

    // Logic section

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t_ = 1;
    // cin >> t_;
    for (int i = 0; i < t_; i++) {
        solve();
    }

    return 0;
}