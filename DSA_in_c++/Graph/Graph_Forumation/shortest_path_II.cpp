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

int n,m,q;
void solve() {
    // Input section
    cin>>n>>m>>q;
    ll dist[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[i][j] = 1e18;
        }
        dist[i][i] = 0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        dist[a][b] = dist[b][a] = min(dist[a][b],1LL*d);
    }

    // Logic section
    // algorithm Floyd warshel
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    // w
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==1e18)cout<<"-1\n";
        else cout<<dist[a][b]<<"\n";
    }
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
