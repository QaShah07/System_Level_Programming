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
int arr[1001];
int dp[1001][1001];
// for getting sum
int getSum(int l, int r)
{ 
	return prefix[r]-((l==0)?0:prefix[l-1]);
}
// for prefix sum
int prefix[10001];
int rec(int l, int r)
{
	// pruning

	// base case
	if(l==r)
	{
		return 0;
	}
	// cache check
	if(dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	// Compute/Transition
	int ans = 1e9;
	for(int mid = l;mid<r;mid++)
	{
		ans = min(ans, rec(l, mid) + rec(mid+1, r) + (getSum(l, mid) % 100) * (getSum(mid+1, r) % 100));
	}
	// save and return
	return dp[l][r] = ans;
}


// // now for generate function
// void generate(int l, int r)
// {
// 	// base case 
// 	if(l==r)
// 	{
// 		return;
// 	}
// 	// now for generate the funtion
// 	for(int mid = l;mid<r;mid++)
// 	{
// 		if(rec(l,r)==rec(l,mid)+rec(mid+1,r)+(getSum(l,mid)%100)*(getSum(mid+1,r)%100))
// 		{
// 			generate(l,mid);
// 			getSum(mid+1,r);
// 			cout<<"Merge ("<<l<<", "<<mid") and ("<<mid+1<<" , "<<r<<endl;
// 		}
// 	}
// }
void solve() {
    // Input semidtion
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	if(i==0) prefix[i] = arr[i];
    	else prefix[i] = prefix[i-1]+arr[i];
    }

    // Logic section
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
    // generate(0,n-1);
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