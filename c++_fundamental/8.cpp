#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> Q[i];
    }

    // Check if all coins have the same number on both sides
    bool allSame = true;
    for (int i = 0; i < N; ++i) {
        if (P[i] != Q[i]) {
            allSame = false;
            break;
        }
    }

    if (allSame) {
        // Each number is only covered by its own coin
        cout << 1 << '\n';
        return 0;
    }

    // Build adjacency list
    vector<vector<pair<int, int>>> adj(N + 1); // to (node, coin index)
    for (int i = 0; i < N; ++i) {
        int u = P[i];
        int v = Q[i];
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    vector<bool> visited_node(N + 1, false);
    vector<bool> visited_edge(N, false);
    long long result = 1;

    for (int u = 1; u <= N; ++u) {
        if (!visited_node[u]) {
            queue<int> q;
            q.push(u);
            visited_node[u] = true;
            int node_count = 0;
            int edge_count = 0;

            while (!q.empty()) {
                int v = q.front();
                q.pop();
                node_count++;

                for (auto [neighbor, coin] : adj[v]) {
                    if (!visited_edge[coin]) {
                        visited_edge[coin] = true;
                        edge_count++;
                        if (!visited_node[neighbor]) {
                            visited_node[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }

            if (node_count == edge_count) {
                // cycle
                if (node_count == 1) {
                    // self-loop
                    result = result * 1 % MOD;
                } else {
                    result = result * (edge_count + 1) % MOD;
                }
            } else if (node_count == edge_count + 1) {
                // tree
                result = result * 1 % MOD;
            } else {
                result = 0;
            }
        }
    }

    cout << result << '\n';

    return 0;
}