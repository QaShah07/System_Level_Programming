#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

using state = pair<int, int>;
int n, m;
vector<vector<int>> a;
vector<vector<int>> vis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(state x) {
    return x.f >= 0 && x.f < n && x.s >= 0 && x.s < m && a[x.f][x.s] == 0 && vis[x.f][x.s] == 0;
}

vector<state> neigh(state st_node) {
    vector<state> neighbour;
    for (int k = 0; k < 4; k++) {
        int x = st_node.f + dx[k], y = st_node.s + dy[k];
        if (isvalid({x, y})) neighbour.push_back({x, y});
    }
    return neighbour;
}

void bfs(state st) {
    queue<state> q;
    vector<state> component;  
    q.push(st);
    vis[st.f][st.s] = 1;  
    component.push_back(st);

    while (!q.empty()) {
        state node = q.front();
        q.pop();
        for (state v : neigh(node)) {
            vis[v.f][v.s] = -1; // temporary mark
            q.push(v);
            component.push_back(v);
        }
    }

    int size = component.size();
    for (auto cell : component) {
        vis[cell.f][cell.s] = (size == 1 ? 0 : size);
    }
}

void Solve() {
    a.clear();
    vis.clear();

    cin >> n >> m;
    a.resize(n, vector<int>(m));
    vis.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && vis[i][j] == 0) {
                bfs({i, j});
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << " ";
            cout << (a[i][j] == 1 ? 1 : vis[i][j]);
        }
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) Solve();
}