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
int arr[1010];
int dp[1010];
int cnt[1010];
int rec(int i)
{
	// prunging 
	if(i<0) return 0;
	// base case

	// cache check
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	// Calculate / Transition
	dp[i] = 1;
    cnt[i] = 1;
    for(int j=0;j<i;j++){
        if(arr[j] < arr[i]){
            int val = 1 + rec(j);
            if(dp[i] < val){
                dp[i] = val;
                cnt[i] = cnt[j];
            }
            else if(val == dp[i]){
                cnt[i] += cnt[j];
                cnt[i] %= MOD;
            }
           
        }
    }
    
	// save and return
	return dp[i];
}


void solve() {
    // Input section
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
    // Logic section
     for(int i = n-1; i >=0; i--){
         ll last = rec(i);
     }

   ll lis = *max_element(dp,dp+n);
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(lis == dp[i]){
             ans += cnt[i];
             ans %= MOD;
        }
    }
    cout << ans << endl;
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