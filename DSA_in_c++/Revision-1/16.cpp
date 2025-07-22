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
vector<int>col;
bool is_bipartite=true;
// Traversal algorithm
void dfs(int node, int cur_col) {
    vis[node] = 1;          // mark visited
    col[node] = cur_col;    // assign current color
    for (int v : g[node]) {
        if (!vis[v]) {
            // flip 1↔2 by 3 - cur_col
            dfs(v, 3 - cur_col);
        }
        else if (col[v] == col[node]) {
            // adjacent has same color → not bipartite
            is_bipartite = false;
        }
    }
}

void solve() {
    // Input section
    int n,m;
    cin>>n>>m;
    g.assign(n+1,{});
      //  Prepare visit & color arrays
    vis.assign(n+1,0);
    col.assign(n+1,0);
    //  Build adjacency list
    for(int i=0;i<m;i++)
    {
    	int a, b;
    	cin>>a>>b;
    	// undirected graph
    	g[a].push_back(b);
    	g[a].push_back(a);
    }

    // Logic section
    is_bipartite = true;
     //  Run DFS on each component
    for(int i=1;i<=n;i++){
    	if(!vis[i])
    	{
    		dfs(i,1);
    	}
    }
    // 4. Output result
   cout << (is_bipartite ? "Possible\n" : "Not Possible\n");
    // printting 
    // 5. (Optional) show each node’s color
    for (int i = 1; i <= n; i++)
        cout << i << " → color " << col[i] << "\n";
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