#include <bits/stdc++.h>
using namespace std;
// self use termiglogy
#define ll long long
#define ld long double
#define F first
#define S second

using state = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;
// global variable(if any)
vector<int> g[200010]; // Increase the size of the array to 2 x 10^5 + 10
ll par[200010]; 
ll dep[200010]; 

void dfs(int node, int parent, int depth) {
    dep[node] = depth;
    par[node] = parent;
    for(auto v: g[node]) {
        if(v != parent) {
            dfs(v, node, depth + 1);
        }
    }
}

void solve() {
    // input section
    ll n; 
    cin >> n;


    ll maxNode = 0; 
    for(ll i = 0; i < n - 1; i++) { 
        ll a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        maxNode = max({maxNode, a, b});
    }
// logic section
    // first DFS traversal to find farthest node from 1.
    dfs(1, 0, 0);
    ll farNode1 = 1; 
    for (ll i = 2; i <= maxNode; i++) { 
        if (dep[i] > dep[farNode1]) {
            farNode1 = i;
        }
    }

    for (ll i = 0; i < n+1; i++) { 
        dep[i] = 0;
    }
    // 2nd DFS travesal to find Farthest node to from node of index farNode1.
    dfs(farNode1, 0, 0);

    ll farNode2 = farNode1; 
    for (ll i = 1; i <= maxNode; i++) { 
        if (dep[i] > dep[farNode2]) {
            farNode2 = i;
        }
    }
    // The Distance from Farthest node 1 to farthestnode 2 ~ dfs(u,0,0) then dis[v] give the distance between u and v

    cout << dep[farNode2] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 

    ll t_ = 1; 
    // cin >> t_;
    while(t_--) {
        solve();
    }

    return 0;
}
