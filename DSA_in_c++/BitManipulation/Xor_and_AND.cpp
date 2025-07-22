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
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    // Logic section
    vector<ll>cntOnes(31,0);
    int orAll = 0;
    for(int x: a)
    {
    	orAll |=x;
    	for(int b=0;b<31;b++)
    	{
    		if(x&(1<<b))
    		{
    			cntOnes[b]++;
    		}
    	}
    }

    // Now as per requirements of Question 
    ll sumXorPairs = 0;
    ll sumAndPairs = 0;
    ll sumXorSubsets = 0;
    ll sumAndSubsets = 0;
    // precomute the power of two
    vector<ll>pow2(n+1,1);
    for(int i=1;i<=n;i++)
    {
    	pow2[i] = (pow2[i-1]*2)%MOD;
    }
    // now we are going to process Each bits
    for(int b=0;b<31;b++)
    {
    	ll ones = cntOnes[b];
    	ll zeros = n-ones;
    	ll bitVal = (1LL<<b)%MOD;
    	// 1) sum of XOR over pairs: each pair (i<j) with differing bits
            //    contributes (1<<b), and there are ones*zeros such unordered pairs
    	ll xorPairs = (ones*zeros)%MOD;
    	sumXorPairs = (sumXorPairs+xorPairs*bitVal)%MOD;
    	 // 2) sum of AND over pairs: each pair (i<j) with both bits=1
            //    contributes (1<<b), and there are C(ones,2) of those
        ll andPairs = 0;
    	if(ones>=2)
    	{
    		andPairs  = (ones*(ones-1)/2)%MOD;
    		sumAndPairs = (sumAndPairs+andPairs*bitVal)%MOD;
    	}
    	  // 4) sum of AND over all non-empty subsets:
            //    a subset’s AND has bit b = 1 iff it’s chosen entirely from the
            //    ’ones’ elements, and non-empty subsets count = 2^ones – 1
    	ll andSubsets = (pow2[ones]+MOD-1)%MOD;
        sumAndSubsets = (sumAndSubsets + andSubsets * bitVal) % MOD;
    }
     // 3) sum of XOR over all subsets: classical result
        //    = (2^(n-1)) * (OR of all elements)
    sumXorSubsets = ((ll)orAll%MOD*pow2[n-1])%MOD;

     cout
            << sumXorPairs   << ' '
            << sumXorSubsets << ' '
            << sumAndPairs   << ' '
            << sumAndSubsets << '\n';
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