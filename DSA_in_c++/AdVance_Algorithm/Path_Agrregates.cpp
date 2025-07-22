#include <bits/stdc++.h>
using namespace std;

//—— Self‐use terminology ———————————————————————————————————————————————
#define ll long long
#define ld long double
#define F  first
#define S  second

using state = pair<int,int>;
using vi    = vector<int>;
using vvi   = vector<vi>;

const int MAXL = 20;             // up to 2^19 steps
const int MOD  = 1e9 + 7;        // unused here but from your template

//—— Globals ————————————————————————————————————————————————————————————
int n, q;
vvi             g;               // adjacency list: g[u] = {neighbors of u}
vector<ll>      val;             // val[u] = value at node u
vvi             par;             // par[u][i] = 2^i-th ancestor of u
vector<vector<ll>> dp;           // dp[u][i]  = GCD of the 2^i-length jump from u upward
vi              depth;           // depth[u]   = depth of u (root has depth 0)

//—— DFS: build binary‐lifting & GCD tables —————————————————————————————
void dfs(int node, int prev, int dep) {
    par[node][0]   = prev;           // immediate parent
    depth[node]    = dep;            // depth in tree
    dp[node][0]    = val[node];      // GCD of zero‐length = node’s own value

    // Build jumps of size 2^i for i=1…MAXL-1
    for (int i = 1; i < MAXL; i++) {
        int mid = par[node][i-1];    // the 2^(i-1) ancestor
        par[node][i] = (mid>0 ? par[mid][i-1] : 0);
        dp[node][i]  = (mid>0
                       ? gcd(dp[node][i-1], dp[mid][i-1])
                       : dp[node][i-1]);
    }

    // Recurse on children
    for (int v : g[node]) {
        if (v == prev) continue;
        dfs(v, node, dep+1);
    }
}

//—— Query GCD on path u ↔ v —————————————————————————————————————————————
ll pathGCD(int u, int v) {
    ll ans = 0;

    // 1) Lift u up so depth[u] == depth[v]
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < MAXL; i++) {
        if (diff & (1<<i)) {
            ans = gcd(ans, dp[u][i]);
            u   = par[u][i];
        }
    }

    // 2) If after lifting they meet, include that node’s value
    if (u == v) {
        return gcd(ans, val[u]);
    }

    // 3) Lift both up together until their parents diverge
    for (int i = MAXL-1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            ans = gcd(ans, dp[u][i]);
            ans = gcd(ans, dp[v][i]);
            u   = par[u][i];
            v   = par[v][i];
        }
    }

    // 4) Finally include the last step from u & v to LCA and the LCA itself
    ans = gcd(ans, dp[u][0]);
    ans = gcd(ans, dp[v][0]);
    return gcd(ans, val[par[u][0]]);
}

//—— Solve one test case —————————————————————————————————————————————
void solve() {
    cin >> n >> q;

    // Resize globals
    g    .assign(n+1, vi());
    val  .assign(n+1, 0LL);
    depth.assign(n+1, 0);
    par  .assign(n+1, vi(MAXL, 0));
    dp   .assign(n+1, vector<ll>(MAXL, 0LL));

    // 1) Read node‐values
    for (int u = 1; u <= n; u++) {
        cin >> val[u];
    }

    // 2) Read edges
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 3) Preprocess from root = 1
    dfs(1, 0, 0);

    // 4) Answer each query in O(log n)
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << pathGCD(u, v) << "\n";
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

