#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, m, k;

int check(int mid)
{
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        cnt += min(mid/i,m);
    }
    if(cnt>=k) return 1;
    else return 0;
}

void solve()
{
    cin >> n >> m >> k;
    

    int lo = 0, hi = n*m, ans = 0;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(check(mid) == 1)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
