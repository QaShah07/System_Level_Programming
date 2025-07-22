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
vvi eg;
vvi vis;
vvi costs;
// algorithm BFS01
bool check(int x, int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// 
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs01(state st)
{
    deque<pair<int,state>>dq;
    dq.push_back({0,st});
    while(!dq.empty())
    {
        int cur  = dq.front();
        dq.pop_front();
        int cost = cur.F;
        int x = cur.S.F;
        int y = cur.S.S;
        // now iterate
        for(int i =1;i<=4;i++)
        {
            int nx = x+dx[i-1];
            int ny = y+dy[i-1];
            if(!check(nx,ny)) continue;
            if(g[x][y]==i)
            {
                if(costs[nx][ny]==-1 || costs[nx][costs]>cost+0)
                {
                    costs[nx][ny] = cost+0;
                    dq.push_front({costs[nx][ny],{nx,ny}});
                }
            }
            else
            {
                if(costs[nx][ny]==-1 || costs[nx][ny]>cost+1)
                {
                    costs[nx][ny] = cost+1;
                    dq.push_back({costs[nx][ny],{nx,ny}});
                }
            }

        }
    }

}
void solve() {
    // Input section
    cin>>n>>m;
    eg.resize(n,vi(m));
    vis.assign(n,vi(m,0));
    costs.assign(n,vi(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int j-0;j<m;j++)
        {
            cin>>eg[i][j];
        }
    }
    // Logic section
    bfs01({0,0});
    cout<<dist[n-1][m-1]<<"\n";
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
