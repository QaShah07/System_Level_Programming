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
// base case
int rec(int level)
{
	// pruning
	if(level>n)
	{
		return 0;
	}
	// base case
	if(level==n)
	{
		return 1;
	}
	// check
	// Move
	int ans = 0;
	for(int step = 1;step<=3;step++)
	{
		if(level+step<=n)
		{
			ans +=rec(level+step);
		}
	}
	return ans;

}
void solve() {
    // Input section
    cin>>n;

    // Logic section
    cout<<rec(1)<<endl;
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