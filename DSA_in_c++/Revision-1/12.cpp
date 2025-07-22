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
vector<char>segmentedSeive(ll L, ll R)
{
	// generates all prime upto Sqrt(R)
	// simple sieve to upto √R
	ll lim = floor(sqrt(R));
	vector<char>marks(lim+1,false);
	vector<ll>primes;
	for(ll i = 2;i<=lim;++i)
	{
		if(!marks[i])
		{
			primes.emplace_back(i);
			for(int j=i*i;j<=lim;j+=i)
			{
				marks[j] = true;
			}
		}
	}

	// 2. Assume Everthing in is [L...R] prime
	vector<char>isPrime(R-L+1,true);
	for(ll p: primes)
	{
		// first Multiple of p>=L
		ll start = max(p*p,((L+p-1)/p)*p);
		for(ll j = start;j<=R;j+=p)
		{
			isPrime[j-L] =false;
		}
	}
	// 4. 1 is not Prime
	if(L==1) isPrime[0] = false;
	return isPrime;
}
void solve() {
    // Input section
    ll L,R;
    cin >> L >> R;
    auto isPrime = segmentedSeive(L, R);
    for (long long i = L; i <= R; ++i) {
        if (isPrime[i - L])
            cout << i << " ";
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