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
int queens[20];
// we are using LCCM framework
// check funtion
bool check(int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		int prow = i;
		int pcol = queens[i];
		if(pcol == col || abs(pcol - col) == abs(prow - row))
		{
			return false;
		}
	}
	return true;
}

// Recursive function
int rec(int level) // level is basically row 
{
	// pruning
	// base case
	if(level==n)
	{
		return 1;
	}
	// calculate
	int ans = 0;
	for(int col = 0;col<n;col++)
	{
		if(check(level,col))
		{
			queens[level] = col;
			ans +=rec(level+1);
			queens[level] = -1;
		}
	}
	return ans;
}
void solve() {
    // Input section
	cin>>n;
	memset(queens,-1,sizeof(queens));

    // Logic section
    cout<<rec(0);
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