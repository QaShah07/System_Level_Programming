#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, m, k;
int arr[200200];
int brr[200200];

int check(int mid)
{
    int towerPlanted = 0;
    int lastTowerPlanted = -1e18;
    for(int i = 0; i < n; i++)
    {
        if(lastTowerPlanted >= arr[i])
            continue;

        int lo = arr[i] - mid;
        int hi = arr[i] + mid;

        auto itr = upper_bound(brr, brr + m, hi);
        if(itr == brr)
            return 0;

        itr--;
        if(lo <= *itr)
        {
            towerPlanted++;
            lastTowerPlanted = (*itr) + mid;
        }
        else
        {
            return 0;
        }
    }

    if(towerPlanted > k) return 0;
    else return 1;
}

void solve()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int j = 0; j < m; j++) cin >> brr[j];

    sort(arr, arr + n);
    sort(brr, brr + m);

    int lo = 0, hi = 2e9, ans = -1;
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
