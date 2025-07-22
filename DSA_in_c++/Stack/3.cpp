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
// function for Next Smaller to Left
vi NSL(vi &arr,int n)
{
	vi ans;
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		if(!s.size()) ans.push_back(-1);
		else if(s.size()>0 && s.top()<arr[i]) ans.push_back(s.top());
		else if(s.size()>0 && s.top()>=arr[i])
		{
			while(s.size()>0 && s.top()>=arr[i])
			{
				s.pop();
			}
			if(!s.size()) ans.push_back(-1);
			else ans.push_back(s.top());
		}
		s.push(arr[i]);
	}
	return ans;
}

void solve() {
    // Input section
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }

    // Logic section
    vi ans = NSL(arr,n);
    for(auto it: ans)
    {
    	cout<<it<<" ";
    }
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