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
int cmp_size;
// Travesal Algorithm ~DFS
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

void solve() {
    // Input section
	int n,m;
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0); // 0 means not visited
		for(int j=0;j<m;j++)
		{
			// for undirectional graph
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
    // Logic section
		int cc_num = 0;
		vector<int>cmp_size_a;
		// For Traversal Algorithm to all node
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cmp_size = 0;
				cc_num++;
				dfs(i);
				cmp_size_a.push_back(cmp_size);
			}
		}
	// Printing the size of the connected component
		for(auto it: cmp_size_a)
		{
			cout<<it<<" ";
		}
		cout<<endl;

	// Now Logic for calculating No of edges
		long long sum = 0;
		sum = accumulate(cmp_size_a.begin(),cmp_size_a.end(),0LL);
		long long ans = 0;
		for(auto v: cmp_size_a)
		{
			ans += 1LL*v*v;
		}
		long long finalAns = (sum*sum-ans)/2;
		cout<<finalAns<<endl;
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