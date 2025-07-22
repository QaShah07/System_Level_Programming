// #include <bits/stdc++.h>
// bits/stdc++.h
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>

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
// in dp jo chij change nhi ho rha h use global rakh sakte ho
int n;
int W;
int w[3003];
int v [3003];
int dp[3003][30003];
int rec(int i, int wleft)
{
	// pruning
	// base case
	if(i==n)
	{
		return 0;
	}
	// chache check
	if(dp[i][wleft]!=-1)
	{
		return dp[i][wleft];
	}
	// transition
	int ans = rec(i+1,wleft);
	if(w[i]<=wleft)
	{
		ans = max(ans, rec(i + 1, wleft - w[i]) + v[i]);
}
	// save and return
	dp[i][wleft] = ans;
	return dp[i][wleft];


}

void solve() {
    // Input section
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>w[i];
    }
    for(int j=0;j<n;j++)
    {
    	cin>>v[j];
    }
    cin>>W;
    // Logic section
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W);

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