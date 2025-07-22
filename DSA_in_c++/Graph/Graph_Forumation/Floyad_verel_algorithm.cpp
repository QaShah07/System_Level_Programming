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
int dist[404][404];

void solve() {
    // Input section
    cin>>n>>m;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j) dist[i][j] = 1e9;
            }
        }
    for(int i=0;i<m;i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        dist[a][b] = min(dist[a][b],d);
    }

    // Logic section
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
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
