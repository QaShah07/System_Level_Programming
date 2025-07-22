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
const int MOD = 1e9;
const int MAXN = 5050;
int catlan[MAXN];
// Recursive funtion
void rec(int i)
{
	// pruning
	// base case
	if(i==0 || i==1)
	{
		catlan[i] = 1;
	}
	// cache check
	// Compute and transtion
	int ans = 0;
	ans = rec(i+1);
	// save and return 
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