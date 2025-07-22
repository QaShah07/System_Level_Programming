#include <bits/stdc++.h>
using namespace std;

using state = pair<int,int>;
#define F first
#define S second
const int INF = 1e9;

int n,m;
vector<string> arr;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool inside(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)return 1;
    return 0;
}

vector<vector<int>> dist,vis;

void bfs01(state st){
    vis = vector<vector<int>>(n,vector<int>(m,0));
    dist = vector<vector<int>>(n,vector<int>(m,INF));
    
    deque<state> dq;
    dist[st.F][st.S] = 0;
    dq.push_back(st);
    
    while(!dq.empty()){
        state cur = dq.front(); dq.pop_front();
        // process once.
        if(vis[cur.F][cur.S])continue;
        vis[cur.F][cur.S]=1;
        // process the node.
        for(int dir = 0;dir<4;dir++){
            int nx = cur.F + dx[dir];
            int ny = cur.S + dy[dir];
            if(inside(nx,ny)){ // valid check
                int edge = (arr[nx][ny]=='#'?1:0);
                if(dist[nx][ny]>dist[cur.F][cur.S]+edge){ // edge relax
                    dist[nx][ny]=dist[cur.F][cur.S]+edge;
                    // 0-1 BFS
                    if(edge==0){
                        dq.push_front({nx,ny});
                    }else{
                        dq.push_back({nx,ny});
                    }
                }
            }
            
        }
    }
}
/*
6 5
S#...
.#.#.
...#.
####.
####.
.E...
*/


int main()
{
    cin>>n>>m;
    arr.resize(n);
    state st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S')st={i,j};
            else if(arr[i][j]=='E')en={i,j};
        }
    }
    bfs01(st);
    cout<<dist[en.F][en.S]<<endl;
}