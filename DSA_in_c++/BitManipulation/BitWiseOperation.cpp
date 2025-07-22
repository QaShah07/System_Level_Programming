#include <bits/stdc++.h>
using namespace std;

// Self use terminology
#define int long long
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
    int cnt[21];
    memset(cnt,0,sizeof(cnt));
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        for(int j=0;j<20;j++)
        {
            if(arr[i]&(1<<j))
            {
                cnt[j]++;
            }
        }
    }
    // Logic section
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int largepos = 0;
        for(int j=0;j<20;j++)
        {
            if(cnt[j])
            {
                largepos |=(1<<j);
                cnt[j]--;
            }
        }
        ans += largepos*largepos;
    }
    cout<<ans<<endl;

}

signed main() {
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