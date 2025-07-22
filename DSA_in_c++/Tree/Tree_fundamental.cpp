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
vector<int>g[100100];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int subtreeSize[100100];
int numChild[100100];
// travesal algorithm 
void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    subtreeSize = 1;
    numChild[node] = 0;
    // go to all nodes and traverse
    for(auto v: g[node])
    {
        if(v != parent)
        {
            numChild[node]++;
            dfs(v,node,depth+1);
            subtreeSize[node] += subtreeSize[v];
        }
    }
    // Child
    if(numChild[node]==0)
    {
        isLeaf[node] = 1;
    }
}

void solve() {
    // Input section
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);

    // Logic section
    // now you can print anything 
    
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
