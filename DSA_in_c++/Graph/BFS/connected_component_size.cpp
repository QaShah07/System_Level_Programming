#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
using state = pair<int,int>;
// global variable 
int n,m;
vector<vector<int>>vis;
vector<vector<int>>eg; // this is integer 
// check funtion
bool check(int x, int y)
{
	if(x>=0 && x<n && y>=0 && y<m && vis[x][y] ==0 && eg[x][y]==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// neighbour funtion which decide how to move
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<state> neighbours(state cur)
{
	vector<state>ans;
	for(int k=0;k<4;k++)
	{
		int nx = cur.F+dx[k];
		int ny = cur.S+dy[k];
		if(check(nx,ny))
		{
			ans.push_back({nx,ny});
		}
	}
	return ans;
}

void bfs(state start_node)
{
	queue<state>q;
	vector<state>component;
	q.push(start_node);
	component.push_back(start_node);
	vis[start_node.F][start_node.S] = 1;
	// first we are going to compute the size
	int sz = 1;
	while(!q.empty())
	{
		state cur_node = q.front();
		q.pop();
		for(auto v: neighbours(cur_node))
		{
			vis[v.F][v.S] = -1; // tempory mark
			q.push(v);
			component.push_back(v);
		}
	}
	// now 2nd time BFS
	int size = component.size();
	for (auto cell : component) {
        vis[cell.F][cell.S] = (size == 1 ? 0 : size);
    }
}

// travesal algorithm - BFS

void solve()
{
	eg.clear();
	vis.clear();
	// input section
	cin>>n>>m;
	eg.resize(n,vector<int>(m));
	vis.assign(n, vector<int>(m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>eg[i][j];
		}
	} 

	// logic section
	

	// now some terminolgy
	// 0 -> not visited, 1 -> completed , 2->visited but not completed
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vis[i][j]==0 && eg[i][j]==0)
			{
				bfs({i,j});
			}
		}
	}



	// for printing 
	// Print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << " ";
            cout << (eg[i][j] == 1 ? 1 : vis[i][j]);
        }
        cout << endl;
    }
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
    return 0;
}