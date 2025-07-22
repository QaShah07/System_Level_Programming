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
vector<int>g[100100];
int ans[100100];
int val[100100];
// DFS alogrithm  /// for Maximum value of ancestor
void dfs(int node, int parent, int maxVal, int minVal)
{
	ans[node] = max(abs(maxVal-val[node]),abs(minVal-val[node]));
	for(auto v: g[node])
	{
		if(v != parent)
		{
			dfs(v,node,abs(maxVal-val[node]),abs(minVal-val[node]));
		}
	}

}


void solve() {
    // Input section

    // Logic section
    dfs(root,0,-1e9,1e9);
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