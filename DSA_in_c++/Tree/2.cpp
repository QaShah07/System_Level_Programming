#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <vector <int>> g;
vector <int> subtreesz;
int ans=0;
int n;

void dfs(int node,int parent, int depth){
    subtreesz[node]=1;
    for (auto v:g[node]){
        if (v!=parent){
            dfs(v,node,depth+1);
            subtreesz[node]+=subtreesz[v];
        }
    }
    
    ans+=(n - subtreesz[node])*(subtreesz[node]);
}

signed main(){
    cin>>n;
    g.resize(n+1);
    subtreesz.assign(n+1,0);
    
    int edge=n-1;
    while(edge--){
        int a,b;
        cin>>a>>b;
        
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(1,0,0);
    
    cout<<ans<<'\n';
}