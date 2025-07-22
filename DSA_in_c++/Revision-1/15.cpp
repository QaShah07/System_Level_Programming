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
vector<vector<int>>g;
vector<int>vis;
vector<int>cc_num; // Conected componenet Number array
// Traversal Algortihm DFS
void dfs(int node, int cmp_cc)
{
	vis[node] = 1;
	cc_num[node] = cmp_cc;
	for(auto v: g[node])
	{
		if(!vis[v])
		{
			dfs(v,cmp_cc);
		}
	}
}
void solve() {
    // Input section
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    cc_num.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
    	// undirected graph
    	int a, b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    // Logic section
    int cmp_cc   = 0;
    // travesre all the node
    for(int i=1;i<=n;i++)
    {
    	if(!vis[i])
    	{
    		cmp_cc++;
    		dfs(i,cmp_cc);
    	}
    }

    // Now for the query
    int q;
    cin>>q;
    while(q--)
    {
    	int x,  y;
    	cin>>x>>y;
    	if(cc_num[x]==cc_num[y])
    	{
    		cout<<"yes"<<endl;
    	}
    	else
    	{
    		cout<<"No"<<endl;
    	}
    }

    // print the array and  see tit
    for(int i=1;i<=n;i++)
    {
    	cout<<i<<" "<<cc_num[i]<<" \n";
    }
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