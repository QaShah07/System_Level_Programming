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

    // Create a mapping from number to its coin index (since each number appears exactly once in P and Q)
    // But actually, each coin is (P[i], Q[i]), so for each number, we need to find coins that have it in P or Q.
    // We'll build an adjacency list where each number points to the coins (as edges) that include it.
    // But since coins are edges between P[i] and Q[i], the problem is to select edges covering all nodes.

    vector<vector<pair<int, int>>> adj(N + 1); // number -> list of (neighbor, coin index)
    for (int i = 0; i < N; ++i) {
        int u = P[i];
        int v = Q[i];
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    vector<bool> visited(N + 1, false);
    vector<bool> edge_used(N, false);
    long long result = 1;

    for (int u = 1; u <= N; ++u) {
        if (!visited[u]) {
            queue<int> q;
            q.push(u);
            visited[u] = true;
            int node_count = 0;
            int edge_count = 0;
            set<int> edges;

            while (!q.empty()) {
                int v = q.front();
                q.pop();
                node_count++;

                for (auto [neighbor, coin] : adj[v]) {
                    if (!edge_used[coin]) {
                        edge_used[coin] = true;
                        edges.insert(coin);
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }

            edge_count = edges.size();
            if (edge_count == node_count) {
                // It's a tree; the number of ways is 1 (must take all edges)
                // But wait, for a tree with m edges (m = node_count -1), the number of subsets is 1?
                // Or is it node_count? Need to re-examine.
                // For a tree, the number of valid subsets is 1 (only the entire set of edges covers all nodes).
                // But sample 1 suggests that for a tree-like structure (coins 1-3), there are 3 subsets.
                // So perhaps the connected component is a cycle.
                // So need to check if the component is a cycle or a tree.
                // Alternatively, the answer for a connected component is 2 if it's a cycle (2^(cycle_length) - something).
                // Revisiting sample 1: The three coins form a cycle (1-2-3-1 via coins 1, 2, 3). The valid subsets are any subset that covers all nodes, which for a cycle of m edges is 2^m - mC0 - mC1 - ... - mC(m-1) + ...? Or more precisely, the number of subsets that are edge covers is 2 for a cycle (take all edges or alternate edges in even cycle).
                // But sample 1 has 3 valid subsets: {1,3}, {2,3}, {1,2,3}. So for a triangle, it's 3. So the formula for a cycle of m edges is m.
                // So for a connected component that's a cycle, the number of valid subsets is the size of the cycle (number of edges).
                // For a tree, it's 1 (only all edges).
                // So need to check whether the component is a tree or a cycle.
                // A tree has node_count = edge_count + 1. A cycle has node_count == edge_count.
                if (node_count == edge_count) {
                    // cycle
                    result = result * 2 % MOD;
                } else {
                    // tree
                    result = result * node_count % MOD;
                }
            } else if (edge_count == node_count - 1) {
                // tree
                result = result * 1 % MOD;
            } else {
                // multiple edges or other structures, but per problem statement, each number appears exactly once in P and Q, so each node has degree 2, implying the graph is a collection of cycles.
                // So this case shouldn't happen.
                result = 0;
            }
        }
    }

    cout << result << '\n';

    return 0;
}