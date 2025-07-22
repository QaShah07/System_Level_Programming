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
int n,m;
vector<vector<state>>g;
vi vis,dist;
// Algorithm 01BFS
void bfs01(int st, int en)
{
    deque<int>dq;
    dq.push_back(st);
    dist[st] = 0;
    while(!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();
        for(auto cord: g[cur])
        {
            int v = cord.F, d = cord.S;
            if(dist[v]>dist[cur]+d)
            {
                dist[v] = dist[cur]+d;
                if(d==0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
}
void solve() {
    g.clear();
    dist.clear();
    // Input section
    cin>>n>>m;
    g.resize(n+1);
    dist.assign(n+1,1e9);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,0}); // Directed graph
        g[b].push_back({a,1});
    }
    // Logic section
    bfs01(1,n);
    if(dist[n]==1e9) dist[n] = -1;
    cout<<dist[n]<<"\n";
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
