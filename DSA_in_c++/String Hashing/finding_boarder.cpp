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
struct hasher {
	int base, mod;
	vector<ll>hash,basepow;
	hasher(string s, int _base, int _mod)
	{
		base = _base;
		mod = _mod;
		int n = s.length();
		hash.resize(n+1);
		basepow.resize(n+1);
		hash[0] = 0;
		basepow[0] = 1;
		for(int i=1;i<=n;i++)
		{
			hash[i] = ( (ll)hash[i-1] * base % mod
            + (s[i-1] - 'a' + 1) ) % mod;
			basepow[i] = basepow[i-1]*base%mod; 
		}
	}
	// Now getHash l..... to r
	// 0 based indes
	int getHash(int l, int r) {
    // bring both terms into ℤ_mod
    ll sub = (hash[l] * basepow[r - l + 1]) % mod;
    ll ans = (hash[r + 1] - sub + mod) % mod;
    return (int)ans;
}


};

void solve() {
    // Input section
	string s;
	cin>>s;
	int n = s.length();
	hasher shash(s,37,1e9+7);
	for(int len =1;len<n;len++)
	{
		if(shash.getHash(0,len-1)==shash.getHash(n-len,n-1))
		{
			cout<<len<<"\n";
		}
	}
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