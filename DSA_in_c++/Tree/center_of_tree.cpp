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
vector<int>g[200010];
ll dep[200010];
ll par[200010];
// Travesla algorithm
void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    for(auto v: g[node])
    {
        if(v != parent)
        {
            dfs(v,node,depth+1);
        }
    }
}
void solve() {
    // Input section
    ll n;
    cin>>n;
    ll maxNode = 0;
    for(int i=0;i<n-1;i++)
    {
        ll a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        maxNode = max({maxNode,a,b});
    }
    // Logic section
    dfs(1,0,0);
    ll farNode1 = 1;
    for(int i=2;i<=maxNode;i++)
    {
        if(dep[i]>dep[farNode1])
        {
            farNode1 = i;
        }
    }
    for(int i=0;i<n;i++)
    {
        dep[i] = 0;
    }
    ll farNode2 = farNode1;
    dfs(farNode1,0,0);
    for(int i=1;i<=maxNode;i++)
    {
        if(dep[i]>dep[farNode2])
        {
            farNode2 = i;
        }
    }
    // D - diamter
    ll D = dep[farNode2];
    if(D&1)
    {
        cout<<"-1\n";
        return;
    }
    // now for 
    ll goback = D/2;
    ll stepOn = 1;
    ll center = farNode2;
    while(stepOn<=goback)
    {
        center = par[center];
        stepOn++;
    }
    cout<<center<<"\n";

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