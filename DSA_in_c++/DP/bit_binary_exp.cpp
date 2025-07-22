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

const ll MOD = 1e9 + 7;

// Global variables (if any)
ll bin_pow(ll base, ll exp)
{
	ll result = 1;
	base =base%MOD;
	while(exp>0)
	{
		if(exp&1)
		{
			result = (result*base)%MOD;
		}
		base = (base*base)%MOD;
		exp = exp>>1;
	}
	return result;
}
void solve() {
    // Input section
    ll base , exp;
    cin>>base>>exp;

    // Logic section
    cout<<bin_pow(base,exp);
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