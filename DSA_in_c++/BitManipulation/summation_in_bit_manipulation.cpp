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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    long long ans = 0;
    for (int j = 0; j < 31; ++j) {
        long long cnt1 = 0;
        for (int x : a)
            if ((x >> j) & 1) ++cnt1;
        long long cnt0 = n - cnt1;

        // each differing ordered pair contributes (1<<j)
        long long contrib = 2LL * cnt0 * cnt1 * (1LL << j);
        ans += contrib;
    }

    cout << ans << "\n";
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