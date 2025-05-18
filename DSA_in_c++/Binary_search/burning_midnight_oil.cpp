#include<bits/stdc++.h>
using namespace std;
#define int long long 
// global variable
int n, m, k;
// check function
int check(int mid)
{
    int tot=0,i=0;
    while(true)
    {
        int power = pow(k,i);
        if(power>mid) break;
        tot +=mid/power;
        i++;
    }
    return tot>=n;
}
// Binary search
void binarySearch()
{
    int lo = 0, hi = n, ans = -1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(check(mid))
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
void solve()
{
// input section 
    cin>>n>>k;
    binarySearch();
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
