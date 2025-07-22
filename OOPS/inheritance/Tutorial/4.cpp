#include <bits/stdc++.h>
using namespace std;

// Self use terminology
#define ll long long
#define ld long double
#define int long long int
#define F first
#define S second

using state = pair<int,int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<state>> g;
vb vis;
vi dist;

void dijkstra(int sc) {
    priority_queue<state, vector<state>, greater<>> pq;
    pq.push({0, sc});
    dist[sc] = 0;
    while (!pq.empty()) {
        int cur = pq.top().S;
        pq.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (auto cord : g[cur]) {
            int neigh = cord.S;
            int t = cord.F;
            if (dist[neigh] > dist[cur] + t) {
                dist[neigh] = dist[cur] + t;
                pq.push({dist[neigh], neigh});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.clear(); vis.clear(); dist.clear();  // clear old values if multiple test cases
    g.resize(n + 1);
    vis.assign(n + 1, false);
    dist.assign(n + 1, 1e18);

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({d, v});
        g[v].push_back({d, u});
    }

    int start;
    cin >> start;
    dijkstra(start);

    int minAns = LLONG_MAX, maxAns = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        for (auto v : g[i]) {
            int t = v.F;
            int c = v.S;
            if (abs(dist[i] - dist[c]) >= t) {
                minAns = min(minAns, (min(dist[i], dist[c]) + t) * 10);
            } else {
                maxAns = max(maxAns, (dist[i] + dist[c] + t) * 5);
            }
        }
    }

    if (minAns == LLONG_MAX && maxAns == LLONG_MIN) {
        cout << "No valid edges\n";
    } else {
        cout << max(minAns, maxAns) << "\n";  /
    }
}

signed main() {
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
