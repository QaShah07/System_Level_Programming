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
// compare funtion for double
bool comapare(vi &a, vi &b)
{
	double a1 = (1.0*a[0])/a[1];
	double b1 = (1.0*b[0])/b[1];
	return a1>b1;
}
// function for fractional Knapsack
double fractionalKnapsack(vi &val, vi& wt, int Capacity)
{
	int n = val.size();
	vvi items(n,vi(2));
	for(int i=0;i<n;i++)
	{
		items[i][0] = val[i];
		items[i][1] = wt[i];
	}
	sort(items.begin(),items.end(),comapare);
	double res = 0;
	int current_capacity = Capacity;
	for(int i=0;i<n;i++)
	{
		if(items[i][1]<=current_capacity)
		{
			res +=items[i][0];
			current_capacity -=items[i][1];
		}
		// Handling fraction case
		else
		{
			res += (1.0*items[i][0]/items[i][1])*current_capacity;
			break;
		}
	}
	return res;
}

void solve() {
    // Input section
    vi a = {60,100,120};
    vi b = {10,20,30};
    int Capacity = 50;

    // Logic section
    cout<<fractionalKnapsack(a,b,Capacity);
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