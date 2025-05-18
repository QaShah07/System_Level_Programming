#include <bits/stdc++.h>
using namespace std;
#define int long long 

// Ingredient counts per hamburger
int b = 0, s = 0, c = 0;

// Stock and prices
int nb, ns, nc;
int pb, ps, pc;
int money;

// Check if we can make `mid` hamburgers
bool check(int mid) {
    int cb = max(0LL, (mid * b - nb)) * pb;
    int cs = max(0LL, (mid * s - ns)) * ps;
    int cc = max(0LL, (mid * c - nc)) * pc;
    return (cb + cs + cc) <= money;
}

void binarySearch() {
    int lo = 0, hi = 1e13, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}

void solve() {
    string str;
    cin >> str;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> money;

    for (char ch : str) {
        if (ch == 'B') b++;
        else if (ch == 'S') s++;
        else if (ch == 'C') c++;
    }

    binarySearch();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
