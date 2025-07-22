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
int n,m;
int mat[205][205];
int dp[210][210][410];

int rec(int i,int j, int k_left)
{
	// pruning 
	if(i >= n || j >= m || k_left < 0) return 0;

	// base case
	if(i == n - 1 && j == m - 1)
	{
		if(mat[i][j] == 0 || k_left > 0) return 1;
		return 0;
	}

	// cache check 
	if(dp[i][j][k_left] != -1)
	{
		return dp[i][j][k_left];
	}

	// Compute/Transition
	int ans = 0;
	if (mat[i][j] == 0)
	{
		ans = (rec(i + 1, j, k_left) % MOD + rec(i, j + 1, k_left) % MOD) % MOD;
	}
	else
	{
		ans = (rec(i + 1, j, k_left - 1) % MOD + rec(i, j + 1, k_left - 1) % MOD) % MOD;
	}

	// Save and Return
	return dp[i][j][k_left] = ans % MOD;
}

void solve() {
	// Input section
	int k_left;
	cin >> n >> m >> k_left;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			for(int k = 0; k <= k_left; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}

	// Logic section
	cout << rec(0, 0, k_left) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t_ = 1;
	cin >> t_;
	for (int i = 0; i < t_; i++) {
		solve();
	}

	return 0;
}
