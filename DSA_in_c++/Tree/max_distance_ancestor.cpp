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
vi val;
vi parent;

// DFS algorithm
int ans  = 0;

void dfs(int node, int par, int minVal, int maxVal)
{
	// for debuging 
	cout<<node<<" "<<par<<" "<<minVal<<" "<<maxVal<<" "<<endl;
	if(par != -1)
	ans = max({ans, abs(val[node] - minVal), abs(val[node] - maxVal)});
	for(auto v: g[node])
	{
		if(v==par) continue;
		dfs(v, node, min(minVal, val[node]), max(maxVal, val[node])); 
	}

}
void solve() {
    // Input section
	int n;
	cin>>n;
	g.resize(n+1);
	val.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
	}
	parent.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
    // Logic section
    dfs(1,-1,1e9,-1e9);
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