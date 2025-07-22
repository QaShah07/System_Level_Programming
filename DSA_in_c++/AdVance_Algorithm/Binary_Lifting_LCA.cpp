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

// LOG = maximum power for binary lifting (2^19 > 5e5)
const int LOG = 20;
vvi g;       // adjacency list of the tree
vvi par;     // par[u][i] = 2^i-th ancestor of u
vi depth;    // depth[u] = distance from root to u

// Traversal Algorithm DFS • Implementing pre-processing
// DFS to initialize depth[] and par[][0], then build all par[][i]
void dfs(int node, int parent, int dep) {
    par[node][0] = parent;  // direct parent (2^0-th ancestor)
    depth[node]   = dep;      // record depth of this node

    // Build ancestors at powers of two:
    // par[node][i] = par[ par[node][i-1] ][i-1]
    for (int i = 1; i < LOG; ++i) {
        int mid = par[node][i-1];
        par[node][i] = (mid > 0 ? par[mid][i-1] : 0);
    }

    // Recurse on children
    for (int v : g[node]) {
        if (v == parent) continue;       // skip edge back to parent
        dfs(v, node, dep + 1);
    }
}


// Query LCA of u and v in O(LOG)
int lca(int u, int v) {
    // 1) Make sure u is the deeper node
    if (depth[u] < depth[v]) swap(u, v);

    // 2) Lift u up to the depth of v
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i) {
        if (diff & (1 << i)) {
            u = par[u][i];
        }
    }
    // Now they may be equal
    if (u == v) return u;

    // 3) Lift both u and v until their parents diverge
    //    We go from highest power down to 0
    for (int i = LOG - 1; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    // 4) Their parent is now the LCA
    return par[u][0];
}

void solve() {
    // Input section
    int n;
    cin>>n;
    g.assign(n+1,{});
    par.assign(n+1,vi(LOG,0));
    depth.assign(n+1,0);
    for(int i=0;i<n-1;++i)
    {
    	int a, b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    // Logic section
    // Preprocess from root = 1 (depth 0, parent 0)
    dfs(1, 0, 0);

     // Answer queries
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
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