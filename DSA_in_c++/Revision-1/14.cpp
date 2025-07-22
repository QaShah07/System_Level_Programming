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
// Struct Data carrier for each subtree
struct Info {
	int SubtSize;
	ll maxima1, maxima2, maxima3;
	ll minima1, minima2;
	Info(ll v = 0)
	{
		SubtSize = 1;
		maxima1 = minima1 = v;
		maxima2 = maxima3 = LLONG_MIN;
		minima2 = LLONG_MAX;
	}
};
//  
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