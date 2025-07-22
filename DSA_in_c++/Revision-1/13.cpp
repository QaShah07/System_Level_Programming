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
bool checkPallindrome(int n)
{
	int reverse = 0;
	int temp = n;
	while(temp != 0)
	{
		reverse = (reverse*10)+(temp%10);
		temp /= 10;
	}
	return (reverse==n);
}
void solve() {
    // Input section
    int n;
    cin>>n;


    // Logic section
    cout<<checkPallindrome(n)<<endl;

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