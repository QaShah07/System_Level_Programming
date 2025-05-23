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
	if(x>=0 && x<n && y>=0 && y<m)
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
vector<state> neighbours(state cur, bool skip_value_check = false)
{
	vector<state>ans;
	for(int k=0;k<4;k++)
	{
		int nx = cur.F+dx[k];
		int ny = cur.S+dy[k];
		if(check(nx,ny) && (skip_value_check || eg[nx][ny]==0))
		{
			ans.push_back({nx,ny});
		}
	}
	return ans;
}

void bfs(state start_node)
{
	queue<state>q;
	vis[start_node.F][start_node.S] = 2;
	q.push(start_node);
	// first we are going to compute the size
	int sz = 1;
	while(!q.empty())
	{
		state cur_node = q.front();
		q.pop();
		for(auto v: neighbours(cur_node))
		{
			if(!vis[v.F][v.S])
			{
				vis[v.F][v.S] = 2, sz++;
				q.push(v);
			}
		}
	}
	// now 2nd time BFS
	vis[start_node.F][start_node.S] = 1;
	if(sz ==1)
	{
		return;
	}
	eg[start_node.F][start_node.S] = sz;
	q.push(start_node);
	while(!q.empty())
	{
		state cur_node = q.front();
		q.pop();
		for(auto v: neighbours(cur_node,true))
		{
			if(vis[v.F][v.S]==2)
			{
				vis[v.F][v.S] = 1,eg[v.F][v.S] = sz;
				q.push(v);
			}
		}
	}
}

// travesal algorithm - BFS

void solve()
{
	// input section
	cin>>n>>m;
	eg.assign(n, vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>eg[i][j];
		}
	} 

	// logic section
	vis.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (eg[i][j] == 1)
			vis[i][j] = 1; // Treat wall as already processed
		}
	}
	cout<<"\n";

	// now some terminolgy
	// 0 -> not visited, 1 -> completed , 2->visited but not completed
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j])
			{
				bfs({i,j});
			}
		}
	}



	// for printing 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<eg[i][j]<<" ";
		}
		cout<<endl;
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
