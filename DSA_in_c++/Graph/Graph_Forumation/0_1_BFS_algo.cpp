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
vector<string>eg;
vvi dist,vis;
// Algorithm BFS01
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
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

void bfs01(state st)
{
    vis.assign(n,vi(m,0));
    dist.assign(n,vi(m,1e9));
    deque<state>dq;
    dist[st.F][st.S] = 0;
    dq.push_back(st);
    while(!dq.empty())
    {
        state cur = dq.front();
        dq.pop_front();
        // process once. this is for safety when becaue in deque node come two times
        if(vis[cur.F][cur.S]) continue;
        vis[cur.F][cur.S] = 1;
        // proceess the node 
        for(int dir = 0; dir<4;dir++)
        {
            int nx = cur.F+dx[dir];
            int ny = cur.S+dy[dir];
            if(check(nx,ny)) // valid check
            {
                int edge = (eg[nx][ny]=='#' ? 1: 0);
                if(dist[nx][ny]>dist[cur.F][cur.S]+edge)
                {
                    dist[nx][ny] = dist[cur.F][cur.S]+edge;
                    // 0-1 BFS
                    if(edge==0)
                    {
                        dq.push_front({nx,ny});
                    }
                    else
                    {
                        dq.push_back({nx,ny});
                    }
                }
            }
        }
    }
}
void solve() {
    // Input section
    cin>>n>>m;
    eg.resize(n);
    state start, end;
    // explicit graph
    for(int i=0;i<n;i++)
    {
        cin>>eg[i];
        for(int j=0;j<m;j++)
        {
            if(eg[i][j]=='S')
            {
                start = {i,j};
            }
            else if(eg[i][j]=='E')
            {
                end = {i,j};
            }
        }
    }
    // Logic section
    bfs01(start);
    cout<<dist[end.F][end.S]<<endl;
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
