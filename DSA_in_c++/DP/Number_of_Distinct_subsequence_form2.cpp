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
    // Input section
    int n;
    string s;
    cin >> s;
    n = s.length();

    // Logic section
    int prefix[n+1];
    int last[26];
    int dp[n+1];
    memset(last, -1, sizeof(last));

    dp[0] = 1; // unique subsequence ending at i-1 (empty string)
    prefix[0] = 1; // sum of subsequences till index -1

    for(int i = 1; i <= n; i++) {
        dp[i] = prefix[i-1]; // add all subsequences before i

        if(last[s[i-1] - 'a'] != -1) {
            int idx = last[s[i-1] - 'a'];
            dp[i] = (dp[i] - prefix[idx] + MOD) % MOD; // remove duplicates
        }

        last[s[i-1] - 'a'] = i - 1; // update last seen index
        prefix[i] = (prefix[i-1] + dp[i]) % MOD; // build prefix sum
    }

    cout << (prefix[n] - 1 + MOD) % MOD << endl; // exclude empty subsequence
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
