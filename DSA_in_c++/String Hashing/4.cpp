#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS to find articulation points
void dfsAP(int u, int **adj, vector<bool> &visited, vector<int> &disc, 
           vector<int> &low, vector<int> &parent, vector<bool> &isArt, 
           int &timer, int n) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int v = 0; v < n; ++v) {
        if (!adj[u][v]) continue;  // no edge

        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfsAP(v, adj, visited, disc, low, parent, isArt, timer, n);
            low[u] = min(low[u], low[v]);

            // root with ≥2 children is articulation
            if (parent[u] == -1 && children > 1) {
                isArt[u] = true;
            }
            // non-root where low[v] ≥ disc[u] is articulation
            if (parent[u] != -1 && low[v] >= disc[u]) {
                isArt[u] = true;
            }
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void connectedVertex(int **arr, int n) {
    vector<bool> visited(n, false), isArt(n, false);
    vector<int> disc(n, 0), low(n, 0), parent(n, -1);
    int timer = 0;

    // find articulation points
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfsAP(i, arr, visited, disc, low, parent, isArt, timer, n);
    }

    // mark all neighbors of articulation points as Type B
    vector<bool> isB(n, false);
    for (int u = 0; u < n; ++u) {
        if (isArt[u]) {
            for (int v = 0; v < n; ++v) {
                if (arr[u][v] && !isArt[v])
                    isB[v] = true;
            }
        }
    }

    // print them in ascending order
    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (isB[i]) {
            if (!first) cout << ' ';
            cout << i;
            first = false;
        }
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    int **arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    connectedVertex(arr, n);

    // clean up (optional)
    for (int i = 0; i < n; ++i)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
