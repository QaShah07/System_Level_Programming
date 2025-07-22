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
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    // Logic section
    sort(arr.begin(),arr.end());
    do {
    	for(auto x: arr)
    	{
    		cout<<x<<" ";
    	}
    	cout<<"\n";
    }while(next_permutation(arr.begin(),arr.end()));
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