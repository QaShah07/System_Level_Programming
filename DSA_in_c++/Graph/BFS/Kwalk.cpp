#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
using state = pair<int,int>;

// global variable
int n, m;
// vector<vector<char>> eg;
vector<vector<int>> vis;
// vector<vector<int>> move_;

// check function 
bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

// neighbour moves of a knight
int dx[] = {2,2,1,-1,-2,-2,-1,1};
int dy[] = {1,-1,2,2,1,-1,-2,-2};

vector<state> neighbours(state cur) {
	vector<state> ans;
	for(int k = 0; k < 8; k++) {
		int nx = cur.F + dx[k];
		int ny = cur.S + dy[k];
		if (check(nx, ny) && vis[nx][ny]==-1) {
			ans.push_back({nx, ny});
		}
	}
	return ans;
}

// BFS traversal
void bfs(state start_node,state end_node) {
	queue<state> q;
	// vis[start_node.F][start_node.S] = 1;
	// move_[start_node.F][start_node.S] = 0;
	vis[start_node.F][start_node.S] = 0;
	q.push(start_node);

	while(!q.empty()) {
		state cur_node = q.front(); 
		q.pop();
		if (cur_node == end_node) return;
		for (state v : neighbours(cur_node)) {
			if (!vis[v.F][v.S]) {
				// vis[v.F][v.S] = 1;
				// move_[v.F][v.S] = move_[cur_node.F][cur_node.S] + 1;
				vis[v.F][v.S] = vis[cur_node.F][cur_node.S] + 1;
				q.push(v);
			}
		}
	}
}

void solve(int n_, int m_, int Sx, int Sy, int Fx, int Fy) {
	// 0-based indexing
	Sx--; Sy--; Fx--; Fy--;

	vis.clear(); 

	// initialize
	n = n_; m = m_;
	// eg.resize(n, vector<char>(m, '.'));
	vis.assign(n, vector<int>(m, -1));
	// move_.assign(n, vector<int>(m, 1000));
	eg[Sx][Sy] = 'S';
	eg[Fx][Fy] = 'F';

	bfs({Sx, Sy},{Fx,Fy});
	// print
	
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << move_[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	

	// Final answer
	// if (!vis[Fx][Fy]) {
	// 	cout << -1 << endl;
	// } else {
	// 	cout << move_[Fx][Fy] << endl;
	// }
	cout << vis[Fx][Fy] << endl;

}

void KnightWalk(int N, int Sx, int Sy, int Fx, int Fy) {
	solve(N, N, Sx, Sy, Fx, Fy);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	cin >> test_case;

	while (test_case--) {
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;
		KnightWalk(N, Sx, Sy, Fx, Fy);
	}
}