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
vvi g;
vector<ll>val;
vi depth;
vvi par;
vector<vector<ll>>dp;
const int MAXL = 20;
// Recurseve GCD algorithm
ll gcd(ll a, ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
// Traversal Algorithm DFS
void dfs(int node, int prev, int dep)
{
	par[node][0] = prev;
	depth[node] = dep;
	dp[node][0] = val[node];
	for(int i=1;i<MAXL;i++)
	{
		int mid = par[node][i-1];
		par[node][i] = (mid >0 ? par[mid][i-1]:0);
		dp[node][i] = (mid>0 ? gcd(dp[node][i-1],dp[mid][i-1]):dp[node][i-1]);
	}
	for(int v: g[node])
	{
		if(v != prev)
		{
			dfs(v, node,dep+1);
		}
	}
}
// Now LCA
ll pathGCD(int u, int v)
{
	ll ans = 0;
	if(depth[u]<depth[v]) swap(u,v);
	int diff = depth[u]-depth[v];
	for(int i=0;i<MAXL;i++)
	{
		if(diff &(1<<i))
		{
			ans = gcd(ans,dp[u][i]);
			u = par[u][i];
		}
	}
	if(u==v)
	{
		return gcd(ans,val[u]);
	}
	for (int i = MAXL-1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            ans = gcd(ans, dp[u][i]);
            ans = gcd(ans, dp[v][i]);
            u   = par[u][i];
            v   = par[v][i];
        }
    }
    ans = gcd(ans, dp[u][0]);
    ans = gcd(ans, dp[v][0]);
    return gcd(ans, val[par[u][0]]);

}

void solve() {
    // Input section
    int n;
    cin>>n;
    g.assign(n+1,{});
    val.assign(n+1,0LL);
    par.assign(n+1,vi(MAXL,0));
    depth.assign(n+1,0);
    dp.assign(n+1,vector<ll>(MAXL,0LL));
    for(int i=1;i<=n;i++)
    {
    	cin>>val[i];
    }
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
    // Logic section
    while(q--)
    {
    	int x; int y;
    	cin>>x>>y;
    	cout<<pathGCD(x,y)<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t_ = 1;
    cin >> t_;
    for (int i = 0; i < t_; i++) {
        solve();
    }

    return 0;
}