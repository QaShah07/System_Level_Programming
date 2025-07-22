#include<bits/stdc++.h>
using namespace std;
// global variable
int n,m;
vector<vector<int>>g;
vector<int>vis;
bool is_cycle = 0;
// traversal algorithm
void dfs(int start_node, int par)
{
    vis[start_node] = 1;
    for(auto v: g[start_node])
    {
        if(!vis[v])
        {
            dfs(v,start_node);
        }
        else if(v !=par) // here coming condtion of back edge
        {
            is_cycle = 1;
            break;
        }
    }
}
// solve function
void solve()
{
    // input section
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        // this is undirected graph
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // now graph visiting startge
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(!is_cycle)
            {
                dfs(i,0);
            }
        }
    }
    if(is_cycle)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t_= 1;
    // cin>>t_;
    for(int i = 0;i<t_;i++)
    {
        solve();
    }
    return 0; 
}