#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int INF = 100;
using state = pair<int,int>; // we can also take this name as cooordinate 
// global variable
int n,m;
vector<string>arr; // if space is not between string
vector<vector<char>>arr2; // if space is given 
// traversal algorithm -BFS
vector<vector<int>>vis;
vector<vector<int>>dist;
// now check function for this
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

// now for neighburs -- basically how to move in four direction
int dx[] = {1, 0, -1, 0}; // down, right, up, left
int dy[] = {0, 1, 0, -1};
vector<state>neighbours(state cur)
{
	vector<state>ans;
	for(int k=0;k<4;k++)
	{
		int nx = cur.F+dx[k];
		int ny = cur.S+dy[k];
		if(check(nx,ny)&&arr2[nx][ny]!='#')
		{
			ans.push_back({nx,ny});
		}
	}
	return ans;
}
void bfs(state start_node)
{
	vis.assign(n,vector<int>(m,0));
	dist.assign(n,vector<int>(m,100));
	queue<state>q;
	vis[start_node.F][start_node.S] = 1;
	dist[start_node.F][start_node.S] = 0;
	q.push(start_node);
	while(!q.empty())
	{
		state cur_node = q.front();
		q.pop();
		for(state v: neighbours(cur_node))
		{
			if(!vis[v.F][v.S])
			{
				vis[v.F][v.S] = 1;
				dist[v.F][v.S] = dist[cur_node.F][cur_node.S]+1;
				q.push(v);
			}
		}
	}
}

void solve()
{
	// input section 
	cin>>n>>m;
	arr2.resize(n+1);
	state start,end;
	for(int i=0;i<n;i++)
	{
		arr2[i].resize(m+1);
		for(int j=0;j<m;j++)
		{
			cin>>arr2[i][j];
			// for the faster 
			if(arr2[i][j]=='S')
			{
				start = {i,j};
			}
			else if(arr2[i][j]=='F')
			{
				end = {i,j};
			}
		}
	}

	// logic section
	bfs(start);
	// printing kind of thing
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<dist[i][j]<<"\t";
		}
		cout<<endl;
	}
	// 
	if(!vis[end.F][end.S])
	{
		cout<<"Finish is not reachable"<<endl;
	}
	else
	{
		cout<<dist[end.F][end.S]<<endl;
	}
}

// 

signed main()
{
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