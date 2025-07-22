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
ll incremovableSubarrayCount(vector<int>& nums) {
	int n = nums.size();
	int i = n-1; // 0 to till i nums array is sorted
	for(int k=0;k<n-1;k++)
	{
		if(nums[k]>=nums[k+1])
		{
			i = k;
			break;
		}
	}
	int j = 0; // j+1 to end arr is sorted
	for(int k=n-1;k>0;k--)
	{
		if(nums[k]<=nums[k-1])
		{
			j = k-1;
			break;
		}
	}
	// Now come for ans
	ll cnt  = 0;
	for(int k=j;k<n;k++)
	{
		ll nxt = k+1<n ? nums[k+1] : 1e10;
		int r = min(k-1,i), l = 0;
		int ans = -1;
		while(l<=r)
		{
			int mid = (l+r)/2;
			if(nums[mid]>=nxt) r = mid-1;
			else
			{
				ans = max(ans,mid);
				l = mid+1;
			}
		}
		cnt += ans+2;
	}
	return cnt;

}
void solve() {
    // Input section
    int n;
    cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
    // Logic section
    cout<<incremovableSubarrayCount(nums);


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