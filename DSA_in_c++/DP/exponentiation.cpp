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
// function for exponenetiona
ll bin_pow(ll base,ll exp)
{
	if(exp==0)
	{
		return 1;
	}
	if(exp&1)
	{
		return base*(bin_pow(base,exp-1))%MOD;
	}
	else
	{
		ll temp = bin_pow(base,exp/2)%MOD;
		return temp*temp%MOD;
	}
}

void solve() {
    // Input section
    ll base, exp;
    cin>>base>>exp;

    // Logic section
    cout<<bin_pow(base,exp)<<"\n";
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