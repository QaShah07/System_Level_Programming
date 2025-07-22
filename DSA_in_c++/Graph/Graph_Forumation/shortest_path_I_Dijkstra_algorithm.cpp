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
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

// Global variables (if any)
int n,m;
vector<vector<state>>g;
vi vis;
vi dist;
// algorithm dijkestra
void dijkestra (int st) {
    for (int i=1 ; i<=n ; i++) {
        dist[i]=1e18;
        vis[i]=0;
    }
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,st});
    dist[st]=0;
    while(!pq.empty()) {
        int cur=pq.top().second;
        pq.pop();
        if (vis[cur]) continue;
        else vis[cur]=1;
        for (auto v:g[cur]) {
            int neigh=v.second;
            int d=v.first;
            if (!vis[neigh] && dist[neigh]>dist[cur]+d) {
                dist[neigh]=dist[cur]+d;
                pq.push({dist[neigh],neigh});
            }
        }
    }
}
void solve() {
    // Input section
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);
    dist.resize(n+1);
    // vis.assign(n+1,0);
    // dist.assign(n+1,1e18);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({c,b});
    }
    // Logic section
    dijkestra(1);
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
}

signed  main() {
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
