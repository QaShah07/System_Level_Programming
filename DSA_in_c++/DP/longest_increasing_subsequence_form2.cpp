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
int arr[10010];
int dp[10010];

// recursive funtion
int rec(int i)
{
	// pruning
	if(i<0) return 0;

	// cache check
	if(dp[i]!=-1)
	{
		return dp[i];
	}

	// Compute/transition
	int ans = 1; // count the current element
	for(int prev_taken = 0; prev_taken < i; prev_taken++)
	{
		if(arr[prev_taken] < arr[i])
		{
			ans = max(ans, 1 + rec(prev_taken));
		}
	}

	// save and return
	return dp[i] = ans; 
}

void solve() {
    // Input section
    cin >> n;
    for(int i = 0; i < n; i++)
    {
    	cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));

    // Logic section
    int best  = 0;
    for(int i = 0; i < n; i++)
    {
    	best = max(best, rec(i));
    }
    cout << best << endl;
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
