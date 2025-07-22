#include <bits/stdc++.h>
using namespace std;
// Self use terminology
#define ll long long
#define ld long double
#define F first
#define S second
using state = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const int MOD = 1e9 + 7;
// Global variables (if any)
vvi g;
vi subtreeSize;
int n;
ll ans = 0;
// Traversal Algorithm : DFS
void dfs(int node, int parent, int depth)
{
  subtreeSize[node] = 1;
  for (auto v : g[node])
  {
    if (v != parent)
    {
      dfs(v, node, depth + 1);
      subtreeSize[node] += subtreeSize[v];
    }
  }
  ans += 1LL * (n - subtreeSize[node]) * subtreeSize[node];
}
void solve()
{
  // Input section
  cin >> n;
  g.resize(n + 1);
  subtreeSize.resize(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  // Logic section
  dfs(1, 0, 0);
  cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t_ = 1;
  // cin >> t_;
  for (int i = 0; i < t_; i++)
  {

    solve();
  }
  return 0;
}