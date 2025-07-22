#include <bits/stdc++.h>
using namespace std;

// Self use terminology
#define ll long long
#define ld long double
#define F first
#define S second

using state = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

// Global variables (if any)
int n;
vvi dist;
vi vis;
vi ans;
void solve() {
    // First, read n
    cin >> n;

    // Now resize
    dist.resize(n, vi(n));
    vis.assign(n, 0);

    // Read adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];

    vi order(n);
    for(int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;
    }

    reverse(order.begin(), order.end());
    for(int k = 0; k < n; k++) {
        int x = order[k];
        vis[x] = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);

        int sum = 0;
        for(int i = 0; i < n; i++) {
            if (!vis[i]) continue;
            for(int j = 0; j < n; j++) {
                if (!vis[j]) continue;
                sum += dist[i][j];
            }
        }
        ans.push_back(sum);
    }

    for(auto it : ans)
        cout << it << " ";
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t_ = 1;
    // cin >> t_;
    for (int i = 0; i < t_; i++) {
        solve();
    }

    return 0;
}
