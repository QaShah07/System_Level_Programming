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
int val[100100];
int ans[100100];

multiset<int>mt;
void insert(int x)
{
	mt.insert(x);
}
void remove(int x)
{
	mt.erase(mt.find(x));
}
int query(int x)
{
	int ans = 1e9; // because we wnat to process minimum value
	auto it = mt.lower_bound(x);
	// now process for the minimum value
	if(it != mt.end())
	{
		ans = min(ans,abs(*it-x));
	}
	if(it != mt.begin())
	{
		it--;
		ans = min(ans,abs(*it-x));
	}
	return ans;

}
// DFS algorithm min
void dfs(int node ,int parent)
{
	ans[node] = query(val[node]);
	insert(val[node]);
	for(auto v: g[node])
	{
		if(v!=parent)
		{
			dfs(v,node);
		}
	}
	remove(val[node]);
}

void solve() {
    // Input section

    // Logic section
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