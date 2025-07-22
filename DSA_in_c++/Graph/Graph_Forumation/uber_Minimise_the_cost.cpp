#include <bits/stdc++.h>
using namespace std;

// Self use terminology
#define MP make_pair
#define ll long long
#define ld long double
#define F first
#define S second

using state = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

// Global variables (if any)
vector<vector<pair<int,state>>>g;
int n,m,k;
int dist[1001][1001];
int vis[1001][1001];
int c[1001];
// Algorithm Dijkestra-Algorithm
void dijkstra(state st)
{
    priority_queue<pair<int,state>, vector<pair<int,state>>, greater<>> pq;
    dist[st.F][st.S] = 0;
    pq.push(MP(0, st));

    while(!pq.empty())
    {
        auto val = pq.top(); pq.pop();
        int cur_dist = val.F;
        int node = val.S.F;
        int fuel = val.S.S;

        if(vis[node][fuel]) continue;
        vis[node][fuel] = 1;

        for(auto v : g[node])
        {
            int to = v.F;
            int cost = v.S.F;
            int distance = v.S.S;

            if(fuel >= cost && dist[to][fuel - cost] > cur_dist + distance)
            {
                dist[to][fuel - cost] = cur_dist + distance;
                pq.push(MP(dist[to][fuel - cost], MP(to, fuel - cost)));
            }
        }

        if(fuel + 1 <= k && dist[node][fuel + 1] > cur_dist + c[node])
        {
            dist[node][fuel + 1] = cur_dist + c[node];
            pq.push(MP(dist[node][fuel + 1], MP(node, fuel + 1)));
        }
    }
}

void solve() {
    cin >> n >> m >> k;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dist[i][j] = 1e9;
            vis[i][j] = 0;
        }
    }

    g.clear();
    g.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> c[i];

    for(int i = 0; i < m; i++) {
        int a, b, p, d;
        cin >> a >> b >> p >> d;
        g[a].push_back(MP(b, MP(p, d)));
        g[b].push_back(MP(a, MP(p, d)));
    }

    state st = {1, 0}; // Start at node 1 with 0 fuel
    dijkstra(st);

    int ans = 1e9;
    for(int i = 0; i <= k; i++) {
        ans = min(ans, dist[n][i]);
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
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
