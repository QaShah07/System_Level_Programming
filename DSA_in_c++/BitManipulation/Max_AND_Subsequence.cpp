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
	int n,x;
	cin>>n>>x;
	vector<int>arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int ans = 0;
	for(int i=29;i>=0;i--) // highest bit to lowest bit
	{
		vector<int>elementSetBits;
		for(auto v: arr)
		{
			if(v&(1<<i))
			{
				elementSetBits.push_back(v);
			}
		}
		if(elementSetBits.size()>=x)
		{
			ans +=(1LL<<i);
			arr = elementSetBits;
		}
	}
	cout<<ans<<endl;
    // Logic section
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