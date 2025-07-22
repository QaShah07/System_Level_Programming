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

int n;
int arr[10010];
int dp[10010];
int parent[10010];  // to reconstruct the LIS path

// recursive function: returns LIS length ending at index i
int rec(int i)
{
	if (i < 0) return 0;

	if (dp[i] != -1)
		return dp[i];

	int ans = 1;
	parent[i] = -1;

	for (int prev_taken = 0; prev_taken < i; prev_taken++)
	{
		if (arr[prev_taken] < arr[i])
		{
			int candidate = 1 + rec(prev_taken);
			if (candidate > ans)
			{
				ans = candidate;
				parent[i] = prev_taken;  // track previous element
			}
		}
	}
	return dp[i] = ans;
}

// Function to generate the actual LIS sequence
vector<int> generateLIS() {
	int bestLength = 0, bestIndex = -1;

	for (int i = 0; i < n; i++) {
		if (dp[i] > bestLength) {
			bestLength = dp[i];
			bestIndex = i;
		}
	}

	vector<int> lis;
	while (bestIndex != -1) {
		lis.push_back(arr[bestIndex]);
		bestIndex = parent[bestIndex];
	}
	reverse(lis.begin(), lis.end());
	return lis;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	memset(parent, -1, sizeof(parent));

	int best = 0;
	for (int i = 0; i < n; i++)
		best = max(best, rec(i));

	cout << "LIS Length: " << best << '\n';

	vector<int> sequence = generateLIS();
	cout << "LIS Sequence: ";
	for (int x : sequence) cout << x << ' ';
	cout << '\n';
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
