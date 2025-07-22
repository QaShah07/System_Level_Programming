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
int n;
vector<bool>is_prime;
void isPrime(int n)
{
	is_prime.assign(n+1,true);
	is_prime[0] = is_prime[1] = false;
	for(int i=2;i<=n;i++)
	{
		if(is_prime[i] && (long long)i*i<=n)
		{
			for(int j=i*i;j<=n;j+=i)
			{
				is_prime[j] = false;
			}
		}
	}
}
void solve() {
    // Input section
	cin>>n;
    // Logic section
    isPrime(n);
    for(int i=2;i<=n;i++)
    {
    	if(is_prime[i])
    	{
    		cout<<i<<" "; 
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