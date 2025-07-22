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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<ll> v(n);
    for (ll &val : v) cin >> val;

    // Step 1: Max subarray sum of segments with '1'
    ll maxSubSum = 0, currSum = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') {
            currSum = max(currSum + v[i], v[i]);
            maxSubSum = max(maxSubSum, currSum);
        } else {
            currSum = 0;
        }
    }

    if (maxSubSum > k) {
        cout << "NO\n";
        return;
    }

    if (maxSubSum == k) {
        cout << "YES\n";
        for (ll i = 0; i < n; ++i) {
            if (s[i] == '0') v[i] = -1e18;
        }
        for (ll val : v) cout << val << " ";
        cout << "\n";
        return;
    }

    // Step 2: Try to insert a single '0' element to make sum equal to k
    ll zeroIdx = -1;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '0') {
            zeroIdx = i;
            break;
        }
    }

    if (zeroIdx == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    // Compute max prefix sum to the left of zeroIdx (within '1's)
    ll maxLeftSum = 0, sum = 0;
    for (ll i = zeroIdx - 1; i >= 0 && s[i] == '1'; --i) {
        sum += v[i];
        maxLeftSum = max(maxLeftSum, sum);
    }

    // Compute max suffix sum to the right of zeroIdx (within '1's)
    ll maxRightSum = 0;
    sum = 0;
    for (ll i = zeroIdx + 1; i < n && s[i] == '1'; ++i) {
        sum += v[i];
        maxRightSum = max(maxRightSum, sum);
    }

    // Assign value to v[zeroIdx] to reach exact sum k
    v[zeroIdx] = k - maxLeftSum - maxRightSum;

    // Set all other '0' positions to very negative to invalidate them
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '0' && i != zeroIdx) {
            v[i] = -1e18;
        }
    }

    for (ll val : v) cout << val << " ";
    cout << "\n";
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
