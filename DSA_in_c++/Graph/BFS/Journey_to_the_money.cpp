#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// global variable 
vector<vector<int>>g;
vector<int>vis;
int cmp_cc;
// traversal algorithm dfs
void dfs(int node)
{
    cmp_cc++;
    vis[node] = 1;
    for(auto v: g[node])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}
void solve()
{
	// input section
    int n,m;
    cin>>n>>m;
    vis.assign(n+1,0);
    g.resize(n+1);
    // convert edge list into adjancy list
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        // for undirected edge
        g[b].push_back(a);
    }
    // logic section
    vector<long long>cmp_cc_array;
    for(int i=1;i<=n;i++){
        if(!vis[i])
        {
            cmp_cc=0;
            dfs(i);
            cmp_cc_array.push_back(cmp_cc);
        }
    }
    // after making the array of size of connected component we are going to apply mathematics on that
    long long sum = accumulate(cmp_cc_array.begin(),cmp_cc_array.end(),0);
    long long ans = 0;
    for(auto v: cmp_cc_array)
    {
        ans += v*v;
    }
    long long finalAns = ((sum*sum)-ans)/2;
    cout<<finalAns<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
    return 0;
}
