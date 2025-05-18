#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int INF =100;
using state = pair<int,int>; // we can take this name as coordinate 

/*
6 6
S . # . . .
. . # . . .
# . # . # .
. . . . # .
# # # # . .
F . . . . .
*/

// global variable
int n, m;
vector<string>arr; //if space is not between string
vector<vector<char>>arr2; // if space is between string

// this is for condition how can he visit for valid neighbours
bool check(int x , int y)
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
// Now for Traversal for algorithm
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
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

// Now traversal algorithm BFS
vector<vector<int>>vis;
vector<vector<int>>dis;
void bfs(state start_node)
{
	vis.assign(n,vector<int>(m,0));
	dis.assign(n,vector<int>(m,INF));
	// now queue for storing the visiting kind of thing
	queue<state>q;
	vis[start_node.F][start_node.S] = 1;
	dis[start_node.F][start_node.S] = 0;
	q.push(start_node);
	// now basically loopoing who can manage everything
	while(!q.empty())
	{
		state cur_node = q.front();
		q.pop();
		for(state v: neighbours(cur_node))
		{
			if(!vis[v.F][v.S])
			{
				vis[v.F][v.S] = 1;
				dis[v.F][v.S] = dis[cur_node.F][cur_node.S]+1;
				q.push(v);
			}
		}
	}
}

// sovle fucntion
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
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<dis[i][j]<<"\t";
		}
		cout<<endl;
	}
	if(!vis[end.F][end.S])
	{
		cout<<"Finish is Not reachable\n";
	}
	else
	{
		cout<<dis[end.F][end.S]<<endl; // this print the shortes path
	}
}

// main function
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


































