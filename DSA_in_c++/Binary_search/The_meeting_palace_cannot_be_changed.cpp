#include<bits/stdc++.h>
using namespace std;
#define int long long 
using ld = long double;
// global variable
int n;
ld x[100100],v[100100];
const ld INF = 1e18;
// check function
int check(ld mid)
{
    ld inter_l = -INF, inter_r = INF;
    for(int i=0;i<n;i++)
    {
        inter_l = max(inter_l,x[i]-v[i]*mid);
        inter_r = min(inter_r,x[i]+v[i]*mid);
    }
    if(inter_l<=inter_r) return 1;
    else return 0;
}
// Binary search
void binarySearch()
{
    ld lo = 0, hi = 1e9, ans = 0;
    for(int i=0;i<80;i++)
    {
        ld mid = lo + (hi - lo) / 2;
        if(check(mid)==1)
        {
            ans = mid;
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}
void solve()
{
// input section 
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

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
