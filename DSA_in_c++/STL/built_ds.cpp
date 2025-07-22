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
struct  bag
{
	int cur_sum = 0;
	cur_max = INT_MIN;
	void insert(int x)
	{
		cur_sum +=x;
		cur_max = max(cur_max,x);
	}
	int sum()
	{
		return cur_sum;
	}
	int getMax()
	{
		return cur_max;
	}
};
void solve() {
    // Input section
    

    // Logic section
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