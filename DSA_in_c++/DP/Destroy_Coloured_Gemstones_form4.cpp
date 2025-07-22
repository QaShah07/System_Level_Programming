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
int arr[110];
// form 4 for pallindrome check
int dp1[110][110];
int rec(int l, int r)
{
	// pruning 
	// base case
	if(l>=r) return 1;
	// cache check
	if(dp1[l][r]!=-1)
	{
		return dp1[l][r];
	}
	// Compute/Transition
	// int ans = 0;
	// if(r]) ans = 1;
	// save and return
	return dp1[l][r]=rec(l+1,r-1)&&arr[l]==arr[r];
}
// form 2 for minimum break
int dp2[110][110];
int rec2(int l,int r)
{
	// pruning
	// if(i==0) return -1;
	// base case
	if(l>=r) return 1;
	if(rec(l,r)) return 1;

	// cache check
	if(dp2[l][r]!=-1)
	{
		return dp2[l][r];
	}
	// Compute/Transition
	int ans = 1e9;
	if(arr[l] == arr[r]) ans = min(ans, rec2(l+1,r-1));
	for(int mid = l;mid<r;mid++)
	{
		ans = min(ans,rec2(l,mid)+rec2(mid+1,r));
	}
	// save and return 
	return dp2[l][r]=ans; 
}

void solve() {
    // Input section
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	cout<<rec2(0,n-1)<<endl;
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