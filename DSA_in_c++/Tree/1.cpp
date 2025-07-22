#include<bits/stdc++.h>
using namespace std;

vector<int> g[200100];
int parent[200100];
int depth[200100];

void dfs(int node,int par,int dep){
    //cout<<node<<" "<<par<<" "<<dep<<endl;
    parent[node]=par;
    depth[node]=dep;
    for(auto it:g[node]){
        if(it!=par){
            dfs(it,node,dep+1);
        }
    }
}



void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);


    int maxch=1;
    for(int i=2;i<=n;i++){
        if(depth[i]>depth[maxch]){
            maxch=i;
        }
    }

    //cout<<maxch<<endl;

    int u=maxch;

     dfs(maxch,0,0);

    maxch=1;
    for(int i=2;i<=n;i++){
        if(depth[i]>depth[maxch]){
            maxch=i;
        }
    }

    //cout<<maxch<<endl;

     int v=maxch;

    int diameter=depth[maxch];

    //find center... 
    if(diameter&1){
        //odd dia -> even nodes
        cout<<"-1\n";
        return;
    }
    int goBack=diameter/2;

    int stepOn=1;

    int center=v;
    while(stepOn<=goBack){
        center=parent[center];
        stepOn++;
    }

    cout<<center<<'\n';

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}